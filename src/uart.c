#include "stm32g0b1/uart.h"

#include "stm32g0b1/stm32g0b1.h"

#include <stdbool.h>
#include <string.h>

#ifndef UART_buf_len
#    define UART_buf_len (32)
#endif

static bool UART_rx_buf_is_empty(void);
static bool UART_rx_interrupt_detected(void);
static bool UART_tx_interrupt_detected(void);
static void UART_enable_interrupts(void);
static void UART_enable_uart(int32_t);
static void UART_reset_buffers(void);
static void UART_rx_isr(void);
static void UART_tx_isr(void);

static uint8_t volatile UART_tx_buf[UART_buf_len];
static int volatile UART_tx_buf_write = 0;
static int volatile UART_tx_buf_read  = 0;

static uint8_t volatile UART_rx_buf[UART_buf_len];
static int volatile UART_rx_buf_write = 0;
static int volatile UART_rx_buf_read  = 0;

USART_peripheral_registers_t volatile *UART_registers;

#define UART_index_next(i)                                                     \
    {                                                                          \
        int next = i + 1;                                                      \
        next %= UART_buf_len;                                                  \
        i = next;                                                              \
    }

void
UART_init(void volatile *uart_regs, int32_t clock_hz)
{
    UART_registers = uart_regs;
    UART_enable_uart(clock_hz);
    UART_reset_buffers();
    UART_enable_interrupts();
}

static void
UART_enable_uart(int32_t clock_hz)
{
    UART_registers->cr1.fifo_disabled.m0 = USART_cr1_m0_8_bits;
    UART_registers->cr1.fifo_disabled.m1 = USART_cr1_m1_8_bits;

    UART_registers->brr = (uint32_t)(clock_hz / (115200));

    UART_registers->cr2.stop = 0;

    UART_registers->cr1.fifo_disabled.re = 1;
    UART_registers->cr1.fifo_disabled.te = 1;
    UART_registers->cr1.fifo_disabled.ue = 1;
}

static void
UART_reset_buffers(void)
{
    UART_tx_buf_write = 0;
    UART_tx_buf_read  = 0;
    memset((void *)UART_tx_buf, 0, UART_buf_len);

    UART_rx_buf_write = 0;
    UART_rx_buf_read  = 0;
    memset((void *)UART_rx_buf, 0, UART_buf_len);
}

static void
UART_enable_interrupts(void)
{
    UART_registers->cr1.fifo_disabled.rxneie   = 1;
    NVIC_registers->IP.usart2_lpuart2.priority = 0;
    NVIC_registers->ISER.usart2_lpuart2        = 1;
}

int
UART_bytes_received(void)
{
    int bytes = UART_rx_buf_write - UART_rx_buf_read;
    bytes += UART_buf_len;
    bytes %= UART_buf_len;
    return bytes;
}

void
UART_buf_write(void const *data, int len)
{
    for (int i = 0; i < len; ++i) {
        UART_byte_write(((uint8_t *)data)[i]);
    }
}

void
UART_byte_write(uint8_t data)
{
    do {
        if (UART_tx_buf_write != UART_tx_buf_read) {
            break;
        }
    } while (UART_registers->cr1.fifo_disabled.txeie);
    UART_tx_buf[UART_tx_buf_write] = data;
    UART_index_next(UART_tx_buf_write);
    UART_registers->cr1.fifo_disabled.txeie = 1;
}

void
UART_byte_transmit(uint8_t data)
{
    while (0 == UART_registers->isr.fifo_disabled.tc) {
    }
    UART_registers->tdr = data;
}

uint8_t
UART_byte_read(void)
{
    if (UART_rx_buf_is_empty()) {
        return 0;
    }
    uint8_t const data = UART_rx_buf[UART_rx_buf_read];
    UART_index_next(UART_rx_buf_read);
    return data;
}

uint8_t
UART_byte_peak(void)
{
    if (UART_rx_buf_is_empty()) {
        return 0;
    }
    return UART_rx_buf[UART_rx_buf_read];
}

void
UART_buf_read_blocking(void *data, int len)
{
    for (int i = 0; i < len; ++i) {
        while (0 == UART_bytes_received()) {
        }
        ((uint8_t *)data)[i] = UART_byte_read();
    }
}

void
USART_IRQHandler(void)
{
    if (UART_tx_interrupt_detected()) {
        UART_tx_isr();
    }
    if (UART_rx_interrupt_detected()) {
        UART_rx_isr();
    }
}

static bool
UART_tx_interrupt_detected(void)
{
    if (0 == UART_registers->cr1.fifo_disabled.txeie) {
        return false;
    }
    if (0 == UART_registers->isr.fifo_disabled.txe) {
        return false;
    }
    return true;
}

static void
UART_tx_isr(void)
{

    if (UART_tx_buf_read == UART_tx_buf_write) {
        UART_registers->cr1.fifo_disabled.txeie = 0;
        return;
    }
    UART_registers->tdr = UART_tx_buf[UART_tx_buf_read];
    UART_index_next(UART_tx_buf_read);
}

static bool
UART_rx_interrupt_detected(void)
{
    if (0 == UART_registers->cr1.fifo_disabled.rxneie) {
        return false;
    }
    if (0 == UART_registers->isr.fifo_disabled.rxne) {
        return false;
    }
    return true;
}

static void
UART_rx_isr(void)
{
    UART_rx_buf[UART_rx_buf_write] = UART_registers->rdr;
    UART_index_next(UART_rx_buf_write);
    if (UART_rx_buf_read == UART_rx_buf_write) {
        // Overflow.  Dump oldest data.
        UART_index_next(UART_rx_buf_read);
    }
}

static bool
UART_rx_buf_is_empty(void)
{
    return UART_rx_buf_read == UART_rx_buf_write;
}

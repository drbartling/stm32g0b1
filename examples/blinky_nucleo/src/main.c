#include "stm32g0b1/stm32g0b1.h"

#include <stdio.h>
#include <string.h>

#define LED_RCC_ENABLE gpioa_en
#define LED_PORT STM_gpio_a
#define LED_PIN pin_5

#define TX_UART_DEBUG_RCC_ENABLE gpioa_en
#define TX_UART_DEBUG_PORT STM_gpio_a
#define TX_UART_DEBUG_PIN pin_2

#define RX_UART_DEBUG_RCC_ENABLE gpioa_en
#define RX_UART_DEBUG_PORT STM_gpio_a
#define RX_UART_DEBUG_PIN pin_3

#define set_pin_mode(name, mode)                                               \
    STM_RCC->iopenr.name##_RCC_ENABLE = 1;                                     \
    name##_PORT->moder.name##_PIN     = mode

static void chip_init(void);
static void rcc_init(void);
static void gpio_init(void);
static void uart_init(void);
static void millis_init(void);
static void millis_handler(void);
static void delay(int64_t);

static int32_t volatile clock_hz = 12 * 1000 * 1000;
static int64_t volatile millis   = 0;

// Application

int
main(void)
{
    chip_init();

    while (1) {
        int64_t period_ms = 1000;
        int64_t delta     = millis % period_ms;
        period_ms -= delta;
        delay(period_ms / 2);
        LED_PORT->bsrr.LED_PIN = 1;
        delay(period_ms / 2);
        LED_PORT->brr.LED_PIN = 1;
        char    text[100]     = {0};
        int64_t ms            = millis;
        sprintf(text, "Hello, World! %d\r\n", (int)ms);
        UART_buf_write(text, (int)strlen(text));
    }
    return 0;
}

static void
chip_init(void)
{
    FLASH_unlock();
    rcc_init();
    gpio_init();
    uart_init();
    millis_init();
}

static void
rcc_init(void)
{
    STM_RCC->apbenr1.pwren    = 1;
    STM_RCC->apbenr2.syscfgen = 1;
    STM_RCC->apbenr2.adcen    = 1;

    STM_RCC->cr.pllon = 0;
    int volatile i    = 0;
    while (STM_RCC->cr.pllon) {
        if (i++ > 20000) {
            return;
        }
    }
    STM_RCC->cr.hsion = 1;
    while (0 == STM_RCC->cr.hsirdy) {
    }
    STM_RCC->pllcfgr.pllsrc = 0b10;      // HSI16 (16MHz)
    STM_RCC->pllcfgr.pllm   = 0b000;     // Divide pllsrc by 1 (16MHz)
    STM_RCC->pllcfgr.plln   = 0b0001000; // Multiply pllm by 8 (128MHz)
    STM_RCC->pllcfgr.pllpen = 0;
    STM_RCC->pllcfgr.pllp   = 0b00001; // Divide pllm by 2 (64MHz)
    STM_RCC->pllcfgr.pllqen = 0;
    STM_RCC->pllcfgr.pllq   = 0b00001; // Divide pllm by 2 (64MHz)
    STM_RCC->pllcfgr.pllren = 0;
    STM_RCC->pllcfgr.pllr   = 0b00001; // Divide pllm by 2 (64MHz)
    STM_RCC->cr.pllon       = 1;
    clock_hz                = 64 * 1000 * 1000;
    while (0 == STM_RCC->cr.pllrdy) {
    }
    STM_RCC->pllcfgr.pllren = 1;
    // Flash latency is WS2 (p. 72 of rm0444)
    STM_FLASH->acr.latency = 0b010; // two wait states
    STM_FLASH->acr.prften  = 1;
    while (0b010 != STM_FLASH->acr.latency) {
    }
    STM_RCC->cfgr.sw   = RCC_sw_pllrclk;
    STM_RCC->cfgr.hpre = 0;
    STM_RCC->cfgr.ppre = 0;
}

static void
gpio_init(void)
{
    set_pin_mode(LED, stm_gpio_mode_output);
}

static void
uart_init(void)
{
    set_pin_mode(TX_UART_DEBUG, stm_gpio_mode_alternate_function);
    TX_UART_DEBUG_PORT->afr.TX_UART_DEBUG_PIN = 1; // DS13560 rev 4 p. 57

    set_pin_mode(RX_UART_DEBUG, stm_gpio_mode_alternate_function);
    RX_UART_DEBUG_PORT->afr.RX_UART_DEBUG_PIN = 1; // DS13560 rev 4 p. 57

    STM_RCC->apbenr1.usart2en = 1;
    UART_init(STM_USART2, clock_hz);
}

static void
millis_init(void)
{
    // rm0444 r5 p. 629
    STM_RCC->apbenr1.tim2en                      = 1;
    GPTIM_peripheral_registers_t volatile *timer = STM_TIM2;

    uint32_t period_ms      = 1;
    uint32_t cycles_per_ms  = (uint32_t)clock_hz / 1000;
    uint32_t counter_cycles = cycles_per_ms * period_ms;

    timer->cr1.cen  = 0;
    timer->sr.uif   = 0;
    timer->dier.uie = 0;

    millis          = 0;
    timer->arr.bits = counter_cycles - 1;

    timer->dier.uie                  = 1;
    timer->dier.tie                  = 1;
    NVIC_registers->IP.tim2.priority = 0;
    NVIC_registers->ISER.tim2        = 1;

    timer->cr1.cen = 1;
}

static void
millis_handler(void)
{
    STM_TIM2->sr.uif = 0;
    millis++;
}

static void
delay(int64_t delay_ms)
{
    int64_t start_ms = millis;
    while (millis - start_ms < delay_ms) {
    }
}

// Environment setup
_Noreturn static void reset_handler(void);
static void initialize_global_data(uint32_t *flash_begin, uint32_t *data_begin,
                                   uint32_t *data_end);

_Noreturn static void nmi_handler(void);

_Noreturn static void hard_fault_handler(void);

extern uint32_t LINKER_load_data;
extern uint32_t LINKER_start_data;
extern uint32_t LINKER_end_data;

static void
reset_handler(void)
{
    initialize_global_data(&LINKER_load_data, &LINKER_start_data,
                           &LINKER_end_data);
    main();

    while (1) {
    }
}

static void
initialize_global_data(uint32_t *flash_begin, uint32_t *data_begin,
                       uint32_t *data_end)
{
    uint32_t *p = data_begin;
    while (p < data_end) {
        *p++ = *flash_begin++;
    }
}

_Noreturn static void
nmi_handler(void)
{
    while (1) {
    }
}

_Noreturn static void
hard_fault_handler(void)
{
    while (1) {
    }
}

interrupt_vector_table_t vector_table __attribute__((section(".isr_vector")))
__attribute__((used)) = {
    // End of ram is initial stack pointer
    .sram_end           = (void *)STSRAM_END,
    .reset_handler      = (void *)reset_handler,
    .nmi_handler        = (void *)nmi_handler,
    .hard_fault_handler = (void *)hard_fault_handler,
    .usart_2_lpuart_2   = (void *)USART_IRQHandler,
    .tim2_handler       = (void *)millis_handler,
};

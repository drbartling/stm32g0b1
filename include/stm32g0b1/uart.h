#ifndef UART_H
#define UART_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief      Initializes the UART peripheral
 *
 * @param      uart_regs  Pointer to the UART registers
 */
void UART_init(volatile void *uart_regs);

/**
 * @brief      Returns the number of bytes received and waiting to be read
 *
 * @return     Number of bytes received into UART FIFO
 */
int UART_bytes_received(void);

/**
 * @brief      Writes one byte out on UART
 *
 * @param[in]  data  Byte to write out on UART
 */
void UART_byte_write(uint8_t data);

/**
 * @brief      Writes one byte out on UART
 *
 * @param[in]  data  Byte to write out on UART
 */
void UART_byte_transmit(uint8_t data);

/**
 * @brief      Dequeues and returns one byte from the UART FIFO
 *
 * @return     Oldest byte in the UART FIFO
 */
uint8_t UART_byte_read(void);

/**
 * @brief      Returns value of oldest byte in UART FIFO, leaves FIFO unaltered
 *
 * @return     Oldest byte in the UART FIFO
 */
uint8_t UART_byte_peak(void);

/**
 * @brief      Copies a buffer into the UART FIFO.
 *
 * @note       Copying more data into the FIFO than the size of the FIFO will
 *             block until the FIFO clears.
 *
 * @param      data  The data
 * @param[in]  len   The length
 */
void UART_buf_write(void const *data, int len);

/**
 * @brief      Reads data from the UART FIFO.
 *
 *             Will block until the specified bytes are received.  Use
 *             UART_bytes_received() to determine if data is ready in order to
 *             avoid blocking.
 *
 * @see        UART_bytes_received
 *
 * @param      data  The data
 * @param[in]  len   The length
 */
void UART_buf_read_blocking(void *data, int len);

/**
 * @brief      Uart interrupt handler.
 *
 *             Do not call directly.  Assign in interrupt vector table.
 */
void USART3_4_LPUART1_IRQHandler(void);

#ifdef __cplusplus
}
#endif
#endif /* end of include guard: UART_H */

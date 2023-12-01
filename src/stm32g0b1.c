#include "stm32g0b1/stm32g0b1.h"

// rm0444 r5 pp. 63-64
// pm0223 r6 p. 81
SYSTICK_Type volatile *SYSTICK_registers = (void *)(0xE000E010UL);
NVIC_Type volatile    *NVIC_registers    = (void *)(0xE000E100UL);
SCB_Type volatile     *SCB_registers     = (void *)(0xE000ED00UL);

// rm0444 r5 pp. 63-64
TIM2_peripheral_registers_t volatile    *STM_TIM2    = (void *)(0x40000000UL);
TIM2_peripheral_registers_t volatile    *STM_TIM3    = (void *)(0x40000400UL);
TIM2_peripheral_registers_t volatile    *STM_TIM4    = (void *)(0x40000800UL);
TIM6_peripheral_registers_t volatile    *STM_TIM6    = (void *)(0x40001000UL);
TIM6_peripheral_registers_t volatile    *STM_TIM7    = (void *)(0x40001400UL);
uint32_t volatile                       *STM_TIM14   = (void *)(0x40002000UL);
uint32_t volatile                       *STM_RTC     = (void *)(0x40002800UL);
uint32_t volatile                       *STM_WWDG    = (void *)(0x40002C00UL);
uint32_t volatile                       *STM_IWDG    = (void *)(0x40003000UL);
SPI_peripheral_registers_t volatile     *STM_SPI2    = (void *)(0x40003800UL);
SPI_peripheral_registers_t volatile     *STM_SPI3    = (void *)(0x40003C00UL);
USART_peripheral_registers_t volatile   *STM_USART2  = (void *)(0x40004400UL);
USART_peripheral_registers_t volatile   *STM_USART3  = (void *)(0x40004800UL);
USART_peripheral_registers_t volatile   *STM_USART4  = (void *)(0x40004C00UL);
USART_peripheral_registers_t volatile   *STM_USART5  = (void *)(0x40005000UL);
uint32_t volatile                       *STM_I2C1    = (void *)(0x40005400UL);
uint32_t volatile                       *STM_I2C2    = (void *)(0x40005800UL);
uint32_t volatile                       *STM_USB     = (void *)(0x40005C00UL);
uint32_t volatile                       *STM_FDCAN1  = (void *)(0x40006400UL);
uint32_t volatile                       *STM_FDCAN2  = (void *)(0x40006800UL);
uint32_t volatile                       *STM_CRS     = (void *)(0x40006C00UL);
uint32_t volatile                       *STM_PWR     = (void *)(0x40007000UL);
uint32_t volatile                       *STM_DAC     = (void *)(0x40007400UL);
uint32_t volatile                       *STM_CEC     = (void *)(0x40007800UL);
LPTIM1_peripheral_registers_t volatile  *STM_LPTIM1  = (void *)(0x40007C00UL);
USART_peripheral_registers_t volatile   *STM_LPUART1 = (void *)(0x40008000UL);
LPTIM1_peripheral_registers_t volatile  *STM_LPTIM2  = (void *)(0x40009400UL);
uint32_t volatile                       *STM_UCPD1   = (void *)(0x4000A000UL);
uint32_t volatile                       *STM_UCPD2   = (void *)(0x4000A400UL);
uint32_t volatile                       *STM_TAMP    = (void *)(0x4000B000UL);
uint32_t volatile                       *STM_SYSCFG  = (void *)(0x40010000UL);
VREFBUF_peripheral_registers_t volatile *STM_VREFBUF = (void *)(0x40010030UL);
uint32_t volatile                       *STM_COMP1   = (void *)(0x40010200UL);
uint32_t volatile                       *STM_COMP2   = (void *)(0x40010204UL);
ADC_peripheral_registers_t volatile     *STM_ADC1    = (void *)(0x40012400UL);
TIM1_peripheral_registers_t volatile    *STM_TIM1    = (void *)(0x40012C00UL);
SPI_peripheral_registers_t volatile     *STM_SPI1    = (void *)(0x40013000UL);
USART_peripheral_registers_t volatile   *STM_USART1  = (void *)(0x40013800UL);
uint32_t volatile                       *STM_TIM15   = (void *)(0x40014000UL);
uint32_t volatile                       *STM_TIM16   = (void *)(0x40014400UL);
uint32_t volatile                       *STM_TIM17   = (void *)(0x40014800UL);
uint32_t volatile                       *STM_DBG     = (void *)(0x40015800UL);
DMA1_peripheral_registers_t volatile    *DMA1        = (void *)(0x40020000UL);
DMA1_peripheral_registers_t volatile    *DMA2        = (void *)(0x40020400UL);
DMAMUX_peripheral_registers_t volatile  *DMAMUX      = (void *)(0x40020800UL);
RCC_peripheral_registers_t volatile     *STM_RCC     = (void *)(0x40021000UL);
uint32_t volatile                       *STM_EXTI    = (void *)(0x40021800UL);
FLASH_registers_t volatile              *STM_FLASH   = (void *)(0x40022000UL);
uint32_t volatile                       *STM_CRC     = (void *)(0x40023000UL);
uint32_t volatile                       *STM_RNG     = (void *)(0x40025000UL);
uint32_t volatile                       *STM_AES     = (void *)(0x40026000UL);

// rm0444 r5 pp. 63-64
stm_gpio_port_t volatile *STM_gpio_a = (void *)(0x50000000UL);
stm_gpio_port_t volatile *STM_gpio_b = (void *)(0x50000400UL);
stm_gpio_port_t volatile *STM_gpio_c = (void *)(0x50000800UL);
stm_gpio_port_t volatile *STM_gpio_d = (void *)(0x50000C00UL);
stm_gpio_port_t volatile *STM_gpio_f = (void *)(0x50001400UL);

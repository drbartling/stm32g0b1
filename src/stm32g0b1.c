#include "stm32g0b1.h"

// rm0444 r5 pp. 63-64
// pm0223 r6 p. 81
volatile uint32_t  *SYSTICK_registers = (void *)(0xE000E010UL);
volatile NVIC_Type *NVIC_registers    = (void *)(0xE000E100UL);
volatile SCB_Type  *SCB_registers     = (void *)(0xE000ED00UL);

// rm0444 r5 pp. 63-64
volatile GPTIM_peripheral_registers_t   *STM_TIM2    = (void *)(0x40000000UL);
volatile GPTIM_peripheral_registers_t   *STM_TIM3    = (void *)(0x40000400UL);
volatile GPTIM_peripheral_registers_t   *STM_TIM4    = (void *)(0x40000800UL);
volatile uint32_t                       *STM_TIM6    = (void *)(0x40001000UL);
volatile uint32_t                       *STM_TIM7    = (void *)(0x40001400UL);
volatile uint32_t                       *STM_TIM14   = (void *)(0x40002000UL);
volatile uint32_t                       *STM_RTC     = (void *)(0x40002800UL);
volatile uint32_t                       *STM_WWDG    = (void *)(0x40002C00UL);
volatile uint32_t                       *STM_IWDG    = (void *)(0x40003000UL);
volatile SPI_peripheral_registers_t     *STM_SPI2    = (void *)(0x40003800UL);
volatile SPI_peripheral_registers_t     *STM_SPI3    = (void *)(0x40003C00UL);
volatile USART_peripheral_registers_t   *STM_USART2  = (void *)(0x40004400UL);
volatile USART_peripheral_registers_t   *STM_USART3  = (void *)(0x40004800UL);
volatile USART_peripheral_registers_t   *STM_USART4  = (void *)(0x40004C00UL);
volatile USART_peripheral_registers_t   *STM_USART5  = (void *)(0x40005000UL);
volatile uint32_t                       *STM_I2C1    = (void *)(0x40005400UL);
volatile uint32_t                       *STM_I2C2    = (void *)(0x40005800UL);
volatile uint32_t                       *STM_USB     = (void *)(0x40005C00UL);
volatile uint32_t                       *STM_FDCAN1  = (void *)(0x40006400UL);
volatile uint32_t                       *STM_FDCAN2  = (void *)(0x40006800UL);
volatile uint32_t                       *STM_CRS     = (void *)(0x40006C00UL);
volatile uint32_t                       *STM_PWR     = (void *)(0x40007000UL);
volatile uint32_t                       *STM_DAC     = (void *)(0x40007400UL);
volatile uint32_t                       *STM_CEC     = (void *)(0x40007800UL);
volatile uint32_t                       *STM_LPTIM1  = (void *)(0x40007C00UL);
volatile USART_peripheral_registers_t   *STM_LPUART1 = (void *)(0x40008000UL);
volatile uint32_t                       *STM_LPTIM2  = (void *)(0x40009400UL);
volatile uint32_t                       *STM_UCPD1   = (void *)(0x4000A000UL);
volatile uint32_t                       *STM_UCPD2   = (void *)(0x4000A400UL);
volatile uint32_t                       *STM_TAMP    = (void *)(0x4000B000UL);
volatile uint32_t                       *STM_SYSCFG  = (void *)(0x40010000UL);
volatile VREFBUF_peripheral_registers_t *STM_VREFBUF = (void *)(0x40010030UL);
volatile uint32_t                       *STM_COMP1   = (void *)(0x40010200UL);
volatile uint32_t                       *STM_COMP2   = (void *)(0x40010204UL);
volatile ADC_peripheral_registers_t     *STM_ADC1    = (void *)(0x40012400UL);
volatile uint32_t                       *STM_TIM1    = (void *)(0x40012C00UL);
volatile SPI_peripheral_registers_t     *STM_SPI1    = (void *)(0x40013000UL);
volatile USART_peripheral_registers_t   *STM_USART1  = (void *)(0x40013800UL);
volatile uint32_t                       *STM_TIM15   = (void *)(0x40014000UL);
volatile uint32_t                       *STM_TIM16   = (void *)(0x40014400UL);
volatile uint32_t                       *STM_TIM17   = (void *)(0x40014800UL);
volatile uint32_t                       *STM_DBG     = (void *)(0x40015800UL);
volatile RCC_peripheral_registers_t     *STM_RCC     = (void *)(0x40021000UL);
volatile uint32_t                       *STM_EXTI    = (void *)(0x40021800UL);
volatile FLASH_registers_t              *STM_FLASH   = (void *)(0x40022000UL);
volatile uint32_t                       *STM_CRC     = (void *)(0x40023000UL);
volatile uint32_t                       *STM_RNG     = (void *)(0x40025000UL);
volatile uint32_t                       *STM_AES     = (void *)(0x40026000UL);

// rm0444 r5 pp. 63-64
volatile stm_gpio_port_t *STM_gpio_a = (void *)(0x50000000UL);
volatile stm_gpio_port_t *STM_gpio_b = (void *)(0x50000400UL);
volatile stm_gpio_port_t *STM_gpio_c = (void *)(0x50000800UL);
volatile stm_gpio_port_t *STM_gpio_d = (void *)(0x50000C00UL);
volatile stm_gpio_port_t *STM_gpio_f = (void *)(0x50001400UL);

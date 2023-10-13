#ifndef STM32G0B1_H_
#define STM32G0B1_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g0b1/stm_adc.h"
#include "stm32g0b1/stm_basic_timer.h"
#include "stm32g0b1/stm_dma1.h"
#include "stm32g0b1/stm_dmamux.h"
#include "stm32g0b1/stm_flash.h"
#include "stm32g0b1/stm_gp_timer.h"
#include "stm32g0b1/stm_gpio.h"
#include "stm32g0b1/stm_nvic.h"
#include "stm32g0b1/stm_rcc.h"
#include "stm32g0b1/stm_scb.h"
#include "stm32g0b1/stm_spi.h"
#include "stm32g0b1/stm_timer1.h"
#include "stm32g0b1/stm_usart.h"
#include "stm32g0b1/stm_vrefbuf.h"
#include "stm32g0b1/uart.h"

#include <stdint.h>

#define STFLASH_BANK1_START 0x08000000
#define STFLASH_BANK1_SIZE (128 * 1024)
#define STFLASH_BANK1_END (STFLASH_BANK1_START + STFLASH_BANK1_SIZE)
#define STFLASH_BANK1_START_PAGE 0
#define STFLASH_BANK1_PAGES 128
#define STFLASH_BANK1_END_PAGE (STFLASH_BANK1_START_PAGE + STFLASH_BANK1_PAGES)

#define STFLASH_BANK2_START (STFLASH_BANK1_START + STFLASH_BANK1_SIZE)
#define STFLASH_BANK2_SIZE (STFLASH_BANK1_SIZE)
#define STFLASH_BANK2_END (STFLASH_BANK2_START + STFLASH_BANK2_SIZE)
#define STFLASH_BANK2_START_PAGE 256
#define STFLASH_BANK2_PAGES STFLASH_BANK1_PAGES
#define STFLASH_BANK2_END_PAGE (STFLASH_BANK2_START_PAGE + STFLASH_BANK2_PAGES)

#define STFLASH_PAGE_SIZE (2 * 1024)

#define STSRAM_BASE (0x20000000)
#define STSRAM_SIZE (144 * 1024)
#define STSRAM_END (STSRAM_BASE + STSRAM_SIZE)

extern volatile NVIC_Type *NVIC_registers;
extern volatile SCB_Type  *SCB_registers;

extern volatile RCC_peripheral_registers_t *STM_RCC;
extern volatile FLASH_registers_t          *STM_FLASH;

extern volatile SPI_peripheral_registers_t *STM_SPI1;
extern volatile SPI_peripheral_registers_t *STM_SPI2;
extern volatile SPI_peripheral_registers_t *STM_SPI3;

extern volatile USART_peripheral_registers_t *STM_USART1;
extern volatile USART_peripheral_registers_t *STM_USART2;
extern volatile USART_peripheral_registers_t *STM_USART3;
extern volatile USART_peripheral_registers_t *STM_USART4;
extern volatile USART_peripheral_registers_t *STM_USART5;
extern volatile USART_peripheral_registers_t *STM_LPUART1;

extern volatile stm_gpio_port_t *STM_gpio_a;
extern volatile stm_gpio_port_t *STM_gpio_b;
extern volatile stm_gpio_port_t *STM_gpio_c;
extern volatile stm_gpio_port_t *STM_gpio_d;
extern volatile stm_gpio_port_t *STM_gpio_f;

extern volatile TIM2_peripheral_registers_t    *STM_TIM2;
extern volatile TIM2_peripheral_registers_t    *STM_TIM3;
extern volatile TIM2_peripheral_registers_t    *STM_TIM4;
extern volatile TIM6_peripheral_registers_t    *STM_TIM6;
extern volatile TIM6_peripheral_registers_t    *STM_TIM7;
extern volatile uint32_t                       *STM_TIM14;
extern volatile uint32_t                       *STM_RTC;
extern volatile uint32_t                       *STM_WWDG;
extern volatile uint32_t                       *STM_IWDG;
extern volatile uint32_t                       *STM_I2C1;
extern volatile uint32_t                       *STM_I2C2;
extern volatile uint32_t                       *STM_USB;
extern volatile uint32_t                       *STM_FDCAN1;
extern volatile uint32_t                       *STM_FDCAN2;
extern volatile uint32_t                       *STM_CRS;
extern volatile uint32_t                       *STM_PWR;
extern volatile uint32_t                       *STM_DAC;
extern volatile uint32_t                       *STM_CEC;
extern volatile uint32_t                       *STM_LPTIM1;
extern volatile uint32_t                       *STM_LPTIM2;
extern volatile uint32_t                       *STM_UCPD1;
extern volatile uint32_t                       *STM_UCPD2;
extern volatile uint32_t                       *STM_TAMP;
extern volatile uint32_t                       *STM_SYSCFG;
extern volatile VREFBUF_peripheral_registers_t *STM_VREFBUF;
extern volatile uint32_t                       *STM_COMP1;
extern volatile uint32_t                       *STM_COMP2;
extern volatile ADC_peripheral_registers_t     *STM_ADC1;
extern volatile TIM1_peripheral_registers_t    *STM_TIM1;
extern volatile uint32_t                       *STM_TIM15;
extern volatile uint32_t                       *STM_TIM16;
extern volatile uint32_t                       *STM_TIM17;
extern volatile uint32_t                       *STM_DBG;
extern volatile DMA1_peripheral_registers_t    *STM_DMA1;
extern volatile DMA1_peripheral_registers_t    *STM_DMA2;
extern volatile DMAMUX_peripheral_registers_t  *STM_DMAMUX;
extern volatile uint32_t                       *STM_EXTI;
extern volatile uint32_t                       *STM_CRC;
extern volatile uint32_t                       *STM_RNG;
extern volatile uint32_t                       *STM_AES;

#ifdef __cplusplus
}
#endif
#endif // STM32G0B1_H_

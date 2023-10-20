#ifndef STM_NVIC_H_
#define STM_NVIC_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef enum {
    NonMaskableInt_IRQn = -14, ///< 2 Non Maskable Interrupt
    HardFault_IRQn      = -13, ///< 3 Cortex-M Hard Fault Interrupt
    SVC_IRQn            = -5,  ///< 11 Cortex-M SV Call Interrupt
    PendSV_IRQn         = -2,  ///< 14 Cortex-M Pend SV Interrupt
    SysTick_IRQn        = -1,  ///< 15 Cortex-M System Tick Interrupt

    WWDG_IRQn       = 0,      ///< Window WatchDog Interrupt
    PVD_VDDIO2_IRQn = 1,      ///< PVD through EXTI line 16, PVM (monit. VDDIO2)
                              ///< through EXTI line 34
    RTC_TAMP_IRQn        = 2, ///< RTC interrupt through the EXTI line 19 & 21
    FLASH_IRQn           = 3, ///< FLASH global Interrupt
    RCC_CRS_IRQn         = 4, ///< RCC and CRS global Interrupt
    EXTI0_1_IRQn         = 5, ///< EXTI 0 and 1 Interrupts
    EXTI2_3_IRQn         = 6, ///< EXTI Line 2 and 3 Interrupts
    EXTI4_15_IRQn        = 7, ///< EXTI Line 4 to 15 Interrupts
    USB_UCPD1_2_IRQn     = 8, ///< USB, UCPD1 and UCPD2 global Interrupt
    DMA1_Channel1_IRQn   = 9, ///< DMA1 Channel 1 Interrupt
    DMA1_Channel2_3_IRQn = 10, ///< DMA1 Channel 2 and Channel 3 Interrupts
    DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn =
        11, ///< DMA1 Ch4 to Ch7, DMA2 Ch1 to Ch5 and DMAMUX1 Overrun Interrupts
    ADC1_COMP_IRQn = 12, ///< ADC1, COMP1,COMP2, COMP3 Interrupts (combined with
                         ///< EXTI 17 & 18)
    TIM1_BRK_UP_TRG_COM_IRQn = 13, ///< TIM1 Break, Update, Trigger and
                                   ///< Commutation Interrupts
    TIM1_CC_IRQn         = 14,     ///< TIM1 Capture Compare Interrupt
    TIM2_IRQn            = 15,     ///< TIM2 Interrupt
    TIM3_TIM4_IRQn       = 16,     ///< TIM3, TIM4 global Interrupt
    TIM6_DAC_LPTIM1_IRQn = 17,     ///< TIM6, DAC and LPTIM1 global Interrupts
    TIM7_LPTIM2_IRQn     = 18,     ///< TIM7 and LPTIM2 global Interrupt
    TIM14_IRQn           = 19,     ///< TIM14 global Interrupt
    TIM15_IRQn           = 20,     ///< TIM15 global Interrupt
    TIM16_FDCAN_IT0_IRQn = 21, ///< TIM16, FDCAN1_IT0 and FDCAN2_IT0 Interrupt
    TIM17_FDCAN_IT1_IRQn = 22, ///< TIM17, FDCAN1_IT1 and FDCAN2_IT1 Interrupt
    I2C1_IRQn            = 23, ///< I2C1 Interrupt  (combined with EXTI 23)
    I2C2_3_IRQn = 24, ///< I2C2, I2C3 Interrupt (combined with EXTI 24 and EXTI
                      ///< 22)
    SPI1_IRQn                 = 25, ///< SPI1/I2S1 Interrupt
    SPI2_3_IRQn               = 26, ///< SPI2/I2S2, SPI3/I2S3 Interrupt
    USART1_IRQn               = 27, ///< USART1 Interrupt
    USART2_LPUART2_IRQn       = 28, ///< USART2 + LPUART2 Interrupt
    USART3_4_5_6_LPUART1_IRQn = 29, ///< USART3, USART4, USART5, USART6, LPUART1
                                    ///< globlal Interrupts (combined with EXTI
                                    ///< 28)
    CEC_IRQn = 30,                  ///< CEC Interrupt(combined with EXTI 27)
} IRQn_Type;

typedef union {
    struct {
        uint32_t wwdg : 1;
        uint32_t pvd_vddio2 : 1;
        uint32_t rtc_tamp : 1;
        uint32_t flash : 1;
        uint32_t rcc_crs : 1;
        uint32_t exti0_1 : 1;
        uint32_t exti2_3 : 1;
        uint32_t exti4_15 : 1;
        uint32_t usb_ucpd1_2 : 1;
        uint32_t dma1_channel1 : 1;
        uint32_t dma1_channel2_3 : 1;
        uint32_t dma1_ch4_7_dma2_ch1_5_dmamux1_ovr : 1;
        uint32_t adc1_comp : 1;
        uint32_t tim1_brk_up_trg_com : 1;
        uint32_t tim1_cc : 1;
        uint32_t tim2 : 1;
        uint32_t tim3_tim4 : 1;
        uint32_t tim6_dac_lptim1 : 1;
        uint32_t tim7_lptim2 : 1;
        uint32_t tim14 : 1;
        uint32_t tim15 : 1;
        uint32_t tim16_fdcan_it0 : 1;
        uint32_t tim17_fdcan_it1 : 1;
        uint32_t i2c1 : 1;
        uint32_t i2c2_3 : 1;
        uint32_t spi1 : 1;
        uint32_t spi2_3 : 1;
        uint32_t usart1 : 1;
        uint32_t usart2_lpuart2 : 1;
        uint32_t usart3_4_5_6_lpuart1 : 1;
        uint32_t cec : 1;
        uint32_t reserved : 1;
    };
    uint32_t bits;
} NVIC_iser_registers_t;

typedef union {
    struct {

        uint8_t reserved_0 : 6;
        uint8_t priority : 2;
    };
    uint8_t bits;
} NVIC_isr_priority_t;
STATIC_ASSERT_TYPE_SIZE(NVIC_isr_priority_t, sizeof(uint8_t));

typedef struct {
    NVIC_isr_priority_t wwdg;
    NVIC_isr_priority_t pvd_vddio2;
    NVIC_isr_priority_t rtc_tamp;
    NVIC_isr_priority_t flash;
    NVIC_isr_priority_t rcc_crs;
    NVIC_isr_priority_t exti0_1;
    NVIC_isr_priority_t exti2_3;
    NVIC_isr_priority_t exti4_15;
    NVIC_isr_priority_t usb_ucpd1_2;
    NVIC_isr_priority_t dma1_channel1;
    NVIC_isr_priority_t dma1_channel2_3;
    NVIC_isr_priority_t dma1_ch4_7_dma2_ch1_5_dmamux1_ovr;
    NVIC_isr_priority_t adc1_comp;
    NVIC_isr_priority_t tim1_brk_up_trg_com;
    NVIC_isr_priority_t tim1_cc;
    NVIC_isr_priority_t tim2;
    NVIC_isr_priority_t tim3_tim4;
    NVIC_isr_priority_t tim6_dac_lptim1;
    NVIC_isr_priority_t tim7_lptim2;
    NVIC_isr_priority_t tim14;
    NVIC_isr_priority_t tim15;
    NVIC_isr_priority_t tim16_fdcan_it0;
    NVIC_isr_priority_t tim17_fdcan_it1;
    NVIC_isr_priority_t i2c1;
    NVIC_isr_priority_t i2c2_3;
    NVIC_isr_priority_t spi1;
    NVIC_isr_priority_t spi2_3;
    NVIC_isr_priority_t usart1;
    NVIC_isr_priority_t usart2_lpuart2;
    NVIC_isr_priority_t usart3_4_5_6_lpuart1;
    NVIC_isr_priority_t cec;
    uint8_t             reserved[1];
} NVIC_ip_registers_t;
STATIC_ASSERT_TYPE_SIZE(NVIC_ip_registers_t, sizeof(uint32_t[8]));

// pm0223 rev 6 p. 82
typedef struct {
    volatile NVIC_iser_registers_t ISER;
    const uint32_t                 RESERVED0[31U];
    volatile uint32_t              ICER[1U];
    const uint32_t                 RSERVED1[31U];
    volatile uint32_t              ISPR[1U];
    const uint32_t                 RESERVED2[31U];
    volatile uint32_t              ICPR[1U];
    const uint32_t                 RESERVED3[31U];
    const uint32_t                 RESERVED4[64U];
    volatile NVIC_ip_registers_t   IP;
} NVIC_Type;
STATIC_ASSERT_MEMBER_OFFSET(NVIC_Type, ISER, 0x000);
STATIC_ASSERT_MEMBER_OFFSET(NVIC_Type, ICER, 0x080);
STATIC_ASSERT_MEMBER_OFFSET(NVIC_Type, ISPR, 0x100);
STATIC_ASSERT_MEMBER_OFFSET(NVIC_Type, ICPR, 0x180);
STATIC_ASSERT_MEMBER_OFFSET(NVIC_Type, IP, 0x300);

// rm0444 rev 5 pp. 315-316
typedef struct {
    void *sram_end;                // 0x0000
    void *reset_handler;           // 0x0004
    void *nmi_handler;             // 0x0008
    void *hard_fault_handler;      // 0x000c
    void *reserved_0x0010;         // 0x0010
    void *reserved_0x0014;         // 0x0014
    void *reserved_0x0018;         // 0x0018
    void *reserved_0x001C;         // 0x001C
    void *reserved_0x0020;         // 0x0020
    void *reserved_0x0024;         // 0x0024
    void *reserved_0x0028;         // 0x0028
    void *svc_handler;             // 0x002c
    void *reserved_0x0030;         // 0x0030
    void *reserved_0x0034;         // 0x0034
    void *pend_sv_handler;         // 0x0038
    void *sys_tick_handler;        // 0x003c
    void *wwdg_handler;            // 0x0040
    void *pvd_handler;             // 0x0044
    void *rtc_tamp_handler;        // 0x0048
    void *flash_handler;           // 0x004c
    void *rcc_crs_handler;         // 0x0050
    void *exi_0_1;                 // 0x0054
    void *exi_2_3;                 // 0x0058
    void *exi_4_15;                // 0x005c
    void *ucpd1_ucpd2_usb_handler; // 0x0060
    void *reserved_0x0064;         // 0x0064
    void *reserved_0x0068;         // 0x0068
    void *reserved_0x006C;         // 0x006C
    void *adc_comp_handler;        // 0x0070
    void *reserved_0x0074;         // 0x0074
    void *reserved_0x0078;         // 0x0078
    void *tim2_handler;            // 0x007C
    void *tim3_tim4_handler;       // 0x0080
    void *reserved_0x0084;         // 0x0084
    void *reserved_0x0088;         // 0x0088
    void *reserved_0x008C;         // 0x008C
    void *reserved_0x0090;         // 0x0090
    void *reserved_0x0094;         // 0x0094
    void *reserved_0x0098;         // 0x0098
    void *reserved_0x009C;         // 0x009C
    void *reserved_0x00A0;         // 0x00A0
    void *reserved_0x00A4;         // 0x00A4
    void *reserved_0x00A8;         // 0x00A8
    void *usart_1;                 // 0x00AC
    void *usart_2_lpuart_2;        // 0x00B0
    void *usart_3_4_5_6_lpuart_1;  // 0x00B4
    void *reserved_0x00B8;         // 0x00B8
    void *reserved_0x00BC;         // 0x00BC
} interrupt_vector_table_t;

#ifdef __cplusplus
}
#endif
#endif // STM_NVIC_H_

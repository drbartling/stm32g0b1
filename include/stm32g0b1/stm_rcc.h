#ifndef STM_RCC_H_
#define STM_RCC_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef union {
    struct {
        uint32_t reserved_0 : 8;
        uint32_t hsion : 1;
        uint32_t hsikeron : 1;
        uint32_t hsirdy : 1;
        uint32_t hsidiv : 3;
        uint32_t reserved_14 : 2;
        uint32_t hseon : 1;
        uint32_t hserdy : 1;
        uint32_t hsebyp : 1;
        uint32_t csson : 1;
        uint32_t reserved_20 : 2;
        uint32_t hsi48on : 1;
        uint32_t hsi48rdy : 1;
        uint32_t pllon : 1;
        uint32_t pllrdy : 1;
        uint32_t reserved_26 : 6;
    };
    uint32_t bits;
} RCC_cr_t;
STATIC_ASSERT_TYPE_SIZE(RCC_cr_t, sizeof(uint32_t));

typedef enum {
    RCC_sw_hsisys  = 0b000,
    RCC_sw_hse     = 0b001,
    RCC_sw_pllrclk = 0b010,
    RCC_sw_lsi     = 0b011,
    RCC_sw_lse     = 0b100,
} RCC_sw_t;

typedef union {
    struct {
        RCC_sw_t       sw : 3;
        RCC_sw_t const sws : 3;
        uint32_t       reserved_6 : 2;
        uint32_t       hpre : 4;
        uint32_t       ppre : 3;
        uint32_t       reserved_15 : 1;
        uint32_t       mco2sel : 4;
        uint32_t       mco2pre : 4;
        uint32_t       mcosel : 4;
        uint32_t       mcopre : 4;
    };
    uint32_t bits;
} RCC_cfgr_t;
STATIC_ASSERT_TYPE_SIZE(RCC_cfgr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t pllsrc : 2;
        uint32_t reserved_2 : 2;
        uint32_t pllm : 3;
        uint32_t reserved_7 : 1;
        uint32_t plln : 7;
        uint32_t reserved_15 : 1;
        uint32_t pllpen : 1;
        uint32_t pllp : 5;
        uint32_t reserved_22 : 2;
        uint32_t pllqen : 1;
        uint32_t pllq : 3;
        uint32_t pllren : 1;
        uint32_t pllr : 3;
    };
    uint32_t bits;
} RCC_pllcfgr_t;
STATIC_ASSERT_TYPE_SIZE(RCC_pllcfgr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t gpioa_en : 1;
        uint32_t gpiob_en : 1;
        uint32_t gpioc_en : 1;
        uint32_t gpiod_en : 1;
        uint32_t gpioe_en : 1;
        uint32_t gpiof_en : 1;
    };
    uint32_t bits;
} RCC_iopenr_t;
STATIC_ASSERT_TYPE_SIZE(RCC_iopenr_t, sizeof(uint32_t));

// rm0444 rev 5 pp197-198
typedef union {
    struct {
        uint32_t dma1en : 1;
        uint32_t dma2en : 1;
        uint32_t reserved_02 : 6;
        uint32_t flashen : 1;
        uint32_t reserved_09 : 3;
        uint32_t crcen : 1;
        uint32_t reserved_13 : 3;
        uint32_t aesen : 1;
        uint32_t reserved_17 : 1;
        uint32_t rngen : 1;
        uint32_t reserved_19 : 13;
    };
    uint32_t bits;
} RCC_ahbenr_t;
STATIC_ASSERT_TYPE_SIZE(RCC_ahbenr_t, sizeof(uint32_t));

// rm0444 rev 5 pp198-201
typedef union {
    struct {
        uint32_t tim2en : 1;
        uint32_t tim3en : 1;
        uint32_t tim4en : 1;
        uint32_t reserved_3 : 1;
        uint32_t tim6en : 1;
        uint32_t tim7en : 1;
        uint32_t reserved_6 : 1;
        uint32_t lpuart2en : 1;
        uint32_t usart5en : 1;
        uint32_t usart6en : 1;
        uint32_t rtcapben : 1;
        uint32_t wwdgen : 1;
        uint32_t fdcanen : 1;
        uint32_t usben : 1;
        uint32_t spi2en : 1;
        uint32_t spi3en : 1;
        uint32_t crsen : 1;
        uint32_t usart2en : 1;
        uint32_t usart3en : 1;
        uint32_t usart4en : 1;
        uint32_t lpuart1en : 1;
        uint32_t i2c1en : 1;
        uint32_t i2c2en : 1;
        uint32_t i2c3en : 1;
        uint32_t cecen : 1;
        uint32_t ucpd1en : 1;
        uint32_t ucpd2en : 1;
        uint32_t dbgen : 1;
        uint32_t pwren : 1;
        uint32_t dac1en : 1;
        uint32_t lptim2en : 1;
        uint32_t lptim1en : 1;
    };
    uint32_t bits;
} RCC_apbenr1_t;
STATIC_ASSERT_TYPE_SIZE(RCC_apbenr1_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t syscfgen : 1;
        uint32_t bit_01 : 1;
        uint32_t bit_02 : 1;
        uint32_t bit_03 : 1;
        uint32_t bit_04 : 1;
        uint32_t bit_05 : 1;
        uint32_t bit_06 : 1;
        uint32_t bit_07 : 1;
        uint32_t bit_08 : 1;
        uint32_t bit_09 : 1;
        uint32_t bit_10 : 1;
        uint32_t tim1en : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t adcen : 1;
        uint32_t bit_21 : 1;
        uint32_t bit_22 : 1;
        uint32_t bit_23 : 1;
        uint32_t bit_24 : 1;
        uint32_t bit_25 : 1;
        uint32_t bit_26 : 1;
        uint32_t bit_27 : 1;
        uint32_t bit_28 : 1;
        uint32_t bit_29 : 1;
        uint32_t bit_30 : 1;
        uint32_t bit_31 : 1;
    };
    uint32_t bits;
} RCC_apbenr2_t;
STATIC_ASSERT_TYPE_SIZE(RCC_apbenr2_t, sizeof(uint32_t));

typedef struct {
    RCC_cr_t volatile cr; /*Clock Control Register */
    uint32_t volatile icscr;
    RCC_cfgr_t volatile cfgr;
    RCC_pllcfgr_t volatile pllcfgr;
    uint32_t volatile reserved0;
    uint32_t volatile crrcr;
    uint32_t volatile cier;
    uint32_t volatile cifr;
    uint32_t volatile cicr;
    uint32_t volatile ioprstr;
    uint32_t volatile ahbrstr;
    uint32_t volatile apbrstr1;
    uint32_t volatile apbrstr2;
    RCC_iopenr_t volatile iopenr;
    RCC_ahbenr_t volatile ahbenr;
    RCC_apbenr1_t volatile apbenr1;
    RCC_apbenr2_t volatile apbenr2;
    uint32_t volatile iopsmenr;
    uint32_t volatile ahbsmenr;
    uint32_t volatile apbsmenr1;
    uint32_t volatile apbsmenr2;
    uint32_t volatile ccipr;
    uint32_t volatile reserved2;
    uint32_t volatile bdcr;
    uint32_t volatile csr;
} RCC_peripheral_registers_t;

#ifdef __cplusplus
}
#endif
#endif // STM_RCC_H_

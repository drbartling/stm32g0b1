#ifndef STM_TIMER1_H_
#define STM_TIMER1_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef union {
    struct {
        uint16_t cen : 1;
        uint16_t udis : 1;
        uint16_t urs : 1;
        uint16_t opm : 1;
        uint16_t dir : 1;
        uint16_t cms : 2;
        uint16_t arpe : 1;
        uint16_t ckd : 2;
        uint16_t reserved_10 : 1;
        uint16_t uifrema : 1;
        uint16_t reserved_12 : 4;
    };
    uint16_t bits;
} TIM1_cr1_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_cr1_t, 2);

typedef union {
    struct {
        uint32_t ccpc : 1;
        uint32_t reserved_01 : 1;
        uint32_t ccus : 1;
        uint32_t ccds : 1;
        uint32_t mms : 3;
        uint32_t ti1s : 1;
        uint32_t ois1 : 1;
        uint32_t ois1n : 1;
        uint32_t ois2 : 1;
        uint32_t ois2n : 1;
        uint32_t ois3 : 1;
        uint32_t ois3n : 1;
        uint32_t ois4 : 1;
        uint32_t reserved_15 : 1;
        uint32_t ois5 : 1;
        uint32_t reserved_17 : 1;
        uint32_t ois6 : 1;
        uint32_t reserved_19 : 1;
        uint32_t mms2 : 4;
        uint32_t reserved_24 : 8;
    };
    uint32_t bits;
} TIM1_cr2_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_cr2_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t sms : 3;
        uint32_t occs : 1;
        uint32_t ts_2_0 : 3;
        uint32_t msm : 1;
        uint32_t etf : 4;
        uint32_t etps : 2;
        uint32_t ece : 1;
        uint32_t etp : 1;
        uint32_t sms_3 : 1;
        uint32_t reserved_17 : 3;
        uint32_t ts_4_3 : 2;
        uint32_t reserved_22 : 10;
    };
    uint32_t bits;
} TIM1_smcr_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_smcr_t, sizeof(uint32_t));

// rm0444 r5 pp. 676-677
typedef union {
    struct {
        uint16_t uie : 1;
        uint16_t cc1ie : 1;
        uint16_t cc2ie : 1;
        uint16_t cc3ie : 1;
        uint16_t cc4ie : 1;
        uint16_t comie : 1;
        uint16_t tie : 1;
        uint16_t bie : 1;
        uint16_t ude : 1;
        uint16_t cc1oe : 1;
        uint16_t cc2oe : 1;
        uint16_t cc3oe : 1;
        uint16_t cc4oe : 1;
        uint16_t comde : 1;
        uint16_t tde : 1;
        uint16_t reserved_15 : 1;
    };
    uint16_t bits;
} TIM1_dier_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_dier_t, sizeof(uint16_t));

// rm0444 r5 pp. 677-679
typedef union {
    struct {
        uint32_t uif : 1;
        uint32_t cc1if : 1;
        uint32_t cc2if : 1;
        uint32_t cc3if : 1;
        uint32_t cc4if : 1;
        uint32_t comif : 1;
        uint32_t tif : 1;
        uint32_t bif : 2;
        uint32_t cc1of : 1;
        uint32_t cc2of : 1;
        uint32_t cc3of : 1;
        uint32_t cc4of : 1;
        uint32_t sbif : 1;
        uint32_t reserved_14 : 2;
        uint32_t cc5if : 1;
        uint32_t cc6if : 1;
        uint32_t reserved_18 : 14;
    };
    uint32_t bits;
} TIM1_sr_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_sr_t, sizeof(uint32_t));

// rm0444 r5 pp. 679-680
typedef union {
    struct {
        uint16_t ug : 1;
        uint16_t cc1g : 1;
        uint16_t cc2g : 1;
        uint16_t cc3g : 1;
        uint16_t cc4g : 1;
        uint16_t comg : 1;
        uint16_t tg : 1;
        uint16_t bg : 1;
        uint16_t b2g : 1;
        uint16_t reserved_09 : 7;
    };
    uint16_t bits;
} TIM1_egr_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_egr_t, sizeof(uint16_t));

typedef union {
    struct {
        uint32_t cc1s : 2;
        uint32_t ic1psc : 2;
        uint32_t ic1f : 4;
        uint32_t cc2s : 2;
        uint32_t ic2psc : 2;
        uint32_t ic2f : 4;
        uint32_t reserved_16 : 16;
    } input_compare_mode;
    struct {
        uint32_t cc1s : 2;
        uint32_t oc1fe : 1;
        uint32_t oc1pe : 1;
        uint32_t oc1m : 3;
        uint32_t oc1ce : 1;
        uint32_t cc2s : 2;
        uint32_t oc2fe : 1;
        uint32_t oc2pe : 1;
        uint32_t oc2m : 3;
        uint32_t oc2ce : 1;
        uint32_t oc1m_3 : 1;
        uint32_t reserved_17 : 7;
        uint32_t oc2m_3 : 1;
        uint32_t reserved_25 : 7;
    } output_compare_mode;
    uint32_t bits;
} TIM1_ccmr1_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_ccmr1_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t cc3s : 2;
        uint32_t ic3psc : 2;
        uint32_t ic3f : 4;
        uint32_t cc4s : 2;
        uint32_t ic4psc : 2;
        uint32_t ic4f : 4;
        uint32_t reserved_16 : 16;
    } input_compare_mode;
    struct {
        uint32_t cc3s : 2;
        uint32_t oc3fe : 1;
        uint32_t oc3pe : 1;
        uint32_t oc3m : 3;
        uint32_t oc3ce : 1;
        uint32_t cc4s : 2;
        uint32_t oc4fe : 1;
        uint32_t oc4pe : 1;
        uint32_t oc4m : 3;
        uint32_t oc4ce : 1;
        uint32_t oc3m_3 : 1;
        uint32_t reserved_17 : 7;
        uint32_t oc4m_3 : 1;
        uint32_t reserved_25 : 7;
    } output_compare_mode;
    uint32_t bits;
} TIM1_ccmr2_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_ccmr2_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t cc1e : 1;
        uint32_t cc1p : 1;
        uint32_t cc1ne : 1;
        uint32_t cc1np : 1;
        uint32_t cc2e : 1;
        uint32_t cc2p : 1;
        uint32_t cc2ne : 1;
        uint32_t cc2np : 1;
        uint32_t cc3e : 1;
        uint32_t cc3p : 1;
        uint32_t cc3ne : 1;
        uint32_t cc3np : 1;
        uint32_t cc4e : 1;
        uint32_t cc4p : 1;
        uint32_t reserved_14 : 1;
        uint32_t cc4np : 1;
        uint32_t cc5e : 1;
        uint32_t cc5p : 1;
        uint32_t reserved_18 : 2;
        uint32_t cc6e : 1;
        uint32_t cc6p : 1;
        uint32_t reserved_22 : 10;
    };
    uint32_t bits;
} TIM1_ccer_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_ccer_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_cnt_t;
STATIC_ASSERT_TYPE_SIZE(TIM1_cnt_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_psc_t;

// rm0444 p. 689
typedef union {
    struct {
        uint16_t lower;
        uint16_t upper;
    };
    uint32_t bits;
} TIM1_arr_t;

typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_reserved_0x30_t;
typedef union {
    struct {
        uint16_t lower;
        uint16_t upper;
    };
    uint32_t bits;
} TIM1_ccr_t;

typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_reserved_0x44_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_dcr_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_dmar_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_or1_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_reserved_0x54_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_af1_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_reserved_0x64_t;
typedef union {
    struct {
        uint32_t bit_00 : 1;
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
        uint32_t bit_11 : 1;
        uint32_t bit_12 : 1;
        uint32_t bit_13 : 1;
        uint32_t bit_14 : 1;
        uint32_t bit_15 : 1;
        uint32_t bit_16 : 1;
        uint32_t bit_17 : 1;
        uint32_t bit_18 : 1;
        uint32_t bit_19 : 1;
        uint32_t bit_20 : 1;
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
} TIM1_tisel_t;

// rm0444 r5 p. 625
// rm0444 r5 pp. 699-701
typedef struct {
    TIM1_cr1_t volatile cr1;
    TIM1_cr2_t volatile cr2;
    TIM1_smcr_t volatile smcr;
    TIM1_dier_t volatile dier;
    uint16_t volatile reserved_0x0E;
    TIM1_sr_t volatile sr;
    TIM1_egr_t volatile egr;
    TIM1_ccmr1_t volatile ccmr1;
    TIM1_ccmr2_t volatile ccmr2;
    TIM1_ccer_t volatile ccer;
    TIM1_cnt_t volatile cnt;
    TIM1_psc_t volatile psc;
    TIM1_arr_t volatile arr;
    TIM1_reserved_0x30_t volatile reserved_0x30;
    TIM1_ccr_t volatile ccr1;
    TIM1_ccr_t volatile ccr2;
    TIM1_ccr_t volatile ccr3;
    TIM1_ccr_t volatile ccr4;
    TIM1_reserved_0x44_t volatile reserved_0x44;
    TIM1_dcr_t volatile dcr;
    TIM1_dmar_t volatile dmar;
    TIM1_or1_t volatile or1;
    TIM1_reserved_0x54_t volatile reserved_0x54[3];
    TIM1_af1_t volatile af1;
    TIM1_reserved_0x64_t volatile reserved_0x64;
    TIM1_tisel_t volatile tisel;
} TIM1_peripheral_registers_t;
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, dier, 0x0C);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, reserved_0x0E, 0x0E);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, sr, 0x10);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, egr, 0x14);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, arr, 0x2C);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, ccr1, 0x34);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, dcr, 0x48);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, or1, 0x50);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, af1, 0x60);
STATIC_ASSERT_MEMBER_OFFSET(TIM1_peripheral_registers_t, tisel, 0x68);

#ifdef __cplusplus
}
#endif
#endif // STM_TIMER1_H_

#ifndef STM_GENERAL_PURPOSE_TIMER_H_
#define STM_GENERAL_PURPOSE_TIMER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef union {
    struct {
        uint32_t cen : 1;
        uint32_t udis : 1;
        uint32_t urs : 1;
        uint32_t opm : 1;
        uint32_t dir : 1;
        uint32_t cms : 2;
        uint32_t arpe : 1;
        uint32_t ckd : 2;
        uint32_t reserved_10 : 1;
        uint32_t uifrema : 1;
        uint32_t reserved_12 : 4;
        uint32_t reserved_16 : 16;
    };
    uint32_t bits;
} GPTIM_cr1_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_cr1_t, sizeof(GPTIM_cr1_t));

typedef union {
    struct {
        uint32_t bit_00_reserved_0 : 3;
        uint32_t bit_03_ccds : 1;
        uint32_t bit_04_mms : 3;
        uint32_t bit_05_ti1s : 1;
        uint32_t bit_08_reserved_8 : 8;
        uint32_t bit_16_reserved_16 : 16;
    };
    uint32_t bits;
} GPTIM_cr2_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_cr1_t, sizeof(GPTIM_cr2_t));

typedef union {
    struct {
        uint32_t bit_00_sms : 3;
        uint32_t bit_03_reserved_3 : 1;
        uint32_t bit_04_ts : 3;
        uint32_t bit_07_msm : 1;
        uint32_t bit_08_etf : 4;
        uint32_t bit_12_etps : 2;
        uint32_t bit_14_ece : 1;
        uint32_t bit_15_etp : 1;
        uint32_t bit_16_sms_3 : 1;
        uint32_t bit_17_reserved_17 : 3;
        uint32_t bit_20_ts : 2;
        uint32_t bit_22_reserved_22 : 10;
    };
    uint32_t bits;
} GPTIM_smcr_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_smcr_t, sizeof(GPTIM_cr2_t));

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
} GPTIM_dier_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_dier_t, sizeof(GPTIM_cr2_t));

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
} GPTIM_sr_t;
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
} GPTIM_egr_t;

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
} GPTIM_ccmr1_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_ccmr1_t, sizeof(GPTIM_cr1_t));

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
} GPTIM_ccmr2_t;
STATIC_ASSERT_TYPE_SIZE(GPTIM_ccmr2_t, sizeof(GPTIM_cr1_t));

typedef union {
    struct {
        uint32_t cc1e : 1;
        uint32_t cc1p : 1;
        uint32_t reserved_2 : 1;
        uint32_t cc1np : 1;
        uint32_t cc2e : 1;
        uint32_t cc2p : 1;
        uint32_t reserved_6 : 1;
        uint32_t cc2np : 1;
        uint32_t cc3e : 1;
        uint32_t cc3p : 1;
        uint32_t reserved_10 : 1;
        uint32_t cc3np : 1;
        uint32_t cc4e : 1;
        uint32_t cc4p : 1;
        uint32_t reserved_14 : 1;
        uint32_t cc4np : 1;
        uint32_t reserved_16 : 16;
    };
    uint32_t bits;
} GPTIM_ccer_t;
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
} GPTIM_cnt_t;
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
} GPTIM_psc_t;

// rm0444 p. 689
typedef union {
    struct {
        uint16_t lower;
        uint16_t upper;
    };
    uint32_t bits;
} GPTIM_arr_t;

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
} GPTIM_reserved_0x30_t;
typedef union {
    struct {
        uint16_t lower;
        uint16_t upper;
    };
    uint32_t bits;
} GPTIM_ccr_t;

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
} GPTIM_reserved_0x44_t;
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
} GPTIM_dcr_t;
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
} GPTIM_dmar_t;
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
} GPTIM_or1_t;
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
} GPTIM_reserved_0x54_t;
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
} GPTIM_af1_t;
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
} GPTIM_reserved_0x64_t;
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
} GPTIM_tisel_t;

typedef struct {
    GPTIM_cr1_t volatile cr1;
    GPTIM_cr2_t volatile cr2;
    GPTIM_smcr_t volatile smcr;
    GPTIM_dier_t volatile dier;
    GPTIM_sr_t volatile sr;
    GPTIM_egr_t volatile egr;
    GPTIM_ccmr1_t volatile ccmr1;
    GPTIM_ccmr2_t volatile ccmr2;
    GPTIM_ccer_t volatile ccer;
    GPTIM_cnt_t volatile cnt;
    GPTIM_psc_t volatile psc;
    GPTIM_arr_t volatile arr;
    GPTIM_reserved_0x30_t volatile reserved_0x30;
    GPTIM_ccr_t volatile ccr1;
    GPTIM_ccr_t volatile ccr2;
    GPTIM_ccr_t volatile ccr3;
    GPTIM_ccr_t volatile ccr4;
    GPTIM_reserved_0x44_t volatile reserved_0x44;
    GPTIM_dcr_t volatile dcr;
    GPTIM_dmar_t volatile dmar;
    GPTIM_or1_t volatile or1;
    GPTIM_reserved_0x54_t volatile reserved_0x54[3];
    GPTIM_af1_t volatile af1;
    GPTIM_reserved_0x64_t volatile reserved_0x64;
    GPTIM_tisel_t volatile tisel;
} GPTIM_peripheral_registers_t;
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, arr, 0x2C);
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, ccr1, 0x34);
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, dcr, 0x48);
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, or1, 0x50);
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, af1, 0x60);
STATIC_ASSERT_MEMBER_OFFSET(GPTIM_peripheral_registers_t, tisel, 0x68);

#ifdef __cplusplus
}
#endif
#endif // STM_GENERAL_PURPOSE_TIMER_H_

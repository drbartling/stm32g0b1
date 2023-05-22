#ifndef STM_ADC_H_
#define STM_ADC_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

typedef union {
    struct {
        uint32_t adrdy : 1;
        uint32_t eosmp : 1;
        uint32_t eoc : 1;
        uint32_t eos : 1;
        uint32_t ovr : 1;
        uint32_t reserved_5 : 2;
        uint32_t awd1 : 1;
        uint32_t awd2 : 1;
        uint32_t awd3 : 1;
        uint32_t reserved_10 : 1;
        uint32_t eocal : 1;
        uint32_t reserved_12 : 1;
        uint32_t ccrdy : 1;
        uint32_t reserved_14 : 18;
    };
    uint32_t bits;
} ADC_isr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_isr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t adrdyie : 1;
        uint32_t eosmpie : 1;
        uint32_t eocie : 1;
        uint32_t eosie : 1;
        uint32_t ovrie : 1;
        uint32_t reserved_5 : 2;
        uint32_t awd1ie : 1;
        uint32_t awd2ie : 1;
        uint32_t awd3ie : 1;
        uint32_t reserved_10 : 1;
        uint32_t eocalie : 1;
        uint32_t reserved_12 : 1;
        uint32_t ccrdyie : 1;
        uint32_t reserved_14 : 18;
    };
    uint32_t bits;
} ADC_ier_t;
STATIC_ASSERT_TYPE_SIZE(ADC_ier_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t aden : 1;
        uint32_t addis : 1;
        uint32_t adstart : 1;
        uint32_t reserved_3 : 1;
        uint32_t adstp : 1;
        uint32_t reserved_05 : 23;
        uint32_t advregen : 1;
        uint32_t reserved_29 : 2;
        uint32_t adcal : 1;
    };
    uint32_t bits;
} ADC_cr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_cr_t, sizeof(uint32_t));

typedef enum {
    ADC_res_12_bits = 0,
    ADC_res_10_bits = 1,
    ADC_res_8_bits  = 2,
    ADC_res_6_bits  = 3,
} ADC_res_t;

typedef enum {
    ADC_exten_software_start = 0b00,
    ADC_exten_rising_edge    = 0b01,
    ADC_exten_falling_edge   = 0b10,
    ADC_exten_all_edges      = 0b11,
} ADC_exten_t;

typedef enum {
    ADC_ovrmod_preserve_oldest  = 0b0,
    ADC_ovrmod_overwrite_oldest = 0b1,
} ADC_ovrmod_t;

typedef union {
    struct {
        uint32_t     dmaen : 1;
        uint32_t     dmacfg : 1;
        uint32_t     scandir : 1;
        ADC_res_t    res : 2;
        uint32_t     align : 1;
        uint32_t     extsel : 3;
        uint32_t     reserved_09 : 1;
        ADC_exten_t  exten : 2;
        ADC_ovrmod_t ovrmod : 1;
        uint32_t     cont : 1;
        uint32_t     wait : 1;
        uint32_t     autoff : 1;
        uint32_t     discen : 1;
        uint32_t     reserved_17 : 4;
        uint32_t     chselrmod : 1;
        uint32_t     awd1sgl : 1;
        uint32_t     awd1en : 1;
        uint32_t     reserved_24 : 2;
        uint32_t     awd1ch : 5;
        uint32_t     reserved_31 : 1;
    };
    uint32_t bits;
} ADC_cfgr1_t;
STATIC_ASSERT_TYPE_SIZE(ADC_cfgr1_t, sizeof(uint32_t));

typedef enum {
    ADC_ovsr_x2   = 0,
    ADC_ovsr_x4   = 1,
    ADC_ovsr_x8   = 2,
    ADC_ovsr_x16  = 3,
    ADC_ovsr_x32  = 4,
    ADC_ovsr_x64  = 5,
    ADC_ovsr_x128 = 6,
    ADC_ovsr_x256 = 7,
} ADC_ovsr_t;

typedef enum {
    ADC_ckmode_adcclk    = 0,
    ADC_ckmode_pclk_div2 = 1,
    ADC_ckmode_pclk_div4 = 2,
    ADC_ckmode_pclk_div1 = 3,
} ADC_ckmode_t;

typedef union {
    struct {
        uint32_t ovse : 1;
        uint32_t reserved_01 : 1;
        uint32_t ovsr : 3;
        /// Oversampling shift.  Number of bits to shift out of ADC result
        uint32_t ovss : 4;
        uint32_t tovs : 1;
        uint32_t resereved_10 : 19;
        uint32_t lftrig : 1;
        uint32_t ckmode : 2;
    };
    uint32_t bits;
} ADC_cfgr2_t;
STATIC_ASSERT_TYPE_SIZE(ADC_cfgr2_t, sizeof(uint32_t));

typedef enum {
    ADC_smp_1p5_cycles   = 0b000,
    ADC_smp_3p5_cycles   = 0b001,
    ADC_smp_7p5_cycles   = 0b010,
    ADC_smp_12p5_cycles  = 0b011,
    ADC_smp_19p5_cycles  = 0b100,
    ADC_smp_39p5_cycles  = 0b101,
    ADC_smp_79p5_cycles  = 0b110,
    ADC_smp_160p5_cycles = 0b111,
} ADC_smp_t;

typedef union {
    struct {
        ADC_smp_t smp1 : 3;
        uint32_t  reserved_03 : 1;
        ADC_smp_t smp2 : 3;
        uint32_t  reserved_07 : 1;
        uint32_t  smpsel00 : 1;
        uint32_t  smpsel01 : 1;
        uint32_t  smpsel02 : 1;
        uint32_t  smpsel03 : 1;
        uint32_t  smpsel04 : 1;
        uint32_t  smpsel05 : 1;
        uint32_t  smpsel06 : 1;
        uint32_t  smpsel07 : 1;
        uint32_t  smpsel08 : 1;
        uint32_t  smpsel09 : 1;
        uint32_t  smpsel10 : 1;
        uint32_t  smpsel11 : 1;
        uint32_t  smpsel12 : 1;
        uint32_t  smpsel13 : 1;
        uint32_t  smpsel14 : 1;
        uint32_t  smpsel15 : 1;
        uint32_t  smpsel16 : 1;
        uint32_t  smpsel17 : 1;
        uint32_t  smpsel18 : 1;
        uint32_t  reserved_27 : 5;
    };
    uint32_t bits;
} ADC_smpr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_smpr_t, sizeof(uint32_t));

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
} ADC_awd1tr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_awd1tr_t, sizeof(uint32_t));

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
} ADC_awd2tr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_awd2tr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t chsel_00 : 1;
        uint32_t chsel_01 : 1;
        uint32_t chsel_02 : 1;
        uint32_t chsel_03 : 1;
        uint32_t chsel_04 : 1;
        uint32_t chsel_05 : 1;
        uint32_t chsel_06 : 1;
        uint32_t chsel_07 : 1;
        uint32_t chsel_08 : 1;
        uint32_t chsel_09 : 1;
        uint32_t chsel_10 : 1;
        uint32_t chsel_11 : 1;
        uint32_t chsel_12 : 1;
        uint32_t chsel_13 : 1;
        uint32_t chsel_14 : 1;
        uint32_t chsel_15 : 1;
        uint32_t chsel_16 : 1;
        uint32_t chsel_17 : 1;
        uint32_t chsel_18 : 1;
        uint32_t reserved_19 : 13;
    };
    uint32_t bits;
} ADC_chselr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_chselr_t, sizeof(uint32_t));

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
} ADC_aed3tr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_aed3tr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint16_t data : 16;
        uint16_t reserved_16 : 16;
    };
    uint32_t bits;
} ADC_adc_dr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_adc_dr_t, sizeof(uint32_t));

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
} ADC_awd2cr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_awd2cr_t, sizeof(uint32_t));

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
} ADC_awd3cr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_awd3cr_t, sizeof(uint32_t));

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
} ADC_calfact_t;
STATIC_ASSERT_TYPE_SIZE(ADC_calfact_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t reserved_0 : 18;
        uint32_t presc : 4;
        uint32_t vrefen : 1;
        uint32_t tsen : 1;
        uint32_t vbaten : 1;
        uint32_t reserved_25 : 7;
    };
    uint32_t bits;
} ADC_ccr_t;
STATIC_ASSERT_TYPE_SIZE(ADC_ccr_t, sizeof(uint32_t));

typedef struct {
    ADC_isr_t volatile isr;
    ADC_ier_t volatile ier;
    ADC_cr_t volatile cr;
    ADC_cfgr1_t volatile cfgr1;
    ADC_cfgr2_t volatile cfgr2;
    ADC_smpr_t volatile smpr;
    uint32_t volatile const reserved_0x018[2];
    ADC_awd1tr_t volatile awd1tr;
    ADC_awd2tr_t volatile awd2tr;
    ADC_chselr_t volatile chselr;
    ADC_aed3tr_t volatile aed3tr;
    uint32_t volatile const reserved_0x030[4];
    ADC_adc_dr_t volatile dr;
    uint32_t volatile const reserved_0x044[23];
    ADC_awd2cr_t volatile awd2cr;
    ADC_awd3cr_t volatile awd3cr;
    uint32_t volatile const reserved_0x0a8[3];
    ADC_calfact_t volatile calfact;
    uint32_t volatile const reserved_0x0b8[148];
    ADC_ccr_t volatile ccr;
} ADC_peripheral_registers_t;
STATIC_ASSERT_MEMBER_OFFSET(ADC_peripheral_registers_t, dr, 0x040);
STATIC_ASSERT_MEMBER_OFFSET(ADC_peripheral_registers_t, calfact, 0x0B4);
STATIC_ASSERT_MEMBER_OFFSET(ADC_peripheral_registers_t, ccr, 0x308);

void    ADC_init(void);
int16_t read_adc(ADC_chselr_t const);
void    ADC_isr(void);

#ifdef __cplusplus
}
#endif
#endif // STM_ADC_H_

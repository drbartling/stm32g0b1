/**
 * @file
 * @version 1.6
 * @brief Register access structs for None LPTIM1
 *
 * Low power timer
 *
 * @note This file is autogenerated using register-code-gen
 */

#ifndef LPTIM1_H_
#define LPTIM1_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

/**
 * Interrupt and Status Register
 */
typedef union LPTIM1_lptim_isr_u {
    struct {
        /// Compare match The CMPM bit is set by hardware to inform application
        /// that LPTIM_CNT register value reached the LPTIM_CMP registerâs
        /// value.
        uint32_t const cmpm : 1;
        /// Autoreload match ARRM is set by hardware to inform application that
        /// LPTIM_CNT registerâs value reached the LPTIM_ARR registerâs
        /// value. ARRM flag can be cleared by writing 1 to the ARRMCF bit in
        /// the LPTIM_ICR register.
        uint32_t const arrm : 1;
        /// External trigger edge event EXTTRIG is set by hardware to inform
        /// application that a valid edge on the selected external trigger input
        /// has occurred. If the trigger is ignored because the timer has
        /// already started, then this flag is not set. EXTTRIG flag can be
        /// cleared by writing 1 to the EXTTRIGCF bit in the LPTIM_ICR register.
        uint32_t const exttrig : 1;
        /// Compare register update OK CMPOK is set by hardware to inform
        /// application that the APB bus write operation to the LPTIM_CMP
        /// register has been successfully completed.
        uint32_t const cmpok : 1;
        /// Autoreload register update OK ARROK is set by hardware to inform
        /// application that the APB bus write operation to the LPTIM_ARR
        /// register has been successfully completed. ARROK flag can be cleared
        /// by writing 1 to the ARROKCF bit in the LPTIM_ICR register.
        uint32_t const arrok : 1;
        /// Counter direction change down to up In Encoder mode, UP bit is set
        /// by hardware to inform application that the counter direction has
        /// changed from down to up. UP flag can be cleared by writing 1 to the
        /// UPCF bit in the LPTIM_ICR register. Note: If the LPTIM does not
        /// support encoder mode feature, this bit is reserved. Please refer to
        /// .
        uint32_t const up : 1;
        /// Counter direction change up to down In Encoder mode, DOWN bit is set
        /// by hardware to inform application that the counter direction has
        /// changed from up to down. DOWN flag can be cleared by writing 1 to
        /// the DOWNCF bit in the LPTIM_ICR register. Note: If the LPTIM does
        /// not support encoder mode feature, this bit is reserved. Please refer
        /// to .
        uint32_t const down : 1;
    };
    uint32_t bits;
} LPTIM1_lptim_isr_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_isr_t, sizeof(uint32_t));

/**
 * Interrupt Clear Register
 */
typedef union LPTIM1_lptim_icr_u {
    struct {
        /// Compare match clear flag Writing 1 to this bit clears the CMP flag
        /// in the LPTIM_ISR register
        uint32_t cmpmcf : 1;
        /// Autoreload match clear flag Writing 1 to this bit clears the ARRM
        /// flag in the LPTIM_ISR register
        uint32_t arrmcf : 1;
        /// External trigger valid edge clear flag Writing 1 to this bit clears
        /// the EXTTRIG flag in the LPTIM_ISR register
        uint32_t exttrigcf : 1;
        /// Compare register update OK clear flag Writing 1 to this bit clears
        /// the CMPOK flag in the LPTIM_ISR register
        uint32_t cmpokcf : 1;
        /// Autoreload register update OK clear flag Writing 1 to this bit
        /// clears the ARROK flag in the LPTIM_ISR register
        uint32_t arrokcf : 1;
        /// Direction change to UP clear flag Writing 1 to this bit clear the UP
        /// flag in the LPTIM_ISR register. Note: If the LPTIM does not support
        /// encoder mode feature, this bit is reserved. Please refer to .
        uint32_t upcf : 1;
        /// Direction change to down clear flag Writing 1 to this bit clear the
        /// DOWN flag in the LPTIM_ISR register. Note: If the LPTIM does not
        /// support encoder mode feature, this bit is reserved. Please refer to
        /// .
        uint32_t downcf : 1;
    };
    uint32_t bits;
} LPTIM1_lptim_icr_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_icr_t, sizeof(uint32_t));

/**
 * Compare match Interrupt Enable
 */
typedef enum LPTIM1_cmpmie_e {
    /// CMPM interrupt disabled
    LPTIM1_cmpmie_b_0x0 = 0x0,
    /// CMPM interrupt enabled
    LPTIM1_cmpmie_b_0x1 = 0x1,
} LPTIM1_cmpmie_t;

/**
 * Autoreload match Interrupt Enable
 */
typedef enum LPTIM1_arrmie_e {
    /// ARRM interrupt disabled
    LPTIM1_arrmie_b_0x0 = 0x0,
    /// ARRM interrupt enabled
    LPTIM1_arrmie_b_0x1 = 0x1,
} LPTIM1_arrmie_t;

/**
 * External trigger valid edge Interrupt Enable
 */
typedef enum LPTIM1_exttrigie_e {
    /// EXTTRIG interrupt disabled
    LPTIM1_exttrigie_b_0x0 = 0x0,
    /// EXTTRIG interrupt enabled
    LPTIM1_exttrigie_b_0x1 = 0x1,
} LPTIM1_exttrigie_t;

/**
 * Compare register update OK Interrupt Enable
 */
typedef enum LPTIM1_cmpokie_e {
    /// CMPOK interrupt disabled
    LPTIM1_cmpokie_b_0x0 = 0x0,
    /// CMPOK interrupt enabled
    LPTIM1_cmpokie_b_0x1 = 0x1,
} LPTIM1_cmpokie_t;

/**
 * Autoreload register update OK Interrupt Enable
 */
typedef enum LPTIM1_arrokie_e {
    /// ARROK interrupt disabled
    LPTIM1_arrokie_b_0x0 = 0x0,
    /// ARROK interrupt enabled
    LPTIM1_arrokie_b_0x1 = 0x1,
} LPTIM1_arrokie_t;

/**
 * Direction change to UP Interrupt Enable Note: If the LPTIM does not support
 * encoder mode feature, this bit is reserved. Please refer to .
 */
typedef enum LPTIM1_upie_e {
    /// UP interrupt disabled
    LPTIM1_upie_b_0x0 = 0x0,
    /// UP interrupt enabled
    LPTIM1_upie_b_0x1 = 0x1,
} LPTIM1_upie_t;

/**
 * Direction change to down Interrupt Enable Note: If the LPTIM does not support
 * encoder mode feature, this bit is reserved. Please refer to .
 */
typedef enum LPTIM1_downie_e {
    /// DOWN interrupt disabled
    LPTIM1_downie_b_0x0 = 0x0,
    /// DOWN interrupt enabled
    LPTIM1_downie_b_0x1 = 0x1,
} LPTIM1_downie_t;

/**
 * Interrupt Enable Register
 */
typedef union LPTIM1_lptim_ier_u {
    struct {
        /// Compare match Interrupt Enable
        LPTIM1_cmpmie_t cmpmie : 1;
        /// Autoreload match Interrupt Enable
        LPTIM1_arrmie_t arrmie : 1;
        /// External trigger valid edge Interrupt Enable
        LPTIM1_exttrigie_t exttrigie : 1;
        /// Compare register update OK Interrupt Enable
        LPTIM1_cmpokie_t cmpokie : 1;
        /// Autoreload register update OK Interrupt Enable
        LPTIM1_arrokie_t arrokie : 1;
        /// Direction change to UP Interrupt Enable Note: If the LPTIM does not
        /// support encoder mode feature, this bit is reserved. Please refer to
        /// .
        LPTIM1_upie_t upie : 1;
        /// Direction change to down Interrupt Enable Note: If the LPTIM does
        /// not support encoder mode feature, this bit is reserved. Please refer
        /// to .
        LPTIM1_downie_t downie : 1;
    };
    uint32_t bits;
} LPTIM1_lptim_ier_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_ier_t, sizeof(uint32_t));

/**
 * Clock selector The CKSEL bit selects which clock source the LPTIM will use:
 */
typedef enum LPTIM1_cksel_e {
    /// LPTIM is clocked by internal clock source (APB clock or any of the
    /// embedded oscillators)
    LPTIM1_cksel_b_0x0 = 0x0,
    /// LPTIM is clocked by an external clock source through the LPTIM external
    /// Input1
    LPTIM1_cksel_b_0x1 = 0x1,
} LPTIM1_cksel_t;

/**
 * Clock Polarity If LPTIM is clocked by an external clock source: When the
 * LPTIM is clocked by an external clock source, CKPOL bits is used to configure
 * the active edge or edges used by the counter: If the LPTIM is configured in
 * Encoder mode (ENC bit is set), the encoder sub-mode 1 is active. If the LPTIM
 * is configured in Encoder mode (ENC bit is set), the encoder sub-mode 2 is
 * active. Refer to for more details about Encoder mode sub-modes.
 */
typedef enum LPTIM1_ckpol_e {
    /// the rising edge is the active edge used for counting.
    LPTIM1_ckpol_b_0x0 = 0x0,
    /// the falling edge is the active edge used for counting
    LPTIM1_ckpol_b_0x1 = 0x1,
    /// both edges are active edges. When both external clock signal edges are
    /// considered active ones, the LPTIM must also be clocked by an internal
    /// clock source with a frequency equal to at least four times the external
    /// clock frequency.If the LPTIM is configured in Encoder mode (ENC bit is
    /// set), the encoder sub-mode 3 is active.
    LPTIM1_ckpol_b_0x2 = 0x2,
    /// not allowed
    LPTIM1_ckpol_b_0x3 = 0x3,
} LPTIM1_ckpol_t;

/**
 * Configurable digital filter for external clock The CKFLT value sets the
 * number of consecutive equal samples that should be detected when a level
 * change occurs on an external clock signal before it is considered as a valid
 * level transition. An internal clock source must be present to use this
 * feature
 */
typedef enum LPTIM1_ckflt_e {
    /// any external clock signal level change is considered as a valid
    /// transition
    LPTIM1_ckflt_b_0x0 = 0x0,
    /// external clock signal level change must be stable for at least 2 clock
    /// periods before it is considered as valid transition.
    LPTIM1_ckflt_b_0x1 = 0x1,
    /// external clock signal level change must be stable for at least 4 clock
    /// periods before it is considered as valid transition.
    LPTIM1_ckflt_b_0x2 = 0x2,
    /// external clock signal level change must be stable for at least 8 clock
    /// periods before it is considered as valid transition.
    LPTIM1_ckflt_b_0x3 = 0x3,
} LPTIM1_ckflt_t;

/**
 * Configurable digital filter for trigger The TRGFLT value sets the number of
 * consecutive equal samples that should be detected when a level change occurs
 * on an internal trigger before it is considered as a valid level transition.
 * An internal clock source must be present to use this feature
 */
typedef enum LPTIM1_trgflt_e {
    /// any trigger active level change is considered as a valid trigger
    LPTIM1_trgflt_b_0x0 = 0x0,
    /// trigger active level change must be stable for at least 2 clock periods
    /// before it is considered as valid trigger.
    LPTIM1_trgflt_b_0x1 = 0x1,
    /// trigger active level change must be stable for at least 4 clock periods
    /// before it is considered as valid trigger.
    LPTIM1_trgflt_b_0x2 = 0x2,
    /// trigger active level change must be stable for at least 8 clock periods
    /// before it is considered as valid trigger.
    LPTIM1_trgflt_b_0x3 = 0x3,
} LPTIM1_trgflt_t;

/**
 * Clock prescaler The PRESC bits configure the prescaler division factor. It
 * can be one among the following division factors:
 */
typedef enum LPTIM1_presc_e {
    ////1
    LPTIM1_presc_b_0x0 = 0x0,
    ////2
    LPTIM1_presc_b_0x1 = 0x1,
    ////4
    LPTIM1_presc_b_0x2 = 0x2,
    ////8
    LPTIM1_presc_b_0x3 = 0x3,
    ////16
    LPTIM1_presc_b_0x4 = 0x4,
    ////32
    LPTIM1_presc_b_0x5 = 0x5,
    ////64
    LPTIM1_presc_b_0x6 = 0x6,
    ////128
    LPTIM1_presc_b_0x7 = 0x7,
} LPTIM1_presc_t;

/**
 * Trigger selector The TRIGSEL bits select the trigger source that will serve
 * as a trigger event for the LPTIM among the below 8 available sources: See for
 * details.
 */
typedef enum LPTIM1_trigsel_e {
    /// lptim_ext_trig0
    LPTIM1_trigsel_b_0x0 = 0x0,
    /// lptim_ext_trig1
    LPTIM1_trigsel_b_0x1 = 0x1,
    /// lptim_ext_trig2
    LPTIM1_trigsel_b_0x2 = 0x2,
    /// lptim_ext_trig3
    LPTIM1_trigsel_b_0x3 = 0x3,
    /// lptim_ext_trig4
    LPTIM1_trigsel_b_0x4 = 0x4,
    /// lptim_ext_trig5
    LPTIM1_trigsel_b_0x5 = 0x5,
    /// lptim_ext_trig6
    LPTIM1_trigsel_b_0x6 = 0x6,
    /// lptim_ext_trig7
    LPTIM1_trigsel_b_0x7 = 0x7,
} LPTIM1_trigsel_t;

/**
 * Trigger enable and polarity The TRIGEN bits controls whether the LPTIM
 * counter is started by an external trigger or not. If the external trigger
 * option is selected, three configurations are possible for the trigger active
 * edge:
 */
typedef enum LPTIM1_trigen_e {
    /// software trigger (counting start is initiated by software)
    LPTIM1_trigen_b_0x0 = 0x0,
    /// rising edge is the active edge
    LPTIM1_trigen_b_0x1 = 0x1,
    /// falling edge is the active edge
    LPTIM1_trigen_b_0x2 = 0x2,
    /// both edges are active edges
    LPTIM1_trigen_b_0x3 = 0x3,
} LPTIM1_trigen_t;

/**
 * Timeout enable The TIMOUT bit controls the Timeout feature
 */
typedef enum LPTIM1_timout_e {
    /// A trigger event arriving when the timer is already started will be
    /// ignored
    LPTIM1_timout_b_0x0 = 0x0,
    /// A trigger event arriving when the timer is already started will reset
    /// and restart the counter
    LPTIM1_timout_b_0x1 = 0x1,
} LPTIM1_timout_t;

/**
 * Waveform shape The WAVE bit controls the output shape
 */
typedef enum LPTIM1_wave_e {
    /// Deactivate Set-once mode, PWM or One Pulse waveform depending on how the
    /// timer was started, CNTSTRT for PWM or SNGSTRT for One Pulse waveform.
    LPTIM1_wave_b_0x0 = 0x0,
    /// Activate the Set-once mode
    LPTIM1_wave_b_0x1 = 0x1,
} LPTIM1_wave_t;

/**
 * Waveform shape polarity The WAVEPOL bit controls the output polarity
 */
typedef enum LPTIM1_wavpol_e {
    /// The LPTIM output reflects the compare results between LPTIM_CNT and
    /// LPTIM_CMP registers
    LPTIM1_wavpol_b_0x0 = 0x0,
    /// The LPTIM output reflects the inverse of the compare results between
    /// LPTIM_CNT and LPTIM_CMP registers
    LPTIM1_wavpol_b_0x1 = 0x1,
} LPTIM1_wavpol_t;

/**
 * Registers update mode The PRELOAD bit controls the LPTIM_ARR and the
 * LPTIM_CMP registers update modality
 */
typedef enum LPTIM1_preload_e {
    /// Registers are updated after each APB bus write access
    LPTIM1_preload_b_0x0 = 0x0,
    /// Registers are updated at the end of the current LPTIM period
    LPTIM1_preload_b_0x1 = 0x1,
} LPTIM1_preload_t;

/**
 * counter mode enabled The COUNTMODE bit selects which clock source is used by
 * the LPTIM to clock the counter:
 */
typedef enum LPTIM1_countmode_e {
    /// the counter is incremented following each internal clock pulse
    LPTIM1_countmode_b_0x0 = 0x0,
    /// the counter is incremented following each valid clock pulse on the LPTIM
    /// external Input1
    LPTIM1_countmode_b_0x1 = 0x1,
} LPTIM1_countmode_t;

/**
 * Encoder mode enable The ENC bit controls the Encoder mode Note: If the LPTIM
 * does not support encoder mode feature, this bit is reserved. Please refer to
 * .
 */
typedef enum LPTIM1_enc_e {
    /// Encoder mode disabled
    LPTIM1_enc_b_0x0 = 0x0,
    /// Encoder mode enabled
    LPTIM1_enc_b_0x1 = 0x1,
} LPTIM1_enc_t;

/**
 * Configuration Register
 */
typedef union LPTIM1_lptim_cfgr_u {
    struct {
        /// Clock selector The CKSEL bit selects which clock source the LPTIM
        /// will use:
        LPTIM1_cksel_t cksel : 1;
        /// Clock Polarity If LPTIM is clocked by an external clock source: When
        /// the LPTIM is clocked by an external clock source, CKPOL bits is used
        /// to configure the active edge or edges used by the counter: If the
        /// LPTIM is configured in Encoder mode (ENC bit is set), the encoder
        /// sub-mode 1 is active. If the LPTIM is configured in Encoder mode
        /// (ENC bit is set), the encoder sub-mode 2 is active. Refer to for
        /// more details about Encoder mode sub-modes.
        LPTIM1_ckpol_t ckpol : 2;
        /// Configurable digital filter for external clock The CKFLT value sets
        /// the number of consecutive equal samples that should be detected when
        /// a level change occurs on an external clock signal before it is
        /// considered as a valid level transition. An internal clock source
        /// must be present to use this feature
        LPTIM1_ckflt_t ckflt : 2;
        uint32_t const reserved_05 : 1;
        /// Configurable digital filter for trigger The TRGFLT value sets the
        /// number of consecutive equal samples that should be detected when a
        /// level change occurs on an internal trigger before it is considered
        /// as a valid level transition. An internal clock source must be
        /// present to use this feature
        LPTIM1_trgflt_t trgflt : 2;
        uint32_t const  reserved_08 : 1;
        /// Clock prescaler The PRESC bits configure the prescaler division
        /// factor. It can be one among the following division factors:
        LPTIM1_presc_t presc : 3;
        uint32_t const reserved_12 : 1;
        /// Trigger selector The TRIGSEL bits select the trigger source that
        /// will serve as a trigger event for the LPTIM among the below 8
        /// available sources: See for details.
        LPTIM1_trigsel_t trigsel : 3;
        uint32_t const   reserved_16 : 1;
        /// Trigger enable and polarity The TRIGEN bits controls whether the
        /// LPTIM counter is started by an external trigger or not. If the
        /// external trigger option is selected, three configurations are
        /// possible for the trigger active edge:
        LPTIM1_trigen_t trigen : 2;
        /// Timeout enable The TIMOUT bit controls the Timeout feature
        LPTIM1_timout_t timout : 1;
        /// Waveform shape The WAVE bit controls the output shape
        LPTIM1_wave_t wave : 1;
        /// Waveform shape polarity The WAVEPOL bit controls the output polarity
        LPTIM1_wavpol_t wavpol : 1;
        /// Registers update mode The PRELOAD bit controls the LPTIM_ARR and the
        /// LPTIM_CMP registers update modality
        LPTIM1_preload_t preload : 1;
        /// counter mode enabled The COUNTMODE bit selects which clock source is
        /// used by the LPTIM to clock the counter:
        LPTIM1_countmode_t countmode : 1;
        /// Encoder mode enable The ENC bit controls the Encoder mode Note: If
        /// the LPTIM does not support encoder mode feature, this bit is
        /// reserved. Please refer to .
        LPTIM1_enc_t enc : 1;
    };
    uint32_t bits;
} LPTIM1_lptim_cfgr_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_cfgr_t, sizeof(uint32_t));

/**
 * LPTIM enable The ENABLE bit is set and cleared by software.
 */
typedef enum LPTIM1_enable_e {
    /// LPTIM is disabled
    LPTIM1_enable_b_0x0 = 0x0,
    /// LPTIM is enabled
    LPTIM1_enable_b_0x1 = 0x1,
} LPTIM1_enable_t;

/**
 * Control Register
 */
typedef union LPTIM1_lptim_cr_u {
    struct {
        /// LPTIM enable The ENABLE bit is set and cleared by software.
        LPTIM1_enable_t enable : 1;
        /// LPTIM start in Single mode This bit is set by software and cleared
        /// by hardware. In case of software start (TRIGEN[1:0] = '00â),
        /// setting this bit starts the LPTIM in single pulse mode. If the
        /// software start is disabled (TRIGEN[1:0] different than '00â),
        /// setting this bit starts the LPTIM in single pulse mode as soon as an
        /// external trigger is detected. If this bit is set when the LPTIM is
        /// in continuous counting mode, then the LPTIM will stop at the
        /// following match between LPTIM_ARR and LPTIM_CNT registers. This bit
        /// can only be set when the LPTIM is enabled. It will be automatically
        /// reset by hardware.
        uint32_t sngstrt : 1;
        /// Timer start in Continuous mode This bit is set by software and
        /// cleared by hardware. In case of software start (TRIGEN[1:0] =
        /// '00â), setting this bit starts the LPTIM in Continuous mode. If
        /// the software start is disabled (TRIGEN[1:0] different than
        /// '00â), setting this bit starts the timer in Continuous mode as
        /// soon as an external trigger is detected. If this bit is set when a
        /// single pulse mode counting is ongoing, then the timer will not stop
        /// at the next match between the LPTIM_ARR and LPTIM_CNT registers and
        /// the LPTIM counter keeps counting in Continuous mode. This bit can be
        /// set only when the LPTIM is enabled. It will be automatically reset
        /// by hardware.
        uint32_t cntstrt : 1;
        /// Counter reset This bit is set by software and cleared by hardware.
        /// When set to '1' this bit will trigger a synchronous reset of the
        /// LPTIM_CNT counter register. Due to the synchronous nature of this
        /// reset, it only takes place after a synchronization delay of 3
        /// LPTimer core clock cycles (LPTimer core clock may be different from
        /// APB clock). COUNTRST must never be set to '1' by software before it
        /// is already cleared to '0' by hardware. Software should consequently
        /// check that COUNTRST bit is already cleared to '0' before attempting
        /// to set it to '1'.
        uint32_t countrst : 1;
        /// Reset after read enable This bit is set and cleared by software.
        /// When RSTARE is set to '1', any read access to LPTIM_CNT register
        /// will asynchronously reset LPTIM_CNT register content.
        uint32_t rstare : 1;
    };
    uint32_t bits;
} LPTIM1_lptim_cr_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_cr_t, sizeof(uint32_t));

/**
 * Compare Register
 */
typedef union LPTIM1_lptim_cmp_u {
    struct {
        /// Compare value
        uint32_t cmp : 16;
    };
    uint32_t bits;
} LPTIM1_lptim_cmp_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_cmp_t, sizeof(uint32_t));

/**
 * Autoreload Register
 */
typedef union LPTIM1_lptim_arr_u {
    struct {
        /// Auto reload value
        uint32_t arr : 16;
    };
    uint32_t bits;
} LPTIM1_lptim_arr_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_arr_t, sizeof(uint32_t));

/**
 * Counter Register
 */
typedef union LPTIM1_lptim_cnt_u {
    struct {
        /// Counter value
        uint32_t cnt : 16;
    };
    uint32_t bits;
} LPTIM1_lptim_cnt_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_cnt_t, sizeof(uint32_t));

/**
 * LPTIM input 1 selection The IN1SEL bits control the LPTIM Input 1
 * multiplexer, which connects LPTIM Input 1 to one of the available inputs. For
 * connection details refer to .
 */
typedef enum LPTIM1_in1sel_e {
    /// lptim_in1_mux0
    LPTIM1_in1sel_b_0x0 = 0x0,
    /// lptim_in1_mux1
    LPTIM1_in1sel_b_0x1 = 0x1,
    /// lptim_in1_mux2
    LPTIM1_in1sel_b_0x2 = 0x2,
    /// lptim_in1_mux3
    LPTIM1_in1sel_b_0x3 = 0x3,
} LPTIM1_in1sel_t;

/**
 * LPTIM input 2 selection The IN2SEL bits control the LPTIM Input 2
 * multiplexer, which connect LPTIM Input 2 to one of the available inputs. For
 * connection details refer to . Note: If the LPTIM does not support encoder
 * mode feature, these bits are reserved. Please refer to .
 */
typedef enum LPTIM1_in2sel_e {
    /// lptim_in2_mux0
    LPTIM1_in2sel_b_0x0 = 0x0,
    /// lptim_in2_mux1
    LPTIM1_in2sel_b_0x1 = 0x1,
    /// lptim_in2_mux2
    LPTIM1_in2sel_b_0x2 = 0x2,
    /// lptim_in2_mux3
    LPTIM1_in2sel_b_0x3 = 0x3,
} LPTIM1_in2sel_t;

/**
 * LPTIM configuration register 2
 */
typedef union LPTIM1_lptim_cfgr2_u {
    struct {
        /// LPTIM input 1 selection The IN1SEL bits control the LPTIM Input 1
        /// multiplexer, which connects LPTIM Input 1 to one of the available
        /// inputs. For connection details refer to .
        LPTIM1_in1sel_t in1sel : 2;
        uint32_t const  reserved_02 : 2;
        /// LPTIM input 2 selection The IN2SEL bits control the LPTIM Input 2
        /// multiplexer, which connect LPTIM Input 2 to one of the available
        /// inputs. For connection details refer to . Note: If the LPTIM does
        /// not support encoder mode feature, these bits are reserved. Please
        /// refer to .
        LPTIM1_in2sel_t in2sel : 2;
    };
    uint32_t bits;
} LPTIM1_lptim_cfgr2_t;
STATIC_ASSERT_TYPE_SIZE(LPTIM1_lptim_cfgr2_t, sizeof(uint32_t));

/**
 * Low power timer
 */
typedef struct LPTIM1_peripheral_registers_s {
    /// Interrupt and Status Register
    LPTIM1_lptim_isr_t lptim_isr;
    /// Interrupt Clear Register
    LPTIM1_lptim_icr_t lptim_icr;
    /// Interrupt Enable Register
    LPTIM1_lptim_ier_t lptim_ier;
    /// Configuration Register
    LPTIM1_lptim_cfgr_t lptim_cfgr;
    /// Control Register
    LPTIM1_lptim_cr_t lptim_cr;
    /// Compare Register
    LPTIM1_lptim_cmp_t lptim_cmp;
    /// Autoreload Register
    LPTIM1_lptim_arr_t lptim_arr;
    /// Counter Register
    LPTIM1_lptim_cnt_t lptim_cnt;
    uint8_t const      reserved_0x20[4];
    /// LPTIM configuration register 2
    LPTIM1_lptim_cfgr2_t lptim_cfgr2;
} LPTIM1_peripheral_registers_t;
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_isr, 0x00);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_icr, 0x04);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_ier, 0x08);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_cfgr, 0x0C);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_cr, 0x10);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_cmp, 0x14);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_arr, 0x18);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_cnt, 0x1C);
STATIC_ASSERT_MEMBER_OFFSET(LPTIM1_peripheral_registers_t, lptim_cfgr2, 0x24);

#ifdef __cplusplus
}
#endif
#endif // LPTIM1_H_

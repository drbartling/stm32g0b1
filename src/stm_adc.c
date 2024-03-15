#include "stm32g0b1/stm_adc.h"

#include "stm32g0b1/stm32g0b1.h"
#include "timeout_macros.h"

#include <assert.h>
#include <stdbool.h>

static volatile bool ADC_locked;

static void ADC_calibrate(void);
static void ADC_enable_interupts(void);

void
ADC_init(void)
{
    // Enable ADC clock tree
    STM_RCC->apbenr2.adcen = 1;

    STM_ADC1->cr.advregen = 1;

    int volatile hacky_timer = 100 * 1000;
    while (hacky_timer--) {
        // Should wait 20us for ADC regulator to stabilize
        // Wait for ADC voltage to stabilize
    }

    STM_ADC1->cfgr1.chselrmod = 0;

    STM_ADC1->cfgr2.ckmode = ADC_ckmode_pclk_div2;

    STM_ADC1->smpr.smp1 = ADC_smp_19p5_cycles;

    hacky_timer = 100 * 1000;
    while (hacky_timer--) {
    }

    ADC_calibrate();

    STM_ADC1->ccr.vbaten = 1;
    STM_ADC1->ccr.tsen   = 1;
    STM_ADC1->ccr.vrefen = 1;
    STM_ADC1->ccr.presc  = 1;

    ADC_enable_interupts();
    ADC_locked = false;
}

static void
ADC_calibrate(void)
{
    while (ADC_locked) {
    }
    ADC_locked = true;
    if (STM_ADC1->cr.aden) {
        STM_ADC1->cr.addis = 1;
        while (1 == STM_ADC1->cr.addis) {
            // Wait for ADC to shut down
        }
    }

    STM_ADC1->cr.adcal = 1;
    while (0 == STM_ADC1->isr.eocal) {
        // Wait for calibration to complete
    }
    STM_ADC1->isr.eocal = 1;
    ADC_locked          = false;
}

static void
ADC_enable_interupts(void)
{
    // Polling based ADC operation
}

void
ADC_isr(void)
{
}

int16_t
read_adc(ADC_chselr_t const chselr)
{
    int const adc_timout_counter = 100;
    wait_timeout(ADC_locked, adc_timout_counter, -1);
    wait_timeout(STM_ADC1->cr.addis, adc_timout_counter, -2);

    STM_ADC1->chselr.bits = chselr.bits;
    wait_timeout(0 == STM_ADC1->isr.ccrdy, adc_timout_counter, -3);
    STM_ADC1->isr.ccrdy = 0;
    STM_ADC1->smpr.smp1 = ADC_smp_79p5_cycles;

    STM_ADC1->isr.adrdy = 1;
    STM_ADC1->cr.aden   = 1;
    wait_timeout(0 == STM_ADC1->isr.adrdy, adc_timout_counter, -4);

    // Clear ADC interrupt flags by writing 1 to them
    STM_ADC1->isr.eos = 1;
    STM_ADC1->isr.eoc = 1;
    STM_ADC1->isr.ovr = 1;

    STM_ADC1->cr.adstart = 1;

    wait_timeout(0 == STM_ADC1->isr.eoc, adc_timout_counter, -5);
    wait_timeout(0 == STM_ADC1->isr.eos, adc_timout_counter, -6);

    uint16_t result = STM_ADC1->dr.data;
    wait_timeout(1 == STM_ADC1->isr.eoc, adc_timout_counter, -7);
    // clear end of conversion and end of sequence bits by writing 1
    STM_ADC1->isr.eos = 1;

    // STM_ADC1->chselr.bits = 0;
    STM_ADC1->cr.addis = 1;

    return (int16_t)result;
}

bool
ADC_lock(void)
{
    if (ADC_locked) {
        return false;
    }
    ADC_locked = true;
    return true;
}
void
ADC_release(void)
{
    assert(ADC_locked);
    ADC_locked = false;
}

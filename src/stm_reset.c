#include "stm_reset.h"

#include "board_support.h"
#include "stm32g0b1.h"
#include "stm_scb.h"

void
RST_software_reset(void)
{
    ST_aircr_t reset_req;
    reset_req.bits            = SCB_registers->AIRCR.bits;
    reset_req.vectkey         = 0x05FA;
    reset_req.prigroup        = 7;
    reset_req.sysresetreq     = 1;
    SCB_registers->AIRCR.bits = reset_req.bits;

    int volatile i = 0;
    while (1) {
        i++;
        if (i < 10 * 1000) {
            bs_led_enable();
        } else if (i < 100 * 1000) {
            bs_led_disable();
        } else {
            i = 0;
        }
    }
}

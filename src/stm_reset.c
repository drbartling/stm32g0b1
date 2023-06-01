#include "stm32g0b1/stm_reset.h"

#include "stm32g0b1/stm32g0b1.h"
#include "stm32g0b1/stm_scb.h"

#include <stdbool.h>

void
RST_software_reset(void)
{
    ST_aircr_t reset_req;
    reset_req.bits            = SCB_registers->AIRCR.bits;
    reset_req.vectkey         = 0x05FA;
    reset_req.prigroup        = 7;
    reset_req.sysresetreq     = 1;
    SCB_registers->AIRCR.bits = reset_req.bits;

    for (int volatile i = 0; true; ++i) {
    }
}

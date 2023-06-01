#include "stm32g0b1/stm_vrefbuf.h"

#include "stm32g0b1/stm32g0b1.h"

void
VREFBUF_init(void)
{
    STM_RCC->apbenr2.syscfgen = 1;

    STM_VREFBUF->csr.vrs  = 1;
    STM_VREFBUF->csr.hiz  = 0;
    STM_VREFBUF->csr.envr = 1;
    while (0 == STM_VREFBUF->csr.vrr) {
        // Wait for vrefbuf to stabilize
    }
}

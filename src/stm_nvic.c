#include "stm_nvic.h"

NVIC_isr_priority_registers_t;

void
HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority,
                     uint32_t SubPriority)
{
    NVIC_SetPriority(IRQn, PreemptPriority);
}

#ifndef STM_SCB_H_
#define STM_SCB_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef union {
    struct {
        uint32_t reserved_0 : 1;
        uint32_t vectclractive : 1;
        uint32_t sysresetreq : 1;
        uint32_t sysresetreqs : 1;
        uint32_t reserved_4 : 4;
        uint32_t prigroup : 3;
        uint32_t reserved_11 : 2;
        uint32_t bfhfnmins : 1;
        uint32_t pris : 1;
        uint32_t endianess : 1;
        /// Write 0x05FA to vectkey before any write to this register
        uint32_t vectkey : 16;
    };
    uint32_t bits;
} ST_aircr_t;
STATIC_ASSERT_TYPE_SIZE(ST_aircr_t, sizeof(uint32_t));

typedef struct {
    volatile const uint32_t CPUID;
    volatile uint32_t       ICSR;
    volatile uint32_t       VTOR;
    volatile ST_aircr_t     AIRCR;
    volatile uint32_t       SCR;
    volatile uint32_t       CCR;
    volatile uint8_t        SHPR[12U];
    volatile uint32_t       SHCSR;
    volatile uint32_t       CFSR;
    volatile uint32_t       HFSR;
    volatile uint32_t       DFSR;
    volatile uint32_t       MMFAR;
    volatile uint32_t       BFAR;
    volatile uint32_t       AFSR;
    volatile const uint32_t ID_PFR[2U];
    volatile const uint32_t ID_DFR;
    volatile const uint32_t ID_ADR;
    volatile const uint32_t ID_MMFR[4U];
    volatile const uint32_t ID_ISAR[6U];
    volatile const uint32_t CLIDR;
    volatile const uint32_t CTR;
    volatile const uint32_t CCSIDR;
    volatile uint32_t       CSSELR;
    volatile uint32_t       CPACR;
    volatile uint32_t       NSACR;
    uint32_t                RESERVED3[92U];
    volatile uint32_t       STIR;
    uint32_t                RESERVED4[15U];
    volatile const uint32_t MVFR0;
    volatile const uint32_t MVFR1;
    volatile const uint32_t MVFR2;
    uint32_t                RESERVED5[1U];
    volatile uint32_t       ICIALLU;
    uint32_t                RESERVED6[1U];
    volatile uint32_t       ICIMVAU;
    volatile uint32_t       DCIMVAC;
    volatile uint32_t       DCISW;
    volatile uint32_t       DCCMVAU;
    volatile uint32_t       DCCMVAC;
    volatile uint32_t       DCCSW;
    volatile uint32_t       DCCIMVAC;
    volatile uint32_t       DCCISW;
    uint32_t                RESERVED7[6U];
    volatile uint32_t       ITCMCR;
    volatile uint32_t       DTCMCR;
    volatile uint32_t       AHBPCR;
    volatile uint32_t       CACR;
    volatile uint32_t       AHBSCR;
    uint32_t                RESERVED8[1U];
    volatile uint32_t       ABFSR;
} SCB_Type;

#ifdef __cplusplus
}
#endif
#endif // STM_SCB_H_

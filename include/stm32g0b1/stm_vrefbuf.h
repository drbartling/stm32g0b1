#ifndef STM_VREFBUF_H_
#define STM_VREFBUF_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

typedef union {
    struct {
        uint32_t envr : 1;
        uint32_t hiz : 1;
        uint32_t vrs : 1;
        uint32_t vrr : 1;
        uint32_t reserved_4 : 12;
        uint32_t reserved_16 : 16;
    };
    uint32_t bits;
} VREFBUF_csr_t;
STATIC_ASSERT_TYPE_SIZE(VREFBUF_csr_t, sizeof(uint32_t));

typedef struct {
    VREFBUF_csr_t volatile csr;
    uint32_t volatile ccr;
} VREFBUF_peripheral_registers_t;
STATIC_ASSERT_TYPE_SIZE(VREFBUF_peripheral_registers_t, 8);

void VREFBUF_init(void);

#ifdef __cplusplus
}
#endif
#endif // STM_VREFBUF_H_

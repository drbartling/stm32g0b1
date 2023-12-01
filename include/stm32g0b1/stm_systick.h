#ifndef STM_SYSTICK_H_
#define STM_SYSTICK_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef union {
    struct {
        uint32_t enable : 1;
        uint32_t tickint : 1;
        uint32_t clksource : 1;
        uint32_t reserved_3 : 13;
        uint32_t countflag : 1;
        uint32_t reserved_17 : 15;
    };
    uint32_t bits;
} STK_csr_t;
STATIC_ASSERT_TYPE_SIZE(STK_csr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t reload : 24;
        uint32_t reserved_24 : 8;
    };
    uint32_t bits;
} STK_rvr_t;
STATIC_ASSERT_TYPE_SIZE(STK_rvr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t current : 24;
        uint32_t reserved_24 : 8;
    };
    uint32_t bits;
} STK_cvr_t;
STATIC_ASSERT_TYPE_SIZE(STK_cvr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t tenms : 24;
        uint32_t reserved_24 : 6;
        uint32_t skew : 1;
        uint32_t no_ref : 1;
    };
    uint32_t bits;
} STK_calib_t;
STATIC_ASSERT_TYPE_SIZE(STK_calib_t, sizeof(uint32_t));

typedef struct {
    volatile STK_csr_t         STK_CSR;
    volatile STK_rvr_t         STK_RVR;
    volatile STK_cvr_t         STK_CVR;
    volatile const STK_calib_t STK_CALIB;
} SYSTICK_Type;
STATIC_ASSERT_MEMBER_OFFSET(SYSTICK_Type, STK_CSR, 0x00);
STATIC_ASSERT_MEMBER_OFFSET(SYSTICK_Type, STK_RVR, 0x04);
STATIC_ASSERT_MEMBER_OFFSET(SYSTICK_Type, STK_CVR, 0x08);
STATIC_ASSERT_MEMBER_OFFSET(SYSTICK_Type, STK_CALIB, 0x0C);

#ifdef __cplusplus
}
#endif
#endif // STM_SYSTICK_H_

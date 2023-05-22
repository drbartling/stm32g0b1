#ifndef USB_H
#define USB_H
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef union {
    struct {
        uint32_t usbrst : 1;
        uint32_t pdwn : 1;
        uint32_t susprdy : 1;
        uint32_t suspen : 1;
        uint32_t l2res : 1;
        uint32_t l1res : 1;
        uint32_t reserved_6 : 1;
        uint32_t l1reqm : 1;
        uint32_t esofm : 1;
        uint32_t sofm : 1;
        uint32_t rst_dconm : 1;
        uint32_t suspm : 1;
        uint32_t wkupm : 1;
        uint32_t ERRM : 1;
        uint32_t PMAOVRM : 1;
        uint32_t CTRM : 1;
        uint32_t THR512M : 1;
        uint32_t reserved_17_30 : 14;
        uint32_t HOST : 1;
    };
    uint32_t bits;
} stm_usb_cntr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_usb_cntr_reg_t, sizeof(uint32_t));

#ifdef __cplusplus
}
#endif
#endif /* USB_H */

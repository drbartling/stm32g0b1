#ifndef STM_FLASH_H_
#define STM_FLASH_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef enum {
    FLASH_result_success,
} FLASH_result_t;

typedef union {
    struct {
        uint32_t latency : 3;
        uint32_t reserved_3 : 5;
        uint32_t prften : 1;
        uint32_t icen : 1;
        uint32_t reserved_10 : 1;
        uint32_t icrst : 1;
        uint32_t reserved_12 : 4;
        uint32_t empty : 1;
        uint32_t reserved_17 : 1;
        uint32_t dbg_swen : 1;
        uint32_t reserved_19 : 13;
    };
    uint32_t bits;
} FLASH_acr_t;
STATIC_ASSERT_TYPE_SIZE(FLASH_acr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t eop : 1;
        uint32_t operr : 1;
        uint32_t reserved_2 : 1;
        uint32_t progerr : 1;
        uint32_t wrperr : 1;
        uint32_t pgaerr : 1;
        uint32_t sizerr : 1;
        uint32_t pgserr : 1;
        uint32_t misserr : 1;
        uint32_t fasterr : 1;
        uint32_t reserved_10 : 4;
        uint32_t rderr : 1;
        uint32_t optverr : 1;
        uint32_t bsy1 : 1;
        uint32_t bsy2 : 1;
        uint32_t cfgbsy : 1;
        uint32_t reserved_19 : 13;
    };
    uint32_t bits;
} FLASH_sr_t;
STATIC_ASSERT_TYPE_SIZE(FLASH_sr_t, sizeof(uint32_t));

typedef enum {
    FLASH_bker_bank1 = 0,
    FLASH_bker_bank2 = 1,
} FLASH_bker_t;

typedef union {
    struct {
        uint32_t pg : 1;
        uint32_t per : 1;
        uint32_t mer1 : 1;
        uint32_t pnb : 10;
        uint32_t bker : 1;
        uint32_t reserved_14 : 1;
        uint32_t mer2 : 1;
        uint32_t strt : 1;
        uint32_t optstrt : 1;
        uint32_t fstpg : 1;
        uint32_t reserved_19 : 5;
        uint32_t eopie : 1;
        uint32_t errie : 1;
        uint32_t rderrie : 1;
        uint32_t obl_launch : 1;
        uint32_t sec_prot : 1;
        uint32_t sec_prot2 : 1;
        uint32_t optlock : 1;
        uint32_t lock : 1;
    };
    uint32_t bits;
} FLASH_cr_t;
STATIC_ASSERT_TYPE_SIZE(FLASH_cr_t, sizeof(uint32_t));

typedef struct {
    FLASH_acr_t volatile acr;
    uint32_t reserved1;
    uint32_t volatile keyr;
    uint32_t volatile optkeyr;
    FLASH_sr_t volatile sr;
    FLASH_cr_t volatile cr;
    uint32_t volatile eccr;
    uint32_t volatile ecc2r;
    uint32_t volatile optr;
    uint32_t volatile pcrop1asr;
    uint32_t volatile pcrop1aer;
    uint32_t volatile wrp1ar;
    uint32_t volatile wrp1br;
    uint32_t volatile pcrop1bsr;
    uint32_t volatile pcrop1ber;
    uint32_t reserved5[2];
    uint32_t volatile pcrop2asr;
    uint32_t volatile pcrop2aer;
    uint32_t volatile wrp2ar;
    uint32_t volatile wrp2br;
    uint32_t volatile pcrop2bsr;
    uint32_t volatile pcrop2ber;
    uint32_t reserved7[9];
    uint32_t volatile secr;
} FLASH_registers_t;

/**
 * @brief      Writes data to flash without erasing
 *
 *             Flash when erased starts with all bits set.  Without erasing, we
 *             can only clear bits.
 *
 * @param[in]  address  The address
 * @param      data     The data
 * @param[in]  size     The size
 *
 * @return     The flash result.
 */
FLASH_sr_t FLASH_write_data_no_erase(int32_t /*address*/, void const * /*data*/,
                                     int32_t /*size*/);

/**
 * @brief      Unlocks the flash
 *
 *             After reset, write into the FLASH control register (FLASH_CR) is
 *             not allowed so as to protect the Flash memory against possible
 *             unwanted operations due, for example, to electric disturbances.
 */
void FLASH_unlock(void);

FLASH_sr_t FLASH_write_page(int32_t, void const *);
void       FLASH_erase_page(int);
int        FLASH_page_number_from_address(int32_t);
int32_t    FLASH_address_from_page_number(int);
void       FLASH_edit_page(int32_t, void *, int32_t);
void       FLASH_write_row(int32_t, void *);

#ifdef __cplusplus
}
#endif
#endif // STM_FLASH_H_

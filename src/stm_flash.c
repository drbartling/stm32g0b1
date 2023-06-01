#include "stm32g0b1/stm_flash.h"

#include "stm32g0b1/stm32g0b1.h"

#include <stdbool.h>
#include <string.h>

static bool         FLASH_is_busy(void);
static void         FLASH_clear_errors(void);
static bool         FLASH_write_double_word(void *, uint64_t);
static FLASH_bker_t FLASH_bank_from_page(int16_t);

#define FLASH_clear_status (1U)

void
FLASH_edit_page(int32_t address, void *data, int32_t size)
{
    if (0 >= size) {
        return;
    }

    int16_t start_page = FLASH_page_number_from_address(address);
    int16_t end_page   = FLASH_page_number_from_address(address + size - 1);
    if (start_page != end_page) {
        return;
    }

    int32_t page_address = FLASH_address_from_page_number(start_page);
    int32_t offset       = address - page_address;

    uint8_t page_data[STFLASH_PAGE_SIZE] = {0};
    memcpy(page_data, (void *)(uintptr_t)page_address, STFLASH_PAGE_SIZE);
    memcpy(page_data + offset, data, (size_t)size);

    FLASH_erase_page(start_page);
    FLASH_write_data_no_erase(page_address, page_data, STFLASH_PAGE_SIZE);
    // Unable to get fast row programming working.  Leaving this here as notes
    // for now.
    // for (int i = 0; i < 4; i++) {
    //     FLASH_write_row(page_address + 256 * i, page_data + 256 * i);
    // }
}

FLASH_sr_t
FLASH_write_page(int32_t address, void const *data)
{
    if (address % (STFLASH_PAGE_SIZE)) {
        // TODO: Return application error code instead
        return STM_FLASH->sr;
    }

    int16_t page_number = FLASH_page_number_from_address(address);

    FLASH_erase_page(page_number);
    return FLASH_write_data_no_erase(address, data, STFLASH_PAGE_SIZE);
}

int16_t
FLASH_page_number_from_address(int32_t address)
{
    if (STFLASH_BANK1_START <= address && address < STFLASH_BANK1_END) {
        int32_t page = (address - STFLASH_BANK1_START) / (STFLASH_PAGE_SIZE)
                       + STFLASH_BANK1_START_PAGE;
        return (int16_t)page;
    }
    if (STFLASH_BANK2_START <= address && address < STFLASH_BANK2_END) {
        int32_t page = ((address - STFLASH_BANK2_START) / (STFLASH_PAGE_SIZE))
                       + STFLASH_BANK2_START_PAGE;
        return (int16_t)page;
    }
    return -1;
}

int32_t
FLASH_address_from_page_number(int16_t page_number)
{
    if (STFLASH_BANK1_START_PAGE <= page_number
        && page_number < STFLASH_BANK1_END_PAGE) {
        return ((page_number - STFLASH_BANK1_START_PAGE) * (STFLASH_PAGE_SIZE))
               + STFLASH_BANK1_START;
    }
    if (STFLASH_BANK2_START_PAGE <= page_number
        && page_number < STFLASH_BANK2_END_PAGE) {
        return ((page_number - STFLASH_BANK2_START_PAGE) * (STFLASH_PAGE_SIZE))
               + STFLASH_BANK2_START;
    }
    return -1;
}

void
FLASH_erase_page(int16_t page_number)
{
    FLASH_bker_t bank = FLASH_bank_from_page(page_number);
    while (FLASH_is_busy()) {
        // Wait for previous flash operation to complete
    }
    FLASH_clear_errors();
    STM_FLASH->cr.pnb  = page_number & 0x4F;
    STM_FLASH->cr.per  = 1;
    STM_FLASH->cr.bker = bank;
    STM_FLASH->cr.strt = 1;

    while (FLASH_is_busy()) {
        // Wait for previous flash operation to complete
    }
    STM_FLASH->sr.eop = FLASH_clear_status;
    STM_FLASH->cr.per = 0;
}

static FLASH_bker_t
FLASH_bank_from_page(int16_t page)
{
    if (256 > page) {
        return FLASH_bker_bank1;
    }
    return FLASH_bker_bank2;
}

FLASH_sr_t
FLASH_write_data_no_erase(int32_t address, void const *data, int32_t size)
{
    uint64_t const *double_words      = data;
    int32_t         double_word_count = size / (int32_t)sizeof(uint64_t);
    uint64_t       *destination       = (void *)address;
    for (int i = 0; i < double_word_count; i++) {
        if (FLASH_write_double_word(&destination[i], double_words[i])) {
            return STM_FLASH->sr;
        }
    }
    return STM_FLASH->sr;
}

static bool
FLASH_write_double_word(void *address, uint64_t double_word)
{
    uint32_t *src  = (void *)(&double_word);
    uint32_t *dest = address;

    while (FLASH_is_busy()) {
        // Wait for previous flash operation to complete
    }
    FLASH_clear_errors();
    STM_FLASH->cr.pg = 1;

    dest[0] = src[0];
    dest[1] = src[1];

    while (FLASH_is_busy()) {
        // Wait for write operation to complete
    }
    STM_FLASH->sr.eop = FLASH_clear_status;
    STM_FLASH->cr.pg  = 0;
    return STM_FLASH->sr.bits != 0;
}

void
FLASH_write_row(int32_t address, void *data)
{
    int32_t *src   = data;
    int32_t *dest  = (void *)address;
    int32_t  size  = 256;
    int32_t  words = size / (int32_t)sizeof(int32_t);

    while (FLASH_is_busy()) {
        // Wait for previous flash operation to complete
    }
    FLASH_clear_errors();
    STM_FLASH->cr.fstpg = 1;

    for (int i = 0; i < words; i++) {
        dest[i] = src[i];
    }

    while (FLASH_is_busy()) {
        // Wait for previous flash operation to complete
    }
    STM_FLASH->sr.eop   = FLASH_clear_status;
    STM_FLASH->cr.fstpg = 0;
    FLASH_clear_errors();
}

void
FLASH_unlock(void)
{
    if (STM_FLASH->cr.lock) {
        STM_FLASH->keyr = 0x45670123;
        STM_FLASH->keyr = 0XCDEF89AB;
    }
}

static bool
FLASH_is_busy(void)
{
    return STM_FLASH->sr.bsy1 || STM_FLASH->sr.bsy2 || STM_FLASH->sr.cfgbsy;
}

static void
FLASH_clear_errors(void)
{
    FLASH_sr_t clear_errors = {
        .operr   = FLASH_clear_status,
        .progerr = FLASH_clear_status,
        .wrperr  = FLASH_clear_status,
        .pgaerr  = FLASH_clear_status,
        .sizerr  = FLASH_clear_status,
        .pgserr  = FLASH_clear_status,
        .misserr = FLASH_clear_status,
        .fasterr = FLASH_clear_status,
        .rderr   = FLASH_clear_status,
        .optverr = FLASH_clear_status,
    };
    FLASH_sr_t clear_status = {
        .eop = 1,
    };
    STM_FLASH->sr.bits = clear_errors.bits | clear_status.bits;
}

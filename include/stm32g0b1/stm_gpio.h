#ifndef STM_GPIO_H
#define STM_GPIO_H
#ifdef __cplusplus
extern "C" {
#endif

#include "static_assert.h"

#include <stdint.h>

typedef enum {
    stm_gpio_mode_input              = 0b00,
    stm_gpio_mode_output             = 0b01,
    stm_gpio_mode_alternate_function = 0b10,
    stm_gpio_mode_analog             = 0b11,
} stm_gpio_mode_t;

typedef union {
    struct {
        stm_gpio_mode_t pin_0 : 2;
        stm_gpio_mode_t pin_1 : 2;
        stm_gpio_mode_t pin_2 : 2;
        stm_gpio_mode_t pin_3 : 2;
        stm_gpio_mode_t pin_4 : 2;
        stm_gpio_mode_t pin_5 : 2;
        stm_gpio_mode_t pin_6 : 2;
        stm_gpio_mode_t pin_7 : 2;
        stm_gpio_mode_t pin_8 : 2;
        stm_gpio_mode_t pin_9 : 2;
        stm_gpio_mode_t pin_10 : 2;
        stm_gpio_mode_t pin_11 : 2;
        stm_gpio_mode_t pin_12 : 2;
        stm_gpio_mode_t pin_13 : 2;
        stm_gpio_mode_t pin_14 : 2;
        stm_gpio_mode_t pin_15 : 2;
    };
    uint32_t bits;
} stm_gpio_mode_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_mode_reg_t, sizeof(uint32_t));

typedef enum {
    stm_gpio_output_push_pull,
    stm_gpio_output_open_drain,
} stm_gpio_output_t;

typedef union {
    struct {
        stm_gpio_output_t pin_0 : 1;
        stm_gpio_output_t pin_1 : 1;
        stm_gpio_output_t pin_2 : 1;
        stm_gpio_output_t pin_3 : 1;
        stm_gpio_output_t pin_4 : 1;
        stm_gpio_output_t pin_5 : 1;
        stm_gpio_output_t pin_6 : 1;
        stm_gpio_output_t pin_7 : 1;
        stm_gpio_output_t pin_8 : 1;
        stm_gpio_output_t pin_9 : 1;
        stm_gpio_output_t pin_10 : 1;
        stm_gpio_output_t pin_11 : 1;
        stm_gpio_output_t pin_12 : 1;
        stm_gpio_output_t pin_13 : 1;
        stm_gpio_output_t pin_14 : 1;
        stm_gpio_output_t pin_15 : 1;
    };
    uint32_t bits;
} stm_gpio_output_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_output_reg_t, sizeof(uint32_t));

typedef enum {
    stm_gpio_output_speed_vlow,
    stm_gpio_output_speed_low,
    stm_gpio_output_speed_high,
    stm_gpio_output_speed_vhigh,
} stm_gpio_output_speed_t;

typedef union {
    struct {
        stm_gpio_output_speed_t pin_0 : 2;
        stm_gpio_output_speed_t pin_1 : 2;
        stm_gpio_output_speed_t pin_2 : 2;
        stm_gpio_output_speed_t pin_3 : 2;
        stm_gpio_output_speed_t pin_4 : 2;
        stm_gpio_output_speed_t pin_5 : 2;
        stm_gpio_output_speed_t pin_6 : 2;
        stm_gpio_output_speed_t pin_7 : 2;
        stm_gpio_output_speed_t pin_8 : 2;
        stm_gpio_output_speed_t pin_9 : 2;
        stm_gpio_output_speed_t pin_10 : 2;
        stm_gpio_output_speed_t pin_11 : 2;
        stm_gpio_output_speed_t pin_12 : 2;
        stm_gpio_output_speed_t pin_13 : 2;
        stm_gpio_output_speed_t pin_14 : 2;
        stm_gpio_output_speed_t pin_15 : 2;
    };
    uint32_t bits;
} stm_gpio_output_speed_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_output_speed_reg_t, sizeof(uint32_t));

typedef enum {
    stm_gpio_pupd_none,
    stm_gpio_pupd_pull_up,
    stm_gpio_pupd_pull_down,
} stm_gpio_pupd_t;

typedef union {
    struct {
        stm_gpio_pupd_t pin_0 : 2;
        stm_gpio_pupd_t pin_1 : 2;
        stm_gpio_pupd_t pin_2 : 2;
        stm_gpio_pupd_t pin_3 : 2;
        stm_gpio_pupd_t pin_4 : 2;
        stm_gpio_pupd_t pin_5 : 2;
        stm_gpio_pupd_t pin_6 : 2;
        stm_gpio_pupd_t pin_7 : 2;
        stm_gpio_pupd_t pin_8 : 2;
        stm_gpio_pupd_t pin_9 : 2;
        stm_gpio_pupd_t pin_10 : 2;
        stm_gpio_pupd_t pin_11 : 2;
        stm_gpio_pupd_t pin_12 : 2;
        stm_gpio_pupd_t pin_13 : 2;
        stm_gpio_pupd_t pin_14 : 2;
        stm_gpio_pupd_t pin_15 : 2;
    };
    uint32_t bits;
} stm_gpio_pupd_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_pupd_reg_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t pin_0 : 1;
        uint32_t pin_1 : 1;
        uint32_t pin_2 : 1;
        uint32_t pin_3 : 1;
        uint32_t pin_4 : 1;
        uint32_t pin_5 : 1;
        uint32_t pin_6 : 1;
        uint32_t pin_7 : 1;
        uint32_t pin_8 : 1;
        uint32_t pin_9 : 1;
        uint32_t pin_10 : 1;
        uint32_t pin_11 : 1;
        uint32_t pin_12 : 1;
        uint32_t pin_13 : 1;
        uint32_t pin_14 : 1;
        uint32_t pin_15 : 1;
    };
    uint32_t bits;
} stm_gpio_idr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_idr_reg_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t pin_0 : 1;
        uint32_t pin_1 : 1;
        uint32_t pin_2 : 1;
        uint32_t pin_3 : 1;
        uint32_t pin_4 : 1;
        uint32_t pin_5 : 1;
        uint32_t pin_6 : 1;
        uint32_t pin_7 : 1;
        uint32_t pin_8 : 1;
        uint32_t pin_9 : 1;
        uint32_t pin_10 : 1;
        uint32_t pin_11 : 1;
        uint32_t pin_12 : 1;
        uint32_t pin_13 : 1;
        uint32_t pin_14 : 1;
        uint32_t pin_15 : 1;
    };
    uint32_t bits;
} stm_gpio_odr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_odr_reg_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t pin_0 : 1;
        uint32_t pin_1 : 1;
        uint32_t pin_2 : 1;
        uint32_t pin_3 : 1;
        uint32_t pin_4 : 1;
        uint32_t pin_5 : 1;
        uint32_t pin_6 : 1;
        uint32_t pin_7 : 1;
        uint32_t pin_8 : 1;
        uint32_t pin_9 : 1;
        uint32_t pin_10 : 1;
        uint32_t pin_11 : 1;
        uint32_t pin_12 : 1;
        uint32_t pin_13 : 1;
        uint32_t pin_14 : 1;
        uint32_t pin_15 : 1;
        uint32_t br0 : 1;
        uint32_t br1 : 1;
        uint32_t br2 : 1;
        uint32_t br3 : 1;
        uint32_t br4 : 1;
        uint32_t br5 : 1;
        uint32_t br6 : 1;
        uint32_t br7 : 1;
        uint32_t br8 : 1;
        uint32_t br9 : 1;
        uint32_t br10 : 1;
        uint32_t br11 : 1;
        uint32_t br12 : 1;
        uint32_t br13 : 1;
        uint32_t br14 : 1;
        uint32_t br15 : 1;
    };
    uint32_t bits;
} stm_gpio_bsrr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_bsrr_reg_t, sizeof(uint32_t));

typedef enum {
    af0,
    af1,
    af2,
    af3,
    af4,
    af5,
    af6,
    af7,
} stm_gpio_afr_t;

typedef union {
    struct {
        stm_gpio_afr_t pin_0 : 4;
        stm_gpio_afr_t pin_1 : 4;
        stm_gpio_afr_t pin_2 : 4;
        stm_gpio_afr_t pin_3 : 4;
        stm_gpio_afr_t pin_4 : 4;
        stm_gpio_afr_t pin_5 : 4;
        stm_gpio_afr_t pin_6 : 4;
        stm_gpio_afr_t pin_7 : 4;
        stm_gpio_afr_t pin_8 : 4;
        stm_gpio_afr_t pin_9 : 4;
        stm_gpio_afr_t pin_10 : 4;
        stm_gpio_afr_t pin_11 : 4;
        stm_gpio_afr_t pin_12 : 4;
        stm_gpio_afr_t pin_13 : 4;
        stm_gpio_afr_t pin_14 : 4;
        stm_gpio_afr_t pin_15 : 4;
    };
    uint32_t bits[2];
} stm_gpio_afr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_bsrr_reg_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t pin_0 : 1;
        uint32_t pin_1 : 1;
        uint32_t pin_2 : 1;
        uint32_t pin_3 : 1;
        uint32_t pin_4 : 1;
        uint32_t pin_5 : 1;
        uint32_t pin_6 : 1;
        uint32_t pin_7 : 1;
        uint32_t pin_8 : 1;
        uint32_t pin_9 : 1;
        uint32_t pin_10 : 1;
        uint32_t pin_11 : 1;
        uint32_t pin_12 : 1;
        uint32_t pin_13 : 1;
        uint32_t pin_14 : 1;
        uint32_t pin_15 : 1;
    };
    uint32_t bits;
} stm_gpio_brr_reg_t;
STATIC_ASSERT_TYPE_SIZE(stm_gpio_bsrr_reg_t, sizeof(uint32_t));

typedef struct {
    volatile stm_gpio_mode_reg_t         moder;
    volatile stm_gpio_output_reg_t       otyper;
    volatile stm_gpio_output_speed_reg_t ospeedr;
    volatile stm_gpio_pupd_reg_t         pupdr;
    volatile stm_gpio_idr_reg_t          idr;
    volatile stm_gpio_odr_reg_t          odr;
    volatile stm_gpio_bsrr_reg_t         bsrr;
    volatile uint32_t                    lckr;
    volatile stm_gpio_afr_reg_t          afr;
    volatile stm_gpio_brr_reg_t          brr;
} stm_gpio_port_t;

#ifdef __cplusplus
}
#endif
#endif /* end of include guard: STM_GPIO_H */

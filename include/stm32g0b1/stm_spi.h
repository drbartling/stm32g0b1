#ifndef STM_SPI_H_
#define STM_SPI_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "static_assert.h"

#ifdef UTEST
#    define CONST
#else
#    define CONST const
#endif

typedef union {
    struct {
        uint32_t cpha : 1;     /**<Clock phase*/
        uint32_t cpol : 1;     /**<Clock polarity*/
        uint32_t mstr : 1;     /**<Master selection*/
        uint32_t br : 3;       /**<Baud rate control*/
        uint32_t spe : 1;      /**<SPI enable*/
        uint32_t lsbfirst : 1; /**<LSBFIRST:*/
        uint32_t ssi : 1;      /**<Internal slave select*/
        uint32_t ssm : 1;      /**<Software slave management*/
        uint32_t rxonly : 1;   /**<Receive only mode enabled*/
        uint32_t crcl : 1;     /**<CRC length*/
        uint32_t crcnext : 1;  /**<Transmit CRC next*/
        uint32_t crcen : 1;    /**<Hardware CRC calculation enable*/
        uint32_t bidioe : 1;   /**<Output enable in bidirectional mode*/
        uint32_t bidimode : 1; /**<Bidirectional data mode enable*/
    };
    uint32_t bits;
} SPI_cr1_t;
STATIC_ASSERT_TYPE_SIZE(SPI_cr1_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t rxdmaen : 1; /**<Rx buffer DMA enable*/
        uint32_t txdmaen : 1; /**<Tx buffer DMA enable*/
        uint32_t ssoe : 1;    /**<SS output enable*/
        uint32_t nssp : 1;    /**<NSS pulse management*/
        uint32_t frf : 1;     /**<Frame format*/
        uint32_t errie : 1;   /**<Error interrupt enable*/
        uint32_t rxneie : 1;  /**<RX buffer not empty interrupt enable*/
        uint32_t txeie : 1;   /**<Tx buffer empty interrupt enable*/
        uint32_t ds : 4;      /**<Data size*/
        uint32_t frxth : 1;   /**<FIFO reception threshold*/
        uint32_t ldma_rx : 1; /**<Last DMA transfer for reception*/
        uint32_t ldma_tx : 1; /**<Last DMA transfer for transmission*/
    };
    uint32_t bits;
} SPI_cr2_t;
STATIC_ASSERT_TYPE_SIZE(SPI_cr2_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t CONST rxne : 1;   /**<Receive buffer not empty*/
        uint32_t CONST txe : 1;    /**<Transmit buffer empty*/
        uint32_t CONST chside : 1; /**<Channel side*/
        uint32_t CONST udr : 1;    /**<Underrun flag*/
        uint32_t       crcerr : 1; /**<CRC error flag*/
        uint32_t CONST modf : 1;   /**<Mode fault*/
        uint32_t CONST ovr : 1;    /**<Overrun flag*/
        uint32_t CONST bsy : 1;    /**<Busy flag*/
        uint32_t CONST fre : 1;    /**<Frame format error*/
        uint32_t CONST frlvl : 2;  /**<FIFO reception level*/
        uint32_t CONST ftlvl : 2;  /**<FIFO transmission level*/
    };
    uint32_t bits;
} SPI_sr_t;
STATIC_ASSERT_TYPE_SIZE(SPI_sr_t, sizeof(uint32_t));

typedef union {
    uint8_t  dr_8;
    uint16_t dr_16;
    uint32_t bits;
} SPI_dr_t;
STATIC_ASSERT_TYPE_SIZE(SPI_dr_t, sizeof(uint32_t));

typedef struct {
    volatile SPI_cr1_t cr1; /*!< SPI Control register 1 (not used in I2S mode),
                          Address offset: 0x00 */
    volatile SPI_cr2_t cr2; /* !< SPI Control register 2, Address offset: 0x04
                             */
    volatile SPI_sr_t sr; /*!< SPI Status register,      Address offset: 0x08 */
    volatile SPI_dr_t dr; /*!< SPI data register,      Address offset: 0x0C */
    volatile uint32_t crcpr;  /*!< SPI CRC polynomial register (not used in I2S
                              mode),  Address  offset: 0x10 */
    volatile uint32_t rxcrcr; /*!< SPI Rx CRC register (not used in I2S mode),
                             Address offset: 0x14 */
    volatile uint32_t txcrcr; /*!< SPI Tx CRC register (not used in I2S mode),
                             Address offset: 0x18 */
} SPI_peripheral_registers_t;

#ifdef __cplusplus
}
#endif
#endif // STM_SPI_H_

#ifndef STM_USART_H_
#define STM_USART_H_
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

typedef enum {
    USART_cr1_m0_7_bits = 0,
    USART_cr1_m0_8_bits = 1,
    USART_cr1_m0_9_bits = 0,
} USART_cr1_m0_t;

typedef enum {
    USART_cr1_m1_7_bits = 0,
    USART_cr1_m1_8_bits = 0,
    USART_cr1_m1_9_bits = 1,
} USART_cr1_m1_t;

typedef union {
    struct {
        uint32_t       ue : 1;      ///< USART enable
        uint32_t       uesm : 1;    ///< USART enable in low - power mode
        uint32_t       re : 1;      ///< Receiver enable
        uint32_t       te : 1;      ///< Transmitter enable
        uint32_t       idleie : 1;  ///< IDLE interrupt enable
        uint32_t       rxfneie : 1; ///< RXFIFO not empty interrupt enable
        uint32_t       tcie : 1;    ///< Transmission complete  enable
        uint32_t       txfnfie : 1; ///< TXFIFO not full interrupt enable
        uint32_t       peie : 1;    ///< PE interrupt enable
        uint32_t       ps : 1;      ///< Parity selection
        uint32_t       pce : 1;     ///< Parity control enable
        uint32_t       wake : 1;    ///< Receiver wakeup method
        USART_cr1_m0_t m0 : 1;      ///< Word length
        uint32_t       mme : 1;     ///< Mute mode enable
        uint32_t       cmie : 1;    ///< Character match interrupt enable
        uint32_t       over8 : 1;   ///< Oversampling mode
        uint32_t       dedt : 5;    ///< Driver Enable deassertion time
        uint32_t       deat : 5;    ///< Driver Enable assertion time
        uint32_t       rtoie : 1;   ///< Receiver timeout interrupt enable
        uint32_t       eobie : 1;   ///< End of Block interrupt enable
        USART_cr1_m1_t m1 : 1;      ///< Word length
        uint32_t       fifoen : 1;  ///< FIFO mode enable
        uint32_t       txfeie : 1;  ///< TXFIFO empty interrupt enable
        uint32_t       rxffie : 1;  ///< RXFIFO Full interrupt enable
    } fifo_enabled;
    struct {
        uint32_t       ue : 1;          ///< USART enable
        uint32_t       uesm : 1;        ///< USART enable in low - power mode
        uint32_t       re : 1;          ///< Receiver enable
        uint32_t       te : 1;          ///< Transmitter enable
        uint32_t       idleie : 1;      ///< IDLE interrupt enable
        uint32_t       rxneie : 1;      ///< Receive data register not empty
        uint32_t       tcie : 1;        ///< Transmission complete  enable
        uint32_t       txeie : 1;       ///< Transmit data register empty
        uint32_t       peie : 1;        ///< PE interrupt enable
        uint32_t       ps : 1;          ///< Parity selection
        uint32_t       pce : 1;         ///< Parity control enable
        uint32_t       wake : 1;        ///< Receiver wakeup method
        USART_cr1_m0_t m0 : 1;          ///< Word length
        uint32_t       mme : 1;         ///< Mute mode enable
        uint32_t       cmie : 1;        ///< Character match interrupt enable
        uint32_t       over8 : 1;       ///< Oversampling mode
        uint32_t       dedt : 5;        ///< Driver Enable deassertion time
        uint32_t       deat : 5;        ///< Driver Enable assertion time
        uint32_t       rtoie : 1;       ///< Receiver timeout interrupt enable
        uint32_t       eobie : 1;       ///< End of Block interrupt enable
        USART_cr1_m1_t m1 : 1;          ///< Word length
        uint32_t       fifoen : 1;      ///< FIFO mode enable
        uint32_t       reserved_30 : 2; ///< Reserved
    } fifo_disabled;
    uint32_t bits;
} USART_cr1_t;
STATIC_ASSERT_TYPE_SIZE(USART_cr1_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t       slven : 1;      ///< Synchronous Slave mode enable
        uint32_t CONST reserved_1 : 2; ///< must be kept at reset value.
        uint32_t dis_nss : 1;     ///< When the DIS_NSS bit is set, the NSS pin
                                  ///< input is ignored.
        uint32_t addm7 : 1;       ///< 7-bit Address Detection/4-bit Address
                                  ///< Detection
        uint32_t       lbdl : 1;  ///< LIN break detection length
        uint32_t       lbdie : 1; ///< LIN break detection interrupt enable
        uint32_t CONST reserved_7 : 1; ///< must be kept at reset value.
        uint32_t       lbcl : 1;       ///< Last bit clock pulse
        uint32_t       cpha : 1;       ///< Clock phase
        uint32_t       cpol : 1;       ///< Clock polarity
        uint32_t       clken : 1;      ///< Clock enable
        uint32_t       stop : 2;       ///< stop bits
        uint32_t       linen : 1;      ///< LIN mode enable
        uint32_t       swap : 1;       ///< Swap TX/RX pins
        uint32_t       rxinv : 1;      ///< RX pin active level inversion
        uint32_t       txinv : 1;      ///< TX pin active level inversion
        uint32_t       datainv : 1;    ///< Binary data inversion
        uint32_t       msbfirst : 1;   ///< Most significant bit first
        uint32_t       abren : 1;      ///< Auto baud rate enable
        uint32_t       abrmod : 2;     ///< Auto baud rate mode
        uint32_t       rtoen : 1;      ///< Receiver timeout enable
        uint32_t       add : 8;        ///< Address of the USART node
    };
    uint32_t bits;
} USART_cr2_t;
STATIC_ASSERT_TYPE_SIZE(USART_cr2_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t       eie : 1;         ///< Error interrupt enable
        uint32_t       iren : 1;        ///< IrDA mode enable
        uint32_t       irlp : 1;        ///< IrDA low-power
        uint32_t       hdsel : 1;       ///< Half-duplex selection
        uint32_t       nack : 1;        ///< Smartcard NACK enable
        uint32_t       scen : 1;        ///< Smartcard mode enable
        uint32_t       dmar : 1;        ///< DMA enable receiver
        uint32_t       dmat : 1;        ///< DMA enable transmitter
        uint32_t       rtse : 1;        ///< RTS enable
        uint32_t       ctse : 1;        ///< CTS enable
        uint32_t       ctsie : 1;       ///< CTS interrupt enable
        uint32_t       onebit : 1;      ///< One sample bit method enable
        uint32_t       ovrdis : 1;      ///< Overrun Disable
        uint32_t       ddre : 1;        ///< DMA Disable on Reception Error
        uint32_t       dem : 1;         ///< Driver enable mode
        uint32_t       dep : 1;         ///< Driver enable polarity selection
        uint32_t CONST reserved_16 : 1; ///< must be kept at reset value.
        uint32_t       scarcnt : 3;     ///< Smartcard auto-retry count
        uint32_t       wus : 2; ///< Wakeup from low-power mode interrupt
                                ///< flag selection
        uint32_t wufie : 1;     ///< Wakeup from low-power mode interrupt
                                ///< enable
        uint32_t txftie : 1;    ///< TXFIFO threshold interrupt enable
        uint32_t tcbgtie : 1;   ///< Transmission Complete before guard time,
                                ///< interrupt enable
        uint32_t rxftcfg : 3;   ///< Receive FIFO threshold
                                ///< configuration
        uint32_t rxftie : 1;    ///< RXFIFO threshold interrupt enable
        uint32_t txftcfg : 3;   ///< TXFIFO threshold configuration
    };
    uint32_t bits;
} USART_cr3_t;
STATIC_ASSERT_TYPE_SIZE(USART_cr3_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t CONST pe : 1;    ///< Parity error
        uint32_t CONST fe : 1;    ///< Framing error
        uint32_t CONST ne : 1;    ///< Noise detection flag
        uint32_t CONST ore : 1;   ///< Overrun error
        uint32_t CONST idle : 1;  ///< Idle line detected
        uint32_t CONST rxfne : 1; ///< RXFIFO not empty
        uint32_t CONST tc : 1;    ///< Transmission complete
        uint32_t CONST txfnf : 1; ///< TXFIFO not full
        uint32_t CONST lbdf : 1;  ///< LIN break detection flag
        uint32_t CONST ctsif : 1; ///< CTS interrupt flag
        uint32_t CONST cts : 1;   ///< CTS flag
        uint32_t CONST rtof : 1;  ///< Receiver timeout
        uint32_t CONST eobf : 1;  ///< End of block flag
        uint32_t CONST udr : 1;   ///< SPI slave underrun error flag
        uint32_t CONST abre : 1;  ///< Auto baud rate error
        uint32_t CONST abrf : 1;  ///< Auto baud rate flag
        uint32_t CONST busy : 1;  ///< Busy flag
        uint32_t CONST cmf : 1;   ///< Character match flag
        uint32_t CONST sbkf : 1;  ///< Send break flag
        uint32_t CONST rwu : 1;   ///< Receiver wakeup from Mute mode
        uint32_t CONST wuf : 1;   ///< Wakeup from low-power mode flag
        uint32_t CONST teack : 1; ///< Transmit enable acknowledge flag
        uint32_t CONST reack : 1; ///< Receive enable acknowledge flag
        uint32_t CONST txfe : 1;  ///< TXFIFO empty
        uint32_t CONST rxff : 1;  ///< RXFIFO full
        uint32_t CONST tcbgt : 1; ///< Transmission complete before guard time
                                  ///< flag
        uint32_t CONST rxft : 1;  ///< RXFIFO threshold flag
        uint32_t CONST txft : 1;  ///< TXFIFO threshold flag
    } fifo_enabled;
    struct {
        uint32_t CONST pe : 1;    ///< Parity error
        uint32_t CONST fe : 1;    ///< Framing error
        uint32_t CONST ne : 1;    ///< Noise detection flag
        uint32_t CONST ore : 1;   ///< Overrun error
        uint32_t CONST idle : 1;  ///< Idle line detected
        uint32_t CONST rxne : 1;  ///< Read data register not empty
        uint32_t CONST tc : 1;    ///< Transmission complete
        uint32_t CONST txe : 1;   ///< Transmit data register empty
        uint32_t CONST lbdf : 1;  ///< LIN break detection flag
        uint32_t CONST ctsif : 1; ///< CTS interrupt flag
        uint32_t CONST cts : 1;   ///< CTS flag
        uint32_t CONST rtof : 1;  ///< Receiver timeout
        uint32_t CONST eobf : 1;  ///< End of block flag
        uint32_t CONST udr : 1;   ///< SPI slave underrun error flag
        uint32_t CONST abre : 1;  ///< Auto baud rate error
        uint32_t CONST abrf : 1;  ///< Auto baud rate flag
        uint32_t CONST busy : 1;  ///< Busy flag
        uint32_t CONST cmf : 1;   ///< Character match flag
        uint32_t CONST sbkf : 1;  ///< Send break flag
        uint32_t CONST rwu : 1;   ///< Receiver wakeup from Mute mode
        uint32_t CONST wuf : 1;   ///< Wakeup from low-power mode flag
        uint32_t CONST teack : 1; ///< Transmit enable acknowledge flag
        uint32_t CONST reack : 1; ///< Receive enable acknowledge flag
        uint32_t CONST reserved_23 : 2;
        uint32_t CONST tcbgt : 1; ///< Transmission complete before guard time
                                  ///< flag
    } fifo_disabled;
    uint32_t bits;
} USART_isr_t;
STATIC_ASSERT_TYPE_SIZE(USART_isr_t, sizeof(uint32_t));

typedef union {
    struct {
        uint32_t PECF : 1;    ///< Parity error clear flag
        uint32_t FECF : 1;    ///< Framing error clear flag
        uint32_t NECF : 1;    ///< Noise detected clear flag
        uint32_t ORECF : 1;   ///< Overrun error clear flag
        uint32_t IDLECF : 1;  ///< Idle line detected clear flag
        uint32_t TXFECF : 1;  ///< TXFIFO empty clear flag
        uint32_t TCCF : 1;    ///< Transmission complete clear flag
        uint32_t TCBGTCF : 1; ///< Transmission complete before Guard time clear
                              ///< flag
        uint32_t       LBDCF : 1;       ///< LIN break detection clear flag
        uint32_t       CTSCF : 1;       ///< CTS clear flag
        uint32_t CONST reserved_10 : 1; ///< must be kept at reset value.
        uint32_t       RTOCF : 1;       ///< Receiver timeout clear flag
        uint32_t       EOBCF : 1;       ///< End of block clear flag
        uint32_t       UDRCF : 1;       ///< SPI slave underrun clear flag
        uint32_t CONST reserved_14 : 3; ///< must be kept at reset value.
        uint32_t       CMCF : 1;        ///< Character match clear flag
        uint32_t CONST reserved_18 : 2; ///< must be kept at reset value.
        uint32_t       WUCF : 1; ///< Wakeup from low-power mode clear flag
    };
    uint32_t bits;
} USART_icr_t;
STATIC_ASSERT_TYPE_SIZE(USART_icr_t, sizeof(uint32_t));

typedef struct {
    USART_cr1_t volatile cr1;
    USART_cr2_t volatile cr2;
    USART_cr3_t volatile cr3;
    uint32_t volatile brr;
    uint32_t volatile gtpr;
    uint32_t volatile rtor;
    uint32_t volatile rqr;
    USART_isr_t volatile isr;
    USART_icr_t volatile icr;
    uint32_t volatile rdr;
    uint32_t volatile tdr;
    uint32_t volatile presc;
} USART_peripheral_registers_t;

#ifdef __cplusplus
}
#endif
#endif // STM_USART_H_

/*
 * QUTMS_HVBoard_Firmware.c
 *
 * Created: 24/11/2019 11:45:34 AM
 * Author : Zoe Goodward
 */

#ifndef MCP2517_defines_H_
#define MCP2517_defines_H_

// Operation Modes
typedef enum {
	MCP2517_NORMAL_MODE = 0x00,
	MCP2517_SLEEP_MODE = 0x01,
	MCP2517_INTERNAL_LOOPBACK_MODE = 0x02,
	MCP2517_LISTEN_ONLY_MODE = 0x03,
	MCP2517_CONFIGURATION_MODE = 0x04,
	MCP2517_EXTERNAL_LOOPBACK_MODE = 0x05,
	MCP2517_CLASSIC_MODE = 0x06,
	MCP2517_RESTRICTED_MODE = 0x07,
	MCP2517_INVALID_MODE = 0xFF
} MCP2517_OPERATION_MODE;

// Error Codes
typedef enum {
	MCP2517_NO_ERROR = 0x01,
	MCP2517_RAM_ERROR = 0x02,
	MCP2517_MODE_SELECT_ERROR = 0x03,
	MCP2517_MESSAGE_SIZE_ERROR = 0x04
} MCP2517_ERROR_CODE;

// Receive status
typedef enum {
	MCP2517_RX_FIFO_EMPTY_STATUS = 0x00,
	MCP2517_RX_FIFO_NOT_EMPTY_STATUS = 0x01,
	MCP2517_RX_FIFO_GREATER_THAN_HALF_FULL_STATUS = 0x02,
	MCP2517_RX_FIFO_FULL_EVENT = 0x04,
	MCP2517_RX_FIFO_OVERFLOW_STATUS = 0x08,
	MCP2517_RX_FIFO_ALL_STATUS = 0x0F
} MCP2517_RX_FIFO_STATUS;

/// Transmit status
typedef enum {
	MCP2517_TX_FIFO_FULL_STATUS = 0x00,
	MCP2517_TX_FIFO_NOT_FULL_STATUS = 0x01,
	MCP2517_TX_FIFO_LESS_THAN_HALF_FULL_STATUS = 0x02,
	MCP2517_TX_FIFO_EMPTY_STATUS = 0x04,
	MCP2517_TX_FIFO_ATTEMPTS_EXHAUSTED_STATUS = 0x10,
	MCP2517_TX_FIFO_ALL_STATUS = 0x17
} MCP2517_TX_FIFO_STATUS;

// FIFO Channels
typedef enum {
	MCP2517_FIFO_CH0,   // Reserved for TXQ
	MCP2517_FIFO_CH1,
	MCP2517_FIFO_CH2,
	MCP2517_FIFO_CH3,
	MCP2517_FIFO_CH4,
	MCP2517_FIFO_CH5,
	MCP2517_FIFO_CH6,
	MCP2517_FIFO_CH7,
	MCP2517_FIFO_CH8,
	MCP2517_FIFO_CH9,
	MCP2517_FIFO_CH10,
	MCP2517_FIFO_CH11,
	MCP2517_FIFO_CH12,
	MCP2517_FIFO_CH13,
	MCP2517_FIFO_CH14,
	MCP2517_FIFO_CH15,
	MCP2517_FIFO_CH16,
	MCP2517_FIFO_CH17,
	MCP2517_FIFO_CH18,
	MCP2517_FIFO_CH19,
	MCP2517_FIFO_CH20,
	MCP2517_FIFO_CH21,
	MCP2517_FIFO_CH22,
	MCP2517_FIFO_CH23,
	MCP2517_FIFO_CH24,
	MCP2517_FIFO_CH25,
	MCP2517_FIFO_CH26,
	MCP2517_FIFO_CH27,
	MCP2517_FIFO_CH28,
	MCP2517_FIFO_CH29,
	MCP2517_FIFO_CH30,
	MCP2517_FIFO_CH31,
	MCP2517_FIFO_CHANNEL_TOTAL
} MCP2517_FIFO_CHANNEL;

// Channel Filters
typedef enum {
	MCP2517_FILTER0,
	MCP2517_FILTER1,
	MCP2517_FILTER2,
	MCP2517_FILTER3,
	MCP2517_FILTER4,
	MCP2517_FILTER5,
	MCP2517_FILTER6,
	MCP2517_FILTER7,
	MCP2517_FILTER8,
	MCP2517_FILTER9,
	MCP2517_FILTER10,
	MCP2517_FILTER11,
	MCP2517_FILTER12,
	MCP2517_FILTER13,
	MCP2517_FILTER14,
	MCP2517_FILTER15,
	MCP2517_FILTER16,
	MCP2517_FILTER17,
	MCP2517_FILTER18,
	MCP2517_FILTER19,
	MCP2517_FILTER20,
	MCP2517_FILTER21,
	MCP2517_FILTER22,
	MCP2517_FILTER23,
	MCP2517_FILTER24,
	MCP2517_FILTER25,
	MCP2517_FILTER26,
	MCP2517_FILTER27,
	MCP2517_FILTER28,
	MCP2517_FILTER29,
	MCP2517_FILTER30,
	MCP2517_FILTER31,
	MCP2517_FILTER_TOTAL,
} MCP2517_FILTER;


// MCP2517 Message Object ID
typedef struct _MCP2517_MSG_OBJ_ID {
	uint16_t MCP2517_SID : 11;
	uint32_t MCP2517_EID : 18;
	uint8_t MCP2517_SID11 : 1;
	uint8_t MCP2517_unimplemented : 2;
} MCP2517_MSG_OBJ_ID;

// MCP2517 Transmit Message Object Control Bits
typedef struct _MCP2517_TX_MSG_OBJ_CTRL {
	uint8_t MCP2517_DLC : 4;
	uint8_t MCP2517_IDE : 1;
	uint8_t MCP2517_RTR : 1;
	uint8_t MCP2517_BRS : 1;
	uint8_t MCP2517_FDF : 1;
	uint8_t MCP2517_ESI : 1;
	uint8_t MCP2517_SEQ : 7;
	uint32_t MCP2517_unimplemented : 16;
} MCP2517_TX_MSG_OBJ_CTRL;

// MCP2517 Transmit Message Object (TXQ and TX FIFO)
typedef union _MCP2517_TX_MSG_OBJ {
	struct {
		MCP2517_MSG_OBJ_ID MCP2517_id;
		MCP2517_TX_MSG_OBJ_CTRL MCP2517_ctrl;
	} MCP2517_bF;
	uint32_t MCP2517_word[3];
	uint8_t MCP2517_byte[12];
} MCP2517_TX_MSG_OBJ;

typedef struct _MCP2517_RX_MSG_OBJ_CTRL {
	uint8_t MCP2517_DLC : 4;
	uint8_t MCP2517_IDE : 1;
	uint8_t MCP2517_RTR : 1;
	uint8_t MCP2517_BRS : 1;
	uint8_t MCP2517_FDF : 1;
	uint8_t MCP2517_ESI : 1;
	uint8_t MCP2517_unimplemented_1 : 2;
	uint8_t MCP2517_FILTHIT : 5;
	uint32_t MCP2517_unimplemented_2 : 16;
} MCP2517_RX_MSG_OBJ_CTRL;

typedef union _MCP2517_RX_MSG_OBJ {
	struct {
		MCP2517_MSG_OBJ_ID MCP2517_id;
		MCP2517_RX_MSG_OBJ_CTRL MCP2517_ctrl;
	} MCP2517_bF;
	uint32_t MCP2517_word[3];
	uint8_t MCP2517_byte[12];
} MCP2517_RX_MSG_OBJ;

#endif // MCP2517_defines_H
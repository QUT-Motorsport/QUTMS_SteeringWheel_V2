/*****************************************************************************
* @file    firmware/QUTMS_SteeringWheel_Firmware/input.h
* @author  Zoe Goodward
* @version V1.0.0
* @date    2/08/2019 1:20:22 PM
* @brief   This file defines the outputs and inputs of the pins of the MCU
*****************************************************************************/

#ifndef INPUT_H_
#define INPUT_H_

#include <stdbool.h>

/*	Pinout

	RX			PD0
	TX			PD1

*/

#define BIT_VALUE(reg, pin) ((reg>>pin) & 1)

/* SPI */
#define SPI_MOSI	PINB5
#define SPI_MISO	PINB6
#define SPI_SCK		PINB7

/* OLED */
#define OLED_RESET	PINB0
#define OLED_CS		PINB1
#define OLED_DC		PIND3

/* CAN */
#define CAN_CS_PORT	PORTB
#define CAN_CS		PINB3
#define CAN_INT		PINB4

/* SD_CARD */
#define SD_CS		PINB2

/* LEDS */
#define LED_A		PIND6
#define LED_B		PIND7

/* Buttons */
#define BTN_A		PINA5
#define BTN_B		PINA6
#define BTN_C		PINA7

#define POT_A		PINA0
#define POT_B		PINA1

#define LED_A_ON	PORTD |= 0b01000000
#define LED_A_OFF	PORTD &= ~0b01000000
#define LED_B_ON	PORTD |= 0b10000000
#define LED_B_OFF	PORTD &= ~0b10000000

/* Rotary Encoder */
#define ROT_ENC_A	PINA6//!((PINA >> PINA6) & 1 == 1)
#define ROT_ENC_B	PINA7//!((PINA >> PINA6) & 1 == 1)

typedef struct input_state {
    bool left_button;
    bool right_button;
    bool back_button;
    bool select_button;
    double pot1;
    int encoder;
} input_state;

void configure_input();
void read_input(input_state *input);

#endif /* MAIN_H_ */
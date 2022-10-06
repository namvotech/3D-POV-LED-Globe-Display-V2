/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

#include <util/delay.h>
#include "povglobe.h"
#include "ab.h"


void busydelay(uint8_t repeat)
{
	for(uint8_t i = 0; i < repeat; i++){ _delay_ms(20); }
}

void globe_clear( void ){
	for (uint8_t j = 0; j < 80; j++){

		for (uint8_t i = 0; i < 5; i++){
			globe[j][i][0] = 0x00;
			globe[j][i][1] = 0x00;
			globe[j][i][2] = 0x00;
		}
	}
}

static inline void pulse_stor_clock( void )
{
	PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
	PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2));
}

static inline void pulse_shift_clock( void )
{
	PORTA |= (1 << PA1) | (1 << PA2) | (1 << PA3);
	PORTA &= ~((1 << PA1) | (1 << PA2) | (1 << PA3));
}	

void init( void )
{
	/* storage PA1 PA2 PA3 */

	/* shift PB0 PB1 PB2 */

	/* red PA4 blue/green PA5 green/blue PA6 */

	/* outputs */
	DDRA |= (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5) | (1 << PA6);
	DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
	globe_clear();
	/* position detector input edge triggered interrupt */
	EIMSK |= (1 << INT1);
	EICRA |= (1 << ISC11) | (0 << ISC10);

	/* 16 bit timer overflow ISR should work around 10kHz */
	TCCR1B |= (1 << CS10);
	TIMSK1 |= (1 << TOIE1);

	speed_index = 0;
	refresh_rate = 60000;

	sei();
}

/* 
 * this function must take care of the actual wiring of the registers 
 * and leds 
 */
static inline void show_globe( uint8_t globe_index )
{
	for (int8_t i = 4; i > -1; i--){
		for (uint8_t j = 1; j != 0x10; j *= 2){
			if (globe[globe_index][i][0] & j) {
				PORTA &= ~(1 << PA4); 
			} else {
				PORTA |= (1 << PA4);
			}
			if (globe[globe_index][i][1] & j) {
				PORTA &= ~(1 << PA5); 
			} else {
				PORTA |= (1 << PA5); 
			}
			if (globe[globe_index][i][2] & j) {
				PORTA &= ~(1 << PA6);
			} else {
				PORTA |= (1 << PA6);
			}
			pulse_shift_clock();
		}
		for (uint8_t j = 0x10; j != 0x80; j *= 2){

			if (globe[globe_index][i][0] & j) {
				PORTA |= (1 << PA4);
			} else {
				PORTA &= ~(1 << PA4); 
			}
			if (globe[globe_index][i][1] & j) {
				PORTA |= (1 << PA6);
			} else {
				PORTA &= ~(1 << PA6);
			}
			if (globe[globe_index][i][2] & j) {
				PORTA |= (1 << PA5); 
			} else {
				PORTA &= ~(1 << PA5); 
			}
			pulse_shift_clock();
		}

		if (globe[globe_index][i][0] & 0x80) {
			PORTA |= (1 << PA4);
		} else {
			PORTA &= ~(1 << PA4); 
		}
		if (globe[globe_index][i][1] & 0x80) {
			PORTA |= (1 << PA6);
		} else {
			PORTA &= ~(1 << PA6);
		}
		if (globe[globe_index][i][2] & 0x80) {
			PORTA |= (1 << PA5); 
		} else {
			PORTA &= ~(1 << PA5); 
		}
		pulse_shift_clock();
	}
	pulse_stor_clock();
}

/* increments speed index and calls output function */
ISR(TIMER1_OVF_vect)
{
	TCNT1 = refresh_rate;
	uint16_t nonvol_spindex = speed_index;
	if (nonvol_spindex <= 316) {
		if(nonvol_spindex%4 == 0){
			show_globe(nonvol_spindex>>2);
		}
		speed_index++;
	} else if (nonvol_spindex < 1000) { /* prevent overflow (delta in INT1 ISR) */
		speed_index++;
	}
}




/* position 0 detected, reset index */
ISR(INT1_vect)
{
	TCNT1 = 0;
	/* volatile, load once */
	uint16_t index_temp = speed_index;

	uint16_t refresh_temp = refresh_rate;
	/* disable and clear timer interrupt */
	TIMSK1 &= ~(1 << TOIE1);
	TIFR1 |= (1 << TOV1);
	/* adapt refresh rate */
	int16_t delta = 320 - index_temp;

	if((refresh_temp + delta) < 0){
		refresh_temp = 0;
	} else if(refresh_temp < 64000) {	
		refresh_temp += delta;
	} else {
		refresh_temp = 64000; /* prevent overflow */
	}

	refresh_rate = refresh_temp;
	TCNT1 = refresh_temp+50;
	speed_index = 0;
	TIMSK1 |= (1 << TOIE1);
}


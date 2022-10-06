/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _POVGLOBE_H_
#define _POVGLOBE_H_
#include <stdlib.h>
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

#include <util/delay.h>

/* color index for array */
enum led_color { RED=0, GREEN, BLUE };

/* 
 * globe[a][b][c] = d:
 * a: x position in direction of rotation
 * b: line number, 0 is bottom
 * c: color index, red: 0, green: 1, blue: 2
 * d: 8 vertical leds in line as one byte, LSB is bottom
 */

uint8_t globe[80][5][3];


volatile uint16_t speed_index;
volatile uint16_t refresh_rate;



void busydelay(uint8_t repeat);
void globe_clear( void );
void init( void );

#endif

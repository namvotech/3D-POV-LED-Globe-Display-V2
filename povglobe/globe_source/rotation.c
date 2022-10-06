/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include "povglobe.h"
/* rotate one line clockwise */
void globe_rotate_cw(uint8_t line, uint8_t color)
{
        uint8_t tempbyte;
        tempbyte = globe[79][line][color];
        for (int8_t i = 79; i > 0; i--){
                globe[i][line][color] = globe[i-1][line][color];
        }
        globe[0][line][color] = tempbyte;
}
void globe_rotate_ccw(uint8_t line, uint8_t color)
{
        uint8_t tempbyte;
        tempbyte = globe[0][line][color];
        for (uint8_t i = 0; i < 79; i++){
                globe[i][line][color] = globe[i+1][line][color];
        }
        globe[79][line][color] = tempbyte;
}

/* rotate everything, avoid function call */
void globe_rotate_full_cw(uint8_t steps, uint8_t delay)
{
	for(uint8_t i = 0; i < steps; i++){
		for(uint8_t line = 0; line < 5; line++){
        		uint8_t tempred = globe[79][line][RED];
        		uint8_t tempgreen = globe[79][line][GREEN];
        		uint8_t tempblue = globe[79][line][BLUE];
		        
		        for (int8_t i = 79; i > 0; i--){
                		globe[i][line][RED] = globe[i-1][line][RED];
                		globe[i][line][GREEN] = globe[i-1][line][GREEN];
                		globe[i][line][BLUE] = globe[i-1][line][BLUE];
		        }
		        globe[0][line][RED] = tempred;
		        globe[0][line][GREEN] = tempgreen;
		        globe[0][line][BLUE] = tempblue;
		}
		for(uint8_t delaytmp = 0; delaytmp < delay; delaytmp++)
			_delay_ms(1);
	}
}

void globe_rotate_full_ccw(uint8_t steps, uint8_t delay)
{
	for(uint8_t i = 0; i < steps; i++){
		for(uint8_t line = 0; line < 5; line++){
        		uint8_t tempred = globe[0][line][RED];
        		uint8_t tempgreen = globe[0][line][GREEN];
        		uint8_t tempblue = globe[0][line][BLUE];
		        
		        for (int8_t i = 0; i < 79; i++){
                		globe[i][line][RED] = globe[i+1][line][RED];
                		globe[i][line][GREEN] = globe[i+1][line][GREEN];
                		globe[i][line][BLUE] = globe[i+1][line][BLUE];
		        }
		        globe[79][line][RED] = tempred;
		        globe[79][line][GREEN] = tempgreen;
		        globe[79][line][BLUE] = tempblue;
		}
		for(uint8_t delaytmp = 0; delaytmp < delay; delaytmp++)
			_delay_ms(1);
	}
}

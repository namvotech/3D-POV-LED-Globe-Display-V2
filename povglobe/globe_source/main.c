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

#include <util/delay.h>
#include "povglobe.h"
#include "animations.h"
#include "ab.h"
#include "rotation.h"

int main(void)
{
	globe_clear();
	init();
	busydelay(250);
	for (uint8_t j = 0; j < 28; j += 1){
		for (uint8_t i = 0; i < 5; i++){
			globe[j][i][0] = 0xFF;
		}
	}
	for (uint8_t j = 28; j < 56; j += 1){
		for (uint8_t i = 0; i < 5; i++){
			globe[j][i][1] = 0xFF;
		}
	}
	for (uint8_t j = 56; j < 80; j += 1){
		for (uint8_t i = 0; i < 5; i++){
			globe[j][i][2] = 0xFF;
		}
	}
	globe_clear();
	/* test pattern, can be removed */
	globe[0][2][0] = 0xFF;
	globe[79][2][2] = 0xFF;
	busydelay(250);
	busydelay(250);
	while ( 1 ){
		globe_clear();



		globe_clear();
		globe_text_1(0,	" POV",
				"GLOBE",
				"DEMO");

		globe_clear();
		globe_earthalpha();
		
		globe_clear();
		globe_pong();

		globe_clear();
		globe_text_3(	"INTENTIONALLY",
				"LEFT",
				"BLANK");	

		
		globe_clear();
		globe_invaders();
		
		globe_clear();
		globe_rings();
		

		globe_clear();
		globe_nyan();

		globe_clear();
		globe_vumeter();
		

		globe_clear();
		globe_pacman();
		

		globe_clear();
		globe_bluerot();

	
		globe_clear();
		globe_noise();
	
		
		globe_clear();
		globe_bird();
		
		globe_clear();
		globe_noname();


		globe_clear();
		globe_earthmap();

		globe_clear();
		globe_text_2(	"MORE INFO?",
				"  VISIT",
				"LEYANDA.DE");
		
	}
}


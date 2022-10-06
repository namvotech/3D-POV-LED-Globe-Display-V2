/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/pgmspace.h>
#include "povglobe.h"
#include "rotation.h"
#include "animations.h"
#include "ab.h"

/* progmem image definitions */
#include "earthmap.h"
#include "bird.h"
#include "earthalpha.h"
#include "nyan.h"

/* this function should be used to read images from the image converter */
void globe_read_image(const uint8_t* image)
{
	for( uint16_t i = 0; i < 1200; i++ )
		*(&globe[0][0][0]+i) = pgm_read_byte(image++);
}

void globe_earthmap(void)
{
	globe_read_image(earthmap);
	globe_rotate_full_ccw(255, 30);
}

void globe_earthalpha(void)
{
	globe_read_image(earthalpha);
	globe_rotate_full_cw(250, 30);
	globe_rotate_full_cw(100, 30);
}

void globe_bird(void)
{
	globe_read_image(bird);
	globe_rotate_full_ccw(120, 35);
}

void globe_nyan(void)
{
	globe_read_image(nyan);
	globe_rotate_full_cw(30, 0);
	globe_rotate_full_ccw(250, 23);
}

void invader0(uint8_t line, uint8_t offset)
{
        globe[79-offset][line][1] |= 0b00001110;
        globe[78-offset][line][1] |= 0b00011000;
        globe[77-offset][line][1] |= 0b10111110;
        globe[76-offset][line][1] |= 0b01101101;
        globe[75-offset][line][1] |= 0b00111101;
        globe[74-offset][line][1] |= 0b00111100;
        globe[73-offset][line][1] |= 0b00111101;
        globe[72-offset][line][1] |= 0b01101101;
        globe[71-offset][line][1] |= 0b10111110;
        globe[70-offset][line][1] |= 0b00011000;
        globe[69-offset][line][1] |= 0b00001110;
}

void invader1(uint8_t line, uint8_t offset)
{
        globe[79-offset][line][RED] |= 0b00111001;
        globe[78-offset][line][RED] |= 0b01111001;
        globe[77-offset][line][RED] |= 0b01111010;
        globe[76-offset][line][RED] |= 0b01101110;
        globe[75-offset][line][RED] |= 0b11101100;
        globe[74-offset][line][RED] |= 0b11111010;
        globe[73-offset][line][RED] |= 0b11111010;
        globe[72-offset][line][RED] |= 0b11101100;
        globe[71-offset][line][RED] |= 0b01101110;
        globe[70-offset][line][RED] |= 0b01111010;
        globe[69-offset][line][RED] |= 0b01111001;
        globe[68-offset][line][RED] |= 0b00111001;
        globe[79-offset][line][2] |= 0b00111001;
        globe[78-offset][line][2] |= 0b01111001;
        globe[77-offset][line][2] |= 0b01111010;
        globe[76-offset][line][2] |= 0b01101110;
        globe[75-offset][line][2] |= 0b11101100;
        globe[74-offset][line][2] |= 0b11111010;
        globe[73-offset][line][2] |= 0b11111010;
        globe[72-offset][line][2] |= 0b11101100;
        globe[71-offset][line][2] |= 0b01101110;
        globe[70-offset][line][2] |= 0b01111010;
        globe[69-offset][line][2] |= 0b01111001;
        globe[68-offset][line][2] |= 0b00111001;
}

void invader2(uint8_t line, uint8_t offset)
{
        globe[79-offset][line][2] |= 0b00011001;
        globe[78-offset][line][2] |= 0b00111010;
        globe[77-offset][line][2] |= 0b01101101;
        globe[76-offset][line][2] |= 0b11111010;
        globe[75-offset][line][2] |= 0b11111010;
        globe[74-offset][line][2] |= 0b01101101;
        globe[73-offset][line][2] |= 0b00111010;
        globe[72-offset][line][2] |= 0b00011001;
}

void globe_invaders(void)
{
	invader0(3, 0);
	invader0(3, 13);
	invader0(3, 26);
	invader0(3, 39);
	invader1(2, 0);
	invader1(2, 13);
	invader1(2, 26);
	invader1(2, 39);
	invader2(1, 2);
	invader2(1, 15);
	invader2(1, 28);
	invader2(1, 41);
	globe_rotate_full_ccw(30, 40);
	globe_rotate_full_cw(30, 40);
	globe_rotate_full_ccw(30, 40);
	globe_rotate_full_cw(30, 40);
}

/* full size pacman */
void pacman_big(void)
{
	for(uint8_t xpos = 0; xpos < 40; xpos++){
		for (uint8_t line = 0; line < 5; line++){
			globe[xpos][line][RED] = 0xFF;
			globe[xpos][line][GREEN] = 0xFF;
		}
	}
	/* front part line 4 */
	for(uint8_t xpos = 40; xpos <= 46; xpos++){
		globe[xpos][4][RED] = 0xFF;
		globe[xpos][4][GREEN] = 0xFF;
	}
	globe[47][4][RED] = 0b11111110;
	globe[47][4][1] = 0b11111110;
	globe[48][4][RED] = 0b11111110;
	globe[48][4][1] = 0b11111110;
	for(uint8_t xpos = 49; xpos <= 70; xpos++){
		globe[xpos][4][RED] = 0xFF;
		globe[xpos][4][GREEN] = 0xFF;
	}
	globe[71][4][RED] = 0b11111110;
	globe[71][4][1] = 0b11111110;
	globe[72][4][RED] = 0b11111110;
	globe[72][4][1] = 0b11111110;
	for(uint8_t xpos = 73; xpos <= 79; xpos++){
		globe[xpos][4][RED] = 0xFF;
		globe[xpos][4][GREEN] = 0xFF;
	}
	/* line 3 */
	for(uint8_t xpos = 40; xpos <= 42; xpos++){
		globe[xpos][3][RED] = 0xFF;
		globe[xpos][3][GREEN] = 0xFF;
	}
	globe[43][3][RED] = 0b11111110;
	globe[43][3][1] = 0b11111110;
	globe[44][3][RED] = 0b11111110;
	globe[44][3][1] = 0b11111110;
	globe[45][3][RED] = 0b11111100;
	globe[45][3][1] = 0b11111100;
	globe[46][3][RED] = 0b01111100;
	globe[46][3][1] = 0b01111100;
	globe[47][3][RED] = 0b00111000;
	globe[47][3][1] = 0b00111000;
	globe[48][3][RED] = 0b00111000;
	globe[48][3][1] = 0b00111000;
	globe[49][3][RED] = 0b01111000;
	globe[49][3][1] = 0b01111000;
	for(uint8_t xpos = 50; xpos <= 54; xpos++){
		globe[xpos][3][RED] = 0b11110000;
		globe[xpos][3][1] = 0b11110000;
	}
	for(uint8_t xpos = 55; xpos <= 64; xpos++){
		globe[xpos][3][RED] = 0b11100000;
		globe[xpos][3][1] = 0b11100000;
	}
	for(uint8_t xpos = 65; xpos <= 69; xpos++){
		globe[xpos][3][RED] = 0b11110000;
		globe[xpos][3][1] = 0b11110000;
	}
	globe[70][3][RED] = 0b01111000;
	globe[70][3][1] = 0b01111000;
	globe[71][3][RED] = 0b00111000;
	globe[71][3][1] = 0b00111000;
	globe[72][3][RED] = 0b00111000;
	globe[72][3][1] = 0b00111000;
	globe[73][3][RED] = 0b01111100;
	globe[73][3][1] = 0b01111100;
	globe[74][3][RED] = 0b11111100;
	globe[74][3][1] = 0b11111100;
	globe[75][3][RED] = 0b11111110;
	globe[75][3][1] = 0b11111110;
	globe[76][3][RED] = 0b11111110;
	globe[76][3][1] = 0b11111110;
	for(uint8_t xpos = 77; xpos <= 79; xpos++){
		globe[xpos][3][RED] = 0xFF;
		globe[xpos][3][1] = 0xFF;
	}
	/* line 2 */
	globe[40][2][RED] = 0b11100111;
	globe[40][2][1] = 0b11100111;
	globe[41][2][RED] = 0b10000001;
	globe[41][2][1] = 0b10000001;
	globe[78][2][RED] = 0b10000001;
	globe[78][2][1] = 0b10000001;
	globe[79][2][RED] = 0b11100111;
	globe[79][2][1] = 0b11100111;
	/* line 1 */
	for(uint8_t xpos = 40; xpos <= 42; xpos++){
		globe[xpos][1][RED] = 0xFF;
		globe[xpos][1][1] = 0xFF;
	}
	globe[43][1][RED] = 0b01111111;
	globe[43][1][1] = 0b01111111;
	globe[44][1][RED] = 0b01111111;
	globe[44][1][1] = 0b01111111;

	globe[45][1][RED] = 0b00111111;
	globe[45][1][1] = 0b00111111;
	globe[46][1][RED] = 0b00111111;
	globe[46][1][1] = 0b00111111;

	globe[47][1][RED] = 0b00011111;
	globe[47][1][1] = 0b00011111;
	globe[48][1][RED] = 0b00011111;
	globe[48][1][1] = 0b00011111;
	globe[49][1][RED] = 0b00011111;
	globe[49][1][1] = 0b00011111;
	for(uint8_t xpos = 50; xpos <= 54; xpos++){
		globe[xpos][1][RED] = 0b00001111;
		globe[xpos][1][1] = 0b00001111;
	}
	for(uint8_t xpos = 55; xpos <= 64; xpos++){
		globe[xpos][1][RED] = 0b00000111;
		globe[xpos][1][1] = 0b00000111;
	}
	for(uint8_t xpos = 65; xpos <= 69; xpos++){
		globe[xpos][1][RED] = 0b00001111;
		globe[xpos][1][1] = 0b00001111;
	}
	globe[70][1][RED] = 0b00011111;
	globe[70][1][1] = 0b00011111;
	globe[71][1][RED] = 0b00011111;
	globe[71][1][1] = 0b00011111;
	globe[72][1][RED] = 0b00011111;
	globe[72][1][1] = 0b00011111;

	globe[73][1][RED] = 0b00111111;
	globe[73][1][1] = 0b00111111;
	globe[74][1][RED] = 0b00111111;
	globe[74][1][1] = 0b00111111;

	globe[75][1][RED] = 0b01111111;
	globe[75][1][1] = 0b01111111;
	globe[76][1][RED] = 0b01111111;
	globe[76][1][1] = 0b01111111;
	for(uint8_t xpos = 77; xpos <= 79; xpos++){
		globe[xpos][1][RED] = 0xFF;
		globe[xpos][1][1] = 0xFF;
	}
	/* line 0 */
	for(uint8_t xpos = 40; xpos <= 79; xpos++){
		globe[xpos][0][RED] = 0xFF;
		globe[xpos][0][1] = 0xFF;
	}
}

/* pacman state open, moving left */
void pac_open_l(uint8_t offset, uint8_t line)
{
	globe[offset][line][RED] = 0b00111100;
	globe[offset+1][line][RED] = 0b01111110;
	globe[offset+2][line][RED] = 0xFF;
	globe[offset+3][line][RED] = 0b10100111;
	globe[offset+4][line][RED] = 0b11000011;
	globe[offset+5][line][RED] = 0b10000001;
	globe[offset][line][GREEN] = 0b00111100;
	globe[offset+1][line][GREEN] = 0b01111110;
	globe[offset+2][line][GREEN] = 0xFF;
	globe[offset+3][line][GREEN] = 0b10100111;
	globe[offset+4][line][GREEN] = 0b11000011;
	globe[offset+5][line][GREEN] = 0b10000001;
}

/* pacman state open, moving right */
void pac_open_r(uint8_t offset, uint8_t line)
{
	globe[offset+7][line][RED] = 0b00111100;
	globe[offset+6][line][RED] = 0b01111110;
	globe[offset+5][line][RED] = 0xFF;
	globe[offset+4][line][RED] = 0b10100111;
	globe[offset+3][line][RED] = 0b11000011;
	globe[offset+2][line][RED] = 0b10000001;
	globe[offset+7][line][GREEN] = 0b00111100;
	globe[offset+6][line][GREEN] = 0b01111110;
	globe[offset+5][line][GREEN] = 0xFF;
	globe[offset+4][line][GREEN] = 0b10100111;
	globe[offset+3][line][GREEN] = 0b11000011;
	globe[offset+2][line][GREEN] = 0b10000001;
}

/* pacman state closed (eating dot) */
void pac_closed(uint8_t offset, uint8_t line)
{
	globe[offset][line][RED] = 0b00111100;
	globe[offset+1][line][RED] = 0b01111110;
	globe[offset+2][line][RED] = 0xFF;
	globe[offset+3][line][RED] = 0xFF;
	globe[offset+4][line][RED] = 0xFF;
	globe[offset+5][line][RED] = 0xFF;
	globe[offset+6][line][RED] = 0b01111110;
	globe[offset+7][line][RED] = 0b00111100;
	globe[offset][line][GREEN] = 0b00111100;
	globe[offset+1][line][GREEN] = 0b01111110;
	globe[offset+2][line][GREEN] = 0xFF;
	globe[offset+3][line][GREEN] = 0xFF;
	globe[offset+4][line][GREEN] = 0xFF;
	globe[offset+5][line][GREEN] = 0xFF;
	globe[offset+6][line][GREEN] = 0b01111110;
	globe[offset+7][line][GREEN] = 0b00111100;
}
/* pacman remove */
void pac_remove(uint8_t offset, uint8_t line)
{
	for(uint8_t i = offset; i <= offset+7; i++){
		globe[i][line][RED] = 0;
		globe[i][line][GREEN] = 0;
	}
}

void globe_pacman(void)
{
	/* place the dots */
	for(uint8_t i = 0; i < 60; i += 16){
		for(uint8_t line = 1; line <= 3; line++){
			globe[i+10][line][RED] = 0b00011000;
			globe[i+11][line][RED] = 0b00111100;
			globe[i+12][line][RED] = 0b00111100;
			globe[i+13][line][RED] = 0b00011000;
			globe[i+10][line][1] = 0b00011000;
			globe[i+11][line][1] = 0b00111100;
			globe[i+12][line][1] = 0b00111100;
			globe[i+13][line][1] = 0b00011000;
		}
	}
	/* let pacman eat all the dots on 3 lines */
	for(uint8_t i = 0; i <= 64; i += 16){
		pac_open_l(i,3);
		busydelay(8);
		pac_remove(i,3);
		pac_closed(i+8, 3);
		busydelay(8);
		pac_remove(i+8,3);
	}	
	busydelay(8);
	for(int8_t i = 64; i >= 8; i -= 16){
		pac_open_r(i,2);
		busydelay(8);
		pac_remove(i,2);
		pac_closed(i-8, 2);
		busydelay(8);
		pac_remove(i-8,2);
	}	
	busydelay(8);
	for(uint8_t i = 0; i <= 64; i += 16){
		pac_open_l(i,1);
		busydelay(8);
		pac_remove(i,1);
		pac_closed(i+8, 1);
		busydelay(8);
		pac_remove(i+8,1);
	}
	pacman_big();
	globe_rotate_full_cw(100, 10);
}

void globe_bluerot(void)
{
	for(uint8_t xpos = 0; xpos < 20; xpos++){
		for(uint8_t line = 0; line <= 4; line++){
			globe[xpos][line][BLUE] = 0xFF;
			globe[xpos+40][line][BLUE] = 0xFF;
		}	
	}
	globe_rotate_full_ccw(250, 6);
}

void globe_rings(void)
{
	for(uint8_t repeat = 0; repeat < 2; repeat++){
		for (uint8_t line = 0; line < 5; line++){
			for (uint8_t bit = 0; bit < 8; bit++){
				for(uint8_t xpos = 0; xpos < 80; xpos++){
					globe[xpos][line][BLUE] = (1 << bit);
					globe[xpos][4-line][GREEN] = (1 << (7-bit));
				}
				busydelay(2);
			}
			for(uint8_t xpos = 0; xpos < 80; xpos++){
				globe[xpos][line][BLUE] = 0;
				globe[xpos][4-line][GREEN] = 0;
			}
		}
		for (uint8_t line = 0; line < 5; line++){
			for (uint8_t bit = 0; bit < 8; bit++){
				for(uint8_t xpos = 0; xpos < 80; xpos++){
					globe[xpos][line][GREEN] = (1 << bit);
					globe[xpos][4-line][BLUE] = (1 << (7-bit));
				}
				busydelay(2);
			}
			for(uint8_t xpos = 0; xpos < 80; xpos++){
				globe[xpos][line][GREEN] = 0;
				globe[xpos][4-line][BLUE] = 0;
			}
		}
	}
}

void globe_noname(void)
{
	for (uint8_t color = 0; color < 3; color++){
		for(uint8_t xpos = 0; xpos <= 79; xpos++){
			for (uint8_t line = 0; line < 5; line++){
				globe[xpos][line][color] = 0xFF;
			}
			busydelay(1);
		}
		for(uint8_t xpos = 0; xpos <= 79; xpos++){
			for (uint8_t line = 0; line < 5; line++){
				globe[xpos][line][color] = 0;
			}
			busydelay(1);
		}
	}
	for(uint8_t xpos = 0; xpos <= 39; xpos++){
		for (uint8_t line = 0; line < 5; line++){
			globe[xpos][line][RED] = 0xFF;
			globe[xpos][line][GREEN] = 0xFF;
			globe[xpos][line][BLUE] = 0xFF;
		}
		busydelay(1);
	}
	globe_rotate_full_cw(250, 10);
}

void globe_longtext(uint8_t line, uint8_t color, char *string)
{

}

/* one rotating line, selectable color && line */
void globe_text_0(uint8_t line, uint8_t color, uint8_t offset, char *string)
{
	if(color & 0x01)
		globe_string(string, line, offset, RED);
	if(color & 0x02)
		globe_string(string, line, offset, GREEN);
	if(color & 0x04)
		globe_string(string, line, offset, BLUE);

	 for(uint8_t i = 0; i < 120; i++){
		if(color & 0x01)
			globe_rotate_cw(line, RED);
		if(color & 0x02)
			globe_rotate_cw(line, GREEN);
		if(color & 0x04)
			globe_rotate_cw(line, BLUE);
                _delay_ms(30);
        }
	
}

/* 3 lines of text, selectable direction, fixed color set */
void globe_text_1(uint8_t dtn, char *string0, char *string1, char *string2)
{
	globe_string(string2, 1, 0, RED);
	globe_string(string2, 1, 0, GREEN);
	globe_string(string2, 1, 0, BLUE);
	globe_string(string1, 2, 0, BLUE);
	globe_string(string0, 3, 0, RED);
	globe_string(string0, 3, 0, GREEN);
	globe_string(string0, 3, 0, BLUE);
	if (dtn == 0)
		globe_rotate_full_cw(250, 25);
	else
		globe_rotate_full_ccw(250, 25);
		
}

/* 3 lines, middle rotates ccw */
void globe_text_2(char *string0, char *string1, char *string2)
{
	globe_string(string2, 1, 0, BLUE);
	globe_string(string1, 2, 0, RED);
	globe_string(string0, 3, 0, BLUE);
	for(uint8_t i = 0; i < 250; i++){
		globe_rotate_cw(1, BLUE);
		globe_rotate_ccw(2, RED);
		globe_rotate_cw(3, BLUE);
                _delay_ms(35);
        }

}

/* 3 lines, rotating cw with different speed */
void globe_text_3(char *string0, char *string1, char *string2)
{
	globe_string(string2, 1, 0, BLUE);
	globe_string(string1, 2, 0, GREEN);
	globe_string(string0, 3, 0, RED);
	for(uint8_t i = 0; i < 150; i++){
		globe_rotate_cw(1, BLUE);
                _delay_ms(30);
		globe_rotate_cw(1, BLUE);
		globe_rotate_cw(2, GREEN);
                _delay_ms(10);
		globe_rotate_cw(1, BLUE);
		globe_rotate_cw(2, GREEN);
		globe_rotate_cw(3, RED);
                _delay_ms(10);
        }


}

/* places the bars as given in the level array */
void vu_show(uint8_t *levels)
{
	for (uint8_t i = 0; i<25; i++){
		
		globe[i*3+1][1][GREEN] = 0;
		globe[i*3+2][1][GREEN] = 0;

		globe[i*3+1][2][RED] = 0;
		globe[i*3+1][2][GREEN] = 0;
		globe[i*3+2][2][RED] = 0;
		globe[i*3+2][2][GREEN] = 0;

		globe[i*3+1][3][RED] = 0;
		globe[i*3+1][3][GREEN] = 0;
		globe[i*3+2][3][RED] = 0;
		globe[i*3+2][3][GREEN] = 0;

		/* levels 1-6 */
		for (uint8_t j = 1; j <= 6; j++){
			if (levels[i] >= j){
				globe[i*3+1][1][GREEN] |= (1 << (j+1));
				globe[i*3+2][1][GREEN] |= (1 << (j+1));
			}
		}
		/* levels 7 to 12 */
		for (uint8_t j = 7; j <= 12; j++){
			if (levels[i] >= j){
				globe[i*3+1][2][GREEN] |= (1 << (j-7));
				globe[i*3+2][2][GREEN] |= (1 << (j-7));
			}
		}
		/* levels 13 to 14 (yellow)*/
		for (uint8_t j = 13; j <= 14; j++){
			if (levels[i] >= j){
				globe[i*3+1][2][GREEN] |= (1 << (j-7));
				globe[i*3+1][2][RED] |= (1 << (j-7));
				globe[i*3+2][2][GREEN] |= (1 << (j-7));
				globe[i*3+2][2][RED] |= (1 << (j-7));
			}
		}
		/* levels 15 to 17 (yellow)*/
		for (uint8_t j = 15; j <= 17; j++){
			if (levels[i] >= j){
				globe[i*3+1][3][GREEN] |= (1 << (j-15));
				globe[i*3+1][3][RED] |= (1 << (j-15));
				globe[i*3+2][3][GREEN] |= (1 << (j-15));
				globe[i*3+2][3][RED] |= (1 << (j-15));
			}
		}
		/* levels 18 to 20 (red)*/
		for (uint8_t j = 18; j <= 20; j++){
			if (levels[i] >= j){
				globe[i*3+1][3][RED] |= (1 << (j-15));
				globe[i*3+2][3][RED] |= (1 << (j-15));
			}
		}
	}
	_delay_ms(30);
}

/* generates random levels */
void globe_vumeter(void)
{
	uint8_t levels[25]; /* 25 bars */
	for (uint8_t barindex = 0; barindex < 25; barindex++)
		levels[barindex] = 0;
	for (uint8_t xpos = 0; xpos<80; xpos++){
		globe[xpos][0][BLUE] = 0b11000000;
		globe[xpos][4][BLUE] = 0b00000011;
	}
	for(uint8_t cyc = 0; cyc < 250; cyc++){
		uint16_t randval0 = rand(); /* seems like rand() provides just 16 bit */
		uint16_t randval1 = rand();
		uint32_t secrand = randval0 & randval1; /* p=0.25 for bit set */
		for(uint8_t barindex = 0; barindex < 16; barindex++){
			if(secrand & (1 << barindex)){
				if(levels[barindex] <= 16)
					levels[barindex] += 4;
				else
					levels[barindex] = 20;
			} else {
				if(levels[barindex] >= 1)
					levels[barindex] -= 1;
			}
		}
		for(uint8_t barindex = 0; barindex < 9; barindex++){
			if(secrand & (1 << barindex)){
				if(levels[barindex+16] <= 16)
					levels[barindex+16] += 4;
				else
					levels[barindex+16] = 20;
			} else {
				if(levels[barindex+16] >= 1)
					levels[barindex+16] -= 1;
			}
		}
		vu_show(levels);
	}
}

/* some random white patterns */
void globe_noise(void)
{
        for(uint16_t i = 0; i < 200; i++){
                for(uint8_t xpos = 0; xpos < 80; xpos++){
                        uint8_t rand0 = (uint8_t)rand();
                        uint8_t rand1 = (uint8_t)rand();
                        uint8_t rand2 = (uint8_t)rand();
			globe[xpos][0][RED] = rand0;
			globe[xpos][0][GREEN] = rand0;
			globe[xpos][0][BLUE] = rand0;
			globe[xpos][1][RED] = rand1;
			globe[xpos][1][GREEN] = rand1;
			globe[xpos][1][BLUE] = rand1;
			globe[xpos][2][RED] = rand2;
			globe[xpos][2][GREEN] = rand2;
			globe[xpos][2][BLUE] = rand2;
			globe[xpos][3][RED] = rand0;
			globe[xpos][3][GREEN] = rand0;
			globe[xpos][3][BLUE] = rand0;
			globe[xpos][4][RED] = rand1;
			globe[xpos][4][GREEN] = rand1;
			globe[xpos][4][BLUE] = rand1;
                }
        }
}

void move_player_up(uint8_t player, uint8_t *position)
{
	uint8_t xpos;
	(*position)++;
	if(player == 0){
		xpos = 28;
	} else {
		xpos = 51;
	}
	for(int8_t i = 5; i >= 0; i--){
		globe[xpos][3][GREEN] |= ((globe[xpos][3][GREEN] & (1 << i)) << 1); 
		globe[xpos+1][3][GREEN] |= ((globe[xpos+1][3][GREEN] & (1 << i)) << 1);
		globe[xpos][3][GREEN] &= ~(1 << i); 
		globe[xpos+1][3][GREEN] &= ~(1 << i);
	} 
	globe[xpos][3][GREEN] |= ((globe[xpos][2][GREEN] & (1 << 7)) >> 7); 
	globe[xpos+1][3][GREEN] |= ((globe[xpos+1][2][GREEN] & (1 << 7)) >> 7);
	globe[xpos][2][GREEN] &= ~(1 << 7); 
	globe[xpos+1][2][GREEN] &= ~(1 << 7);
	for(int8_t i = 6; i >= 0; i--){
		globe[xpos][2][GREEN] |= ((globe[xpos][2][GREEN] & (1 << i)) << 1); 
		globe[xpos+1][2][GREEN] |= ((globe[xpos+1][2][GREEN] & (1 << i)) << 1);
		globe[xpos][2][GREEN] &= ~(1 << i); 
		globe[xpos+1][2][GREEN] &= ~(1 << i);
	} 
	globe[xpos][2][GREEN] |= ((globe[xpos][1][GREEN] & (1 << 7)) >> 7); 
	globe[xpos+1][2][GREEN] |= ((globe[xpos+1][1][GREEN] & (1 << 7)) >> 7);
	globe[xpos][1][GREEN] &= ~(1 << 7); 
	globe[xpos+1][1][GREEN] &= ~(1 << 7);
	for(int8_t i = 6; i >= 1; i--){
		globe[xpos][1][GREEN] |= ((globe[xpos][1][GREEN] & (1 << i)) << 1); 
		globe[xpos+1][1][GREEN] |= ((globe[xpos+1][1][GREEN] & (1 << i)) << 1);
		globe[xpos][1][GREEN] &= ~(1 << i); 
		globe[xpos+1][1][GREEN] &= ~(1 << i);
	} 
}
void move_player_down(uint8_t player, uint8_t *position)
{
	uint8_t xpos;
	(*position)--;
	if(player == 0){
		xpos = 28;
	} else {
		xpos = 51;
	}
	for(int8_t i = 2; i <= 7; i++){
		globe[xpos][1][GREEN] |= ((globe[xpos][1][GREEN] & (1 << i)) >> 1); 
		globe[xpos+1][1][GREEN] |= ((globe[xpos+1][1][GREEN] & (1 << i)) >> 1);
		globe[xpos][1][GREEN] &= ~(1 << i); 
		globe[xpos+1][1][GREEN] &= ~(1 << i);
	} 
	globe[xpos][1][GREEN] |= ((globe[xpos][2][GREEN] & (1 << 0)) << 7); 
	globe[xpos+1][1][GREEN] |= ((globe[xpos+1][2][GREEN] & (1 << 0)) << 7);
	globe[xpos][2][GREEN] &= ~(1 << 0); 
	globe[xpos+1][2][GREEN] &= ~(1 << 0);
	for(int8_t i = 1; i <= 7; i++){
		globe[xpos][2][GREEN] |= ((globe[xpos][2][GREEN] & (1 << i)) >> 1); 
		globe[xpos+1][2][GREEN] |= ((globe[xpos+1][2][GREEN] & (1 << i)) >> 1);
		globe[xpos][2][GREEN] &= ~(1 << i); 
		globe[xpos+1][2][GREEN] &= ~(1 << i);
	} 
	globe[xpos][2][GREEN] |= ((globe[xpos][3][GREEN] & (1 << 0)) << 7); 
	globe[xpos+1][2][GREEN] |= ((globe[xpos+1][3][GREEN] & (1 << 0)) << 7);
	globe[xpos][3][GREEN] &= ~(1 << 0); 
	globe[xpos+1][3][GREEN] &= ~(1 << 0);
	for(int8_t i = 1; i <= 6; i++){
		globe[xpos][3][GREEN] |= ((globe[xpos][3][GREEN] & (1 << i)) >> 1); 
		globe[xpos+1][3][GREEN] |= ((globe[xpos+1][3][GREEN] & (1 << i)) >> 1);
		globe[xpos][3][GREEN] &= ~(1 << i); 
		globe[xpos+1][3][GREEN] &= ~(1 << i);
	} 
}

/* walls for the ball */
#define XHIGH	49
#define XLOW	30

#define YHIGH	31
#define YLOW	9
/* this function will just move the ball around the field each time called */
void move_ball(uint8_t *ball_x, uint8_t *ball_y, uint8_t *ball_vert, uint8_t *ball_hor)
{
	globe[*ball_x][*ball_y/8][RED] &= ~(1 << *ball_y%8);
	if(*ball_hor){ /* increase xpos case */
		if(*ball_vert){ /* increase ypos case */
			if(*ball_x < XHIGH && *ball_y < YHIGH){ /* move ball */
				(*ball_x)++;
				(*ball_y)++;
			} else if (*ball_x == XHIGH) {
				(*ball_x)--;
				(*ball_hor) = 0; /* change direction */
				if (*ball_y == YHIGH) { /* ball in left upper edge */
					(*ball_vert) = 0;
					(*ball_y)--;
				} else { /* ball on left (highest x is on left side) wall */
					(*ball_y)++;
				}	
			} else { /* ball on upper wall */	
				(*ball_vert) = 0;
				(*ball_x)++;
				(*ball_y)--;
			}	
		} else { /* decrease y pos */
			if(*ball_x < XHIGH && *ball_y > YLOW){ /* move ball */
				(*ball_x)++;
				(*ball_y)--;
			} else if (*ball_x == XHIGH) {
				(*ball_x)--;
				(*ball_hor) = 0; /* change direction */
				if (*ball_y == YLOW) { /* ball in left bottom edge */
					(*ball_vert) = 1;
					(*ball_y)++;
				} else { /* ball on left wall */
					(*ball_y)--;
				}	
			} else { /* ball on bottom wall */	
				(*ball_vert) = 1;
				(*ball_x)++;
				(*ball_y)++;
			}	
		}
	} else { /* decrease xpos case */
		if(*ball_vert){ /* increase ypos case */
			if(*ball_x > XLOW && *ball_y < YHIGH){ /* move ball */
				(*ball_x)--;
				(*ball_y)++;
			} else if (*ball_x == XLOW) {
				(*ball_x)++;
				(*ball_hor) = 1; /* change direction */
				if (*ball_y == YHIGH) { /* ball in right upper edge */
					(*ball_vert) = 0;
					(*ball_y)--;
				} else { /* ball on right wall */
					(*ball_y)++;
				}	
			} else { /* ball on upper wall */	
				(*ball_vert) = 0;
				(*ball_x)--;
				(*ball_y)--;
			}	
		} else { /* decrease y pos */
			if(*ball_x > XLOW && *ball_y > YLOW){ /* move ball */
				(*ball_x)--;
				(*ball_y)--;
			} else if (*ball_x == XLOW) {
				(*ball_x)++;
				(*ball_hor) = 1; /* change direction */
				if (*ball_y == YLOW) { /* ball in right bottom edge */
					(*ball_vert) = 1;
					(*ball_y)++;
				} else { /* ball on right wall */
					(*ball_y)--;
				}	
			} else { /* ball on bottom wall */	
				(*ball_vert) = 1;
				(*ball_x)--;
				(*ball_y)++;
			}	
		}
	}
	globe[*ball_x][*ball_y/8][RED] |= (1 << *ball_y%8);
}

void globe_pong(void)
{
	/* position index is used to compare player and ball position */
	uint8_t pos_left = 9; /* indicates bottom edge of player */
	uint8_t pos_right = 9;
	/* ball x y position, controlled by move_ball */
	uint8_t ball_x = 40;
	uint8_t ball_y = 20;
	/* moving direction of ball, controlled by move_ball */
	uint8_t ball_vert = 0;
	uint8_t ball_hor = 0;

	/* score (fake) */
	globe_string("0:0", 3, 31, BLUE);
	/* generate frame */
	for(uint8_t i = 28; i <= 52; i++){
		globe[i][1][BLUE] = 1;
		globe[i][4][BLUE] = 1;
	}

	/* draw players */
	globe[28][1][GREEN] |= 0b01111110;
	globe[29][1][GREEN] |= 0b01111110;
	globe[51][1][GREEN] |= 0b01111110;
	globe[52][1][GREEN] |= 0b01111110;
	for (uint16_t i = 0; i < 500; i++){
		move_ball(&ball_x, &ball_y, &ball_vert, &ball_hor);
		/* the most sophisticated pong AI ever written */
		/* ball moves left */
		if(ball_hor){
			if(pos_left > ball_y)
				move_player_down(1, &pos_left);
			else if (pos_left < (ball_y-6))
				move_player_up(1, &pos_left); 
		} else { /* ball moves right */
			if(pos_right > ball_y)
				move_player_down(0, &pos_right);
			else if (pos_right < (ball_y-6))
				move_player_up(0, &pos_right); 

		}
		_delay_ms(35);
	}
}

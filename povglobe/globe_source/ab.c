/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include "povglobe.h"
#include <stdlib.h>
#include <inttypes.h>
#include "ab.h"

void globe_string(char *string, uint8_t line, uint8_t offset, uint8_t color)
{
        while(*string){
                globe_char(*string, line, offset, color);
                offset += 6;
                string++;
        }
}

/* char, line (bottom is 0), offset from left end, color index */
void globe_char( char ch, uint8_t line, uint8_t offset, uint8_t color)
{
	switch (ch)
	{
		case '0':
			globe[79-offset][line][color] |= 0b00111110;
			globe[78-offset][line][color] |= 0b01000101;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01010001;
			globe[75-offset][line][color] |= 0b00111110;
			break;
		case '1':
			globe[78-offset][line][color] |= 0b00100001;
			globe[77-offset][line][color] |= 0b01111111;
			globe[76-offset][line][color] |= 0b00000001;
			break;
		case '2':
			globe[79-offset][line][color] |= 0b00100001;
			globe[78-offset][line][color] |= 0b01000011;
			globe[77-offset][line][color] |= 0b01000101;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b00110001;
			break;
		case '3':
			globe[79-offset][line][color] |= 0b01000010;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01010001;
			globe[76-offset][line][color] |= 0b01101001;
			globe[75-offset][line][color] |= 0b01000110;
			break;
		case '4':
			globe[79-offset][line][color] |= 0b00001100;
			globe[78-offset][line][color] |= 0b00010100;
			globe[77-offset][line][color] |= 0b00100100;
			globe[76-offset][line][color] |= 0b01111111;
			globe[75-offset][line][color] |= 0b00000100;
			break;
		case '5':
			globe[79-offset][line][color] |= 0b01110010;
			globe[78-offset][line][color] |= 0b01010001;
			globe[77-offset][line][color] |= 0b01010001;
			globe[76-offset][line][color] |= 0b01010001;
			globe[75-offset][line][color] |= 0b01001110;
			break;
		case '6':
			globe[79-offset][line][color] |= 0b00011110;
			globe[78-offset][line][color] |= 0b00101001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b00000110;
			break;
		case '7':
			globe[79-offset][line][color] |= 0b01000000;
			globe[78-offset][line][color] |= 0b01000111;
			globe[77-offset][line][color] |= 0b01001000;
			globe[76-offset][line][color] |= 0b01010000;
			globe[75-offset][line][color] |= 0b01100000;
			break;
		case '8':
			globe[79-offset][line][color] |= 0b00110110;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b00110110;
			break;
		case '9':
			globe[79-offset][line][color] |= 0b00110000;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001010;
			globe[75-offset][line][color] |= 0b00111100;
			break;
		case '!':
			globe[77-offset][line][color] |= 0b01111001;
			break;
		case ':':
			globe[78-offset][line][color] |= 0b00110110;
			globe[77-offset][line][color] |= 0b00110110;
			break;
		case '.':
			globe[78-offset][line][color] |= 0b00000110;
			globe[77-offset][line][color] |= 0b00000110;
			break;
		case '?':
			globe[79-offset][line][color] |= 0b00100000;
			globe[78-offset][line][color] |= 0b01000000;
			globe[77-offset][line][color] |= 0b01000101;
			globe[76-offset][line][color] |= 0b01001000;
			globe[75-offset][line][color] |= 0b00110000;
			break;
		case '&':
			globe[79-offset][line][color] |= 0b00110110;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01010101;
			globe[76-offset][line][color] |= 0b00100010;
			globe[75-offset][line][color] |= 0b00000101;
			break;
		case 'A':
			globe[79-offset][line][color] |= 0b00111111;
			globe[78-offset][line][color] |= 0b01000100;
			globe[77-offset][line][color] |= 0b01000100;
			globe[76-offset][line][color] |= 0b01000100;
			globe[75-offset][line][color] |= 0b00111111;
			break;
		case 'B':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b00110110;
			break;
		case 'C':
			globe[79-offset][line][color] |= 0b00111110;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01000001;
			globe[76-offset][line][color] |= 0b01000001;
			globe[75-offset][line][color] |= 0b00100010;
			break;
		case 'D':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01000001;
			globe[76-offset][line][color] |= 0b00100010;
			globe[75-offset][line][color] |= 0b00011100;
			break;
		case 'E':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b01000001;
			break;
		case 'F':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01001000;
			globe[77-offset][line][color] |= 0b01001000;
			globe[76-offset][line][color] |= 0b01001000;
			globe[75-offset][line][color] |= 0b01000000;
			break;
		case 'G':
			globe[79-offset][line][color] |= 0b00111110;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b00101111;
			break;
		case 'H':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b00001000;
			globe[77-offset][line][color] |= 0b00001000;
			globe[76-offset][line][color] |= 0b00001000;
			globe[75-offset][line][color] |= 0b01111111;
			break;
		case 'I':
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01111111;
			globe[76-offset][line][color] |= 0b01000001;
			break;
		case 'J':
			globe[79-offset][line][color] |= 0b00000010;
			globe[78-offset][line][color] |= 0b00000001;
			globe[77-offset][line][color] |= 0b01000001;
			globe[76-offset][line][color] |= 0b01111110;
			globe[75-offset][line][color] |= 0b01000000;
			break;
		case 'K':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b00001000;
			globe[77-offset][line][color] |= 0b00010100;
			globe[76-offset][line][color] |= 0b00100010;
			globe[75-offset][line][color] |= 0b01000001;
			break;
		case 'L':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b00000001;
			globe[77-offset][line][color] |= 0b00000001;
			globe[76-offset][line][color] |= 0b00000001;
			globe[75-offset][line][color] |= 0b00000001;
			break;
		case 'M':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b00100000;
			globe[77-offset][line][color] |= 0b00011000;
			globe[76-offset][line][color] |= 0b00100000;
			globe[75-offset][line][color] |= 0b01111111;
			break;
		case 'N':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b00010000;
			globe[77-offset][line][color] |= 0b00001000;
			globe[76-offset][line][color] |= 0b00000100;
			globe[75-offset][line][color] |= 0b01111111;
			break;
		case 'O':
			globe[79-offset][line][color] |= 0b00111110;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01000001;
			globe[76-offset][line][color] |= 0b01000001;
			globe[75-offset][line][color] |= 0b00111110;
			break;
		case 'P':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01001000;
			globe[77-offset][line][color] |= 0b01001000;
			globe[76-offset][line][color] |= 0b01001000;
			globe[75-offset][line][color] |= 0b00110000;
			break;
		case 'Q': 
			globe[79-offset][line][color] |= 0b00111110;
			globe[78-offset][line][color] |= 0b01000001;
			globe[77-offset][line][color] |= 0b01000101;
			globe[76-offset][line][color] |= 0b01000010;
			globe[75-offset][line][color] |= 0b00111101;
			break;
		case 'R':
			globe[79-offset][line][color] |= 0b01111111;
			globe[78-offset][line][color] |= 0b01001000;
			globe[77-offset][line][color] |= 0b01001100;
			globe[76-offset][line][color] |= 0b01001010;
			globe[75-offset][line][color] |= 0b00110001;
			break;
		case 'S':
			globe[79-offset][line][color] |= 0b00110001;
			globe[78-offset][line][color] |= 0b01001001;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01001001;
			globe[75-offset][line][color] |= 0b01000110;
			break;
		case 'T':
			globe[79-offset][line][color] |= 0b01000000;
			globe[78-offset][line][color] |= 0b01000000;
			globe[77-offset][line][color] |= 0b01111111;
			globe[76-offset][line][color] |= 0b01000000;
			globe[75-offset][line][color] |= 0b01000000;
			break;
		case 'U':
			globe[79-offset][line][color] |= 0b01111110;
			globe[78-offset][line][color] |= 0b00000001;
			globe[77-offset][line][color] |= 0b00000001;
			globe[76-offset][line][color] |= 0b00000001;
			globe[75-offset][line][color] |= 0b01111110;
			break;
		case 'V':
			globe[79-offset][line][color] |= 0b01111100;
			globe[78-offset][line][color] |= 0b00000010;
			globe[77-offset][line][color] |= 0b00000001;
			globe[76-offset][line][color] |= 0b00000010;
			globe[75-offset][line][color] |= 0b01111100;
			break;
		case 'W':
			globe[79-offset][line][color] |= 0b01111110;
			globe[78-offset][line][color] |= 0b00000001;
			globe[77-offset][line][color] |= 0b00000110;
			globe[76-offset][line][color] |= 0b00000001;
			globe[75-offset][line][color] |= 0b01111110;
			break;
		case 'X': 
			globe[79-offset][line][color] |= 0b01100011;
			globe[78-offset][line][color] |= 0b00010100;
			globe[77-offset][line][color] |= 0b00001000;
			globe[76-offset][line][color] |= 0b00010100;
			globe[75-offset][line][color] |= 0b01100011;
			break;
		case 'Y':
			globe[79-offset][line][color] |= 0b01110000;
			globe[78-offset][line][color] |= 0b00001000;
			globe[77-offset][line][color] |= 0b00000111;
			globe[76-offset][line][color] |= 0b00001000;
			globe[75-offset][line][color] |= 0b01110000;
			break;
		case 'Z':
			globe[79-offset][line][color] |= 0b01000011;
			globe[78-offset][line][color] |= 0b01000101;
			globe[77-offset][line][color] |= 0b01001001;
			globe[76-offset][line][color] |= 0b01010001;
			globe[75-offset][line][color] |= 0b01100001;
			break;
		default:
			break;
	}
}


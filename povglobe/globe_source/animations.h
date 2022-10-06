/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

#include <inttypes.h>
void invader0(uint8_t line, uint8_t offset);
void invader1(uint8_t line, uint8_t offset);
void invader2(uint8_t line, uint8_t offset);
void globe_noise(void);
void pacman_big(void);
void globe_pacman(void);
void globe_bluerot(void);
void globe_rings(void);
void globe_earthmap(void);
void globe_nyan(void);
void globe_earthalpha(void);
void globe_bird(void);
void globe_noname(void);
void globe_text_0(uint8_t line, uint8_t color, uint8_t offset, char *string);
void globe_text_1(uint8_t, char *, char *, char *);
void globe_text_2(char *, char *, char *);
void globe_text_3(char *, char *, char *);
void globe_invaders(void);
void globe_vumeter(void);
void globe_pong(void);
#endif

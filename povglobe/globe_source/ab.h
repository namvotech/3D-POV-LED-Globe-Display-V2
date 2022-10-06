#ifndef _AB_H_
#define _AB_H_
/*
RGB POV globe v1.0

Copyright (C) 2011 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/
#include <stdlib.h>
#include <inttypes.h>

void globe_string(char *string, uint8_t line, uint8_t offset, uint8_t color);

void globe_char( char ch, uint8_t line, uint8_t offset, uint8_t color);
#endif

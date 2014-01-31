/*
 * Copyright (C) 2009-2012 Chris McClelland
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <makestuff.h>
#include "libdump.h"

void dump(uint32 address, const uint8 *input, uint32 length) {
	uint8 ch;
	char x;
	const uint8 *p;

	if ( length ) {
		printf("         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
		while ( length ) {
			x = 0;
			p = input;
			printf("%08X ", address);
			do {
				ch = *input++;
				printf("%02X ", ch);
				--length;
				x++;
				address++;
			} while ( x < 16 && length );
			while ( x++ < 16 ) {
				printf("   ");
			}
			while ( p < input ) {
				ch = *p++;
				printf("%c", (ch >= 32 && ch <=126) ? ch : '.');
			}
			printf("\n");
		}
	}
}

void dumpSimple(const uint8 *input, uint32 length) {
	while ( length ) {
		printf(" %02X", *input++);
		--length;
	}
	printf("\n");
}

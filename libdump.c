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

static void printAddr16(size_t address) {
	printf("%04X ", (uint32)address);
}
static void printAddr32(size_t address) {
	printf("%08X ", (uint32)address);
}
static void printAddr64(size_t address) {
	printf(PFSZH" ", address);
}
typedef void (*FuncPtr)(size_t address);

void dump(size_t address, const uint8 *input, size_t length) {
	if ( length ) {
		uint8 ch;
		char x;
		const uint8 *p;
		FuncPtr printAddr;
		const size_t nextAddr = address + length;
		const char *spaces;
		#if WORD_LENGTH == 64
			if ( nextAddr >= 0x100000000ULL ) {
				printAddr = printAddr64;
				spaces = "                ";
			} else
		#endif
		if ( nextAddr >= 0x10000 ) {
			printAddr = printAddr32;
			spaces = "        ";
		} else {
			printAddr = printAddr16;
			spaces = "    ";
		}
		printf("%s 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n", spaces);
		while ( length ) {
			x = 0;
			p = input;
			printAddr(address);
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

void dumpSimple(const uint8 *input, size_t length) {
	while ( length ) {
		printf(" %02X", *input++);
		--length;
	}
	printf("\n");
}

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
#ifndef LIBDUMP_H
#define LIBDUMP_H

#include <stddef.h>
#include <makestuff.h>

#ifdef __cplusplus
extern "C" {
#endif
	void dump(size_t address, const uint8 *input, size_t length);
	void dumpSimple(const uint8 *input, size_t length);
#ifdef __cplusplus
}
#endif

#endif

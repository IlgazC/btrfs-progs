/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

#ifndef __STRING_TABLE_H__
#define __STRING_TABLE_H__

#include <stdarg.h>

enum string_table_spacing {
	STRING_TABLE_SPACING_1,
	STRING_TABLE_SPACING_2,
};

struct string_table {
	unsigned int ncols;
	unsigned int nrows;
	enum string_table_spacing spacing;
	char *cells[];
};

struct string_table *table_create(unsigned int columns, unsigned int rows);
__attribute__ ((format (printf, 4, 0)))
char *table_printf(struct string_table *tab, unsigned int column, unsigned int row,
			  const char *fmt, ...);
char *table_vprintf(struct string_table *tab, unsigned int column, unsigned int row,
			  const char *fmt, va_list ap);
void table_dump(struct string_table *tab);
void table_free(struct string_table *tab);

#endif

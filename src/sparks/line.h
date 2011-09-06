/*
 * Copyright (C) 2011 by Thomas Quémard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _SPARKS__LINE__H_
#define _SPARKS__LINE__H_

/**
 * @defgroup line
 * @{
 */

#include "sparks/sparks.h"
typedef enum
{
   NONE, CIRCLE
} sparks_symbol_t;

/**
 * Options for line graphs.
 */
typedef struct
{
   sparks_color_t color; ///< Color of the line
   sparks_color_t symbol_color; ///< Color of the symbols
   double symbol_size; ///< Size of the symbols
   sparks_symbol_t symbol;
   double width; ///< Width of the line
} sparks_line_opt_t;


/**
 * Creates a new set of options for line graphs.
 */
sparks_line_opt_t
sparks_line_opt_new ();

/**
 * Plot a data serie as a line.
 */
void
sparks_draw_line (sparks_t* graph, sparks_data_t* data, unsigned len,
   sparks_line_opt_t opt);

void
sparks_draw_simple_line (sparks_t* graph, sparks_data_t* data, unsigned len);

/**
 * @}
 */
#endif

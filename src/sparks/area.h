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

#ifndef _SPARKS__AREA__H_
#define _SPARKS__AREA__H_


#include "sparks/sparks.h"

/**
 * @defgroup area
 * @{
 */

/**
 * Options for area graphs.
 */
typedef struct
{
   sparks_color_t color; ///< Color of the bars
} sparks_area_opt_t;


/**
 * Plot a data serie as an area.
 */
void
sparks_draw_area (sparks_t* graph, sparks_data_t* data, unsigned int len,
   sparks_area_opt_t opt);

void
sparks_draw_simple_area (sparks_t* graph, sparks_data_t* data,
   unsigned int len);

/**
 * Creates a new set of options for area graphs.
 */
sparks_area_opt_t
sparks_area_opt_new ();

/**
 * @}
 */

#endif

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

#ifndef _SPARKS__H_
#define _SPARKS__H_


#include <cairo.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define SPARKS_DATA_HMIDDLE ((sparks_data_t)63)
#define SPARKS_DATA_MAX ((sparks_data_t)127)
#define SPARKS_DATA_0 ((sparks_data_t)0)
#define SPARKS_DATA_NA ((sparks_data_t)-1)

/**
 * @defgroup Sparks
 * @{
 */

typedef char sparks_data_t;

/**
 * An RGBA color.
 */
typedef struct
{
   double r; ///< Red component (between 0 and 1)
   double g; ///< Green component (between 0 and 1)
   double b; ///< Blue component (between 0 and 1)
   double a; ///< Alpha component (between 0 and 1 ; 1 being completely opaque)
} sparks_color_t;

/**
 * Grid properties.
 */
typedef struct
{
   unsigned int w; ///< Grid width
   unsigned int h; ///< Grid height
   unsigned int x; ///< Grid X position
   unsigned int y; ///< Grid Y position
}  sparks_grid_t;


/**
 * Describes the margins around the grid (between the grid and the borders of the image)
 */
typedef struct
{
   unsigned int top; ///< Top margin
   unsigned int right; ///< Right margin
   unsigned int bottom; ///< Bottom margin
   unsigned int left; ///< Left margin
} sparks_margins_t;

/**
 * The base struct for any graph.
 */
typedef struct
{
   cairo_t* cr; ///< A cairo context
   cairo_surface_t* surface; ///< A cairo surface
   unsigned int width; ///< Width of the graph
   unsigned int height; ///< Height of the graph
   unsigned int data_length; ///< The maximum length of the data ploted
   sparks_color_t bg_color; ///< Background color
   sparks_margins_t margins; ///< Margins around the grid
} sparks_t;


/**
 * Creates a new sparks_t struct
 * @param width The width of the graph image
 * @param height The height of the graph image
 */
sparks_t
sparks_new (unsigned int width, unsigned int height);

/**
 * Creates a new sparks_color_t from three RGB components.
 */
sparks_color_t
sparks_get_rgb_color (double r, double g, double b);

/**
 * Cleans a sparks_t struct.
 *
 * @param graph A pointer to the sparks_t to clean.
 */
void
sparks_clean (sparks_t* graph);

/**
 * Draws the background of a plot.
 */
void
sparks_draw_bg (sparks_t* graph, double r, double g, double b);

void
sparks_draw_borders (sparks_t* graph, double size, double r, double g, double b);

sparks_grid_t
sparks_grid_new (sparks_t* graph);

/**
 * Sets the maximum length of the data series being plotted.
 */
void
sparks_set_data_length (sparks_t* graph, unsigned int len);

/**
 * Sets a margin around the grid.
 */
void
sparks_set_margin (sparks_t* graph, unsigned int margin);

/**
 * Writes the plot to a PNG file.
 */
void
sparks_save_png (sparks_t* graph, char* file_path);

/**
 * @}
 */
#endif

#include "sparks/sparks.h"


sparks_t
sparks_new (unsigned int width, unsigned int height)
{
   sparks_t graph = {
      .surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, (int)width, (int)height),
      .cr = NULL,
      .width = width,
      .height = height,
      .data_length = 0,
      .bg_color = sparks_get_rgb_color(1, 1, 1),
      .margins = {.top = 0, .right=0, .bottom=0, .left=0}
   };
   graph.cr = cairo_create (graph.surface);
   return graph;
}

void
sparks_clean (sparks_t* graph)
{
   cairo_destroy(graph->cr);
}

void
sparks_draw_bg (sparks_t* graph, double r, double g, double b)
{
   graph->bg_color.r = r;
   graph->bg_color.g = g;
   graph->bg_color.b = b;
   cairo_set_source_rgba(graph->cr, r, g, b, 1);
   cairo_rectangle(graph->cr, 0, 0, (double)graph->width, (double)graph->height);
   cairo_fill(graph->cr);
}

void
sparks_draw_borders (sparks_t* graph, double size, double r, double g, double b)
{
   cairo_set_source_rgba(graph->cr, r, g, b, 1);
   cairo_set_line_width(graph->cr, size);
   cairo_set_line_join(graph->cr, CAIRO_LINE_JOIN_MITER);
   cairo_rectangle(graph->cr, 0, 0, (double)graph->width, (double)graph->height);
   cairo_stroke(graph->cr);
}

sparks_color_t
sparks_get_rgb_color (double r, double g, double b)
{
   sparks_color_t color = {
      .r = r,
      .g = g,
      .b = b,
      .a = 1
   };
   return color;
}

void
sparks_set_data_length (sparks_t* graph,  unsigned int len)
{
   graph->data_length = len;
}

void
sparks_set_margin (sparks_t* graph, unsigned int margin)
{
   graph->margins.top = margin;
   graph->margins.right = margin;
   graph->margins.bottom = margin;
   graph->margins.left = margin;
}

sparks_grid_t
sparks_grid_new (sparks_t* graph)
{
   sparks_grid_t grid = {
      .y = graph->margins.top,
      .x = graph->margins.left,
      .w = graph->width - graph->margins.left - graph->margins.right,
      .h = graph->height - graph->margins.top - graph->margins.bottom
   };
   return grid;
}

void
sparks_save_png (sparks_t* graph, char* file_path)
{
   (void)cairo_surface_write_to_png(graph->surface, file_path);
}

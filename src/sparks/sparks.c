#include "sparks/sparks.h"


sparks_t
sparks_new (int width, int height)
{
   sparks_t graph;
   graph.surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
   graph.cr = cairo_create (graph.surface);
   graph.width = width;
   graph.height = height;
   graph.data_length = 0;
   sparks_set_margin(&graph, 0);
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
   cairo_rectangle(graph->cr, 0, 0, graph->width, graph->height);
   cairo_fill(graph->cr);
}

void
sparks_draw_borders (sparks_t* graph, double size, double r, double g, double b)
{
   cairo_set_source_rgba(graph->cr, r, g, b, 1);
   cairo_set_line_width(graph->cr, size);
   cairo_set_line_join(graph->cr, CAIRO_LINE_JOIN_MITER);

   // FIXME For some reason, cairo_rectangle draws some strange lines
   // Actually, maybe not... Something's wrong here.
   cairo_move_to (graph->cr, 0, 0);
   cairo_rel_line_to (graph->cr, graph->width, 0);
   cairo_rel_line_to (graph->cr, 0, graph->height);
   cairo_rel_line_to (graph->cr, -graph->width, 0);
   cairo_close_path (graph->cr);

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
sparks_draw_fill (sparks_t* graph, unsigned char* data, unsigned int data_length)
{
   const unsigned int grid_y = graph->margins.top;
   const unsigned int grid_w = graph->width - graph->margins.left - graph->margins.right;
   const unsigned int grid_h = graph->height - graph->margins.top - graph->margins.bottom;

   unsigned char* d = data;
   const unsigned char* d_max = d + data_length - 1;
   unsigned int x = graph->margins.left;
   const unsigned int x_step = grid_w / (graph->data_length-1);
   unsigned int y = 0;

   cairo_move_to(graph->cr, x, graph->height - graph->margins.bottom);
   while (d <= d_max)
   {
      y = grid_y + grid_h - (grid_h * (*d) / 256);
      cairo_line_to(graph->cr, x, y);
      x += x_step;
      ++d;
   }
   cairo_line_to(graph->cr, x-x_step, graph->height - graph->margins.bottom);
   cairo_close_path(graph->cr);

   cairo_set_source_rgb(graph->cr, 0.9, 0.9, 0.9);
   cairo_fill(graph->cr);

}

void
sparks_save_png (sparks_t* graph, char* file_path)
{
   cairo_surface_write_to_png(graph->surface, file_path);
}

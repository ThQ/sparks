#include "sparks/line.h"


sparks_line_opt_t
sparks_line_opt_new ()
{
   sparks_line_opt_t opt = {
      .color = {.r=0.2, .g=0.27, .b=0.84, .a=1},
      .symbol_size = 2,
      .symbol_color = {.r=0.2, .g=0.27, .b=0.84},
      .symbol = CIRCLE,
      .width = 1.4
   };
   return opt;
}

void
sparks_draw_line (sparks_t* graph, sparks_data_t* data, unsigned int data_len,
   sparks_line_opt_t opt)
{
   const unsigned int grid_y = graph->margins.top;
   const unsigned int grid_w = graph->width - graph->margins.left - graph->margins.right;
   const unsigned int grid_h = graph->height - graph->margins.top - graph->margins.bottom;

   sparks_data_t* d = data;
   const sparks_data_t* d_max = d + data_len;
   unsigned int x = graph->margins.left;
   const unsigned int x_step = grid_w / (graph->data_length-1);
   unsigned int y = 0;
   unsigned char begin_new_line = 1;

   cairo_set_line_width(graph->cr, opt.width);
   cairo_set_source_rgba(graph->cr, opt.color.r, opt.color.g, opt.color.b,
      opt.color.a);

   while (d++ < d_max)
   {
      if (*d >= 0)
      {
         y = grid_y + grid_h - (grid_h * (*d) / 127);
         if (begin_new_line == 1)
         {
            cairo_move_to(graph->cr, x, y);
         }
         else
         {
            cairo_line_to(graph->cr, x, y);
         }
         x += x_step;
         begin_new_line = 0;
      }
      else
      {
         cairo_stroke(graph->cr);
         begin_new_line = 1;
      }
   }
   cairo_stroke(graph->cr);

   cairo_arc(graph->cr, x-x_step, y, opt.symbol_size, 0, 2 * M_PI);
   cairo_fill(graph->cr);
}

void
sparks_draw_simple_line (sparks_t* graph, sparks_data_t* data, unsigned int len)
{
   sparks_draw_line(graph, data, len, sparks_line_opt_new());
}

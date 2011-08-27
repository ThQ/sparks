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
   sparks_grid_t grid = sparks_grid_new(graph);

   sparks_data_t* d = data;
   const sparks_data_t* d_max = d + data_len - 1;
   double x = (double)graph->margins.left;
   const double x_step = (double)grid.w / graph->data_length;
   double y = (double)0;
   bool begin_new_line = true;

   cairo_set_line_width(graph->cr, opt.width);
   cairo_set_source_rgba(graph->cr, opt.color.r, opt.color.g, opt.color.b,
      opt.color.a);

   while (d++ < d_max)
   {
      if (*d >= SPARKS_DATA_0)
      {
         y = (double)grid.y + grid.h - (grid.h * (int)(*d) / 127);
         if (begin_new_line)
         {
            cairo_move_to(graph->cr, x, y);
         }
         else
         {
            cairo_line_to(graph->cr, x, y);
         }
         x += x_step;
         begin_new_line = false;
      }
      else
      {
         cairo_stroke(graph->cr);
         begin_new_line = true;
      }
   }
   cairo_stroke(graph->cr);
}

void
sparks_draw_simple_line (sparks_t* graph, sparks_data_t* data, unsigned int len)
{
   sparks_draw_line(graph, data, len, sparks_line_opt_new());
}

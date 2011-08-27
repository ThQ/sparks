#include "sparks/bars.h"

void
sparks_draw_bars (sparks_t* graph, sparks_data_t* data, unsigned int data_len,
   sparks_bars_opt_t opt)
{
   sparks_grid_t grid = sparks_grid_new(graph);
   double x = (double)graph->margins.left;
   const double x_step = (double)grid.w / (graph->data_length);
   const double bar_width = (double)x_step - opt.spacing;
   const double grid_bottom_y = (double)grid.y + grid.h;
   sparks_data_t* d = data;
   const sparks_data_t* d_max = d + data_len - 1;
   double bar_h = 0;

   cairo_set_source_rgba(graph->cr, opt.color.r, opt.color.g, opt.color.b,
      opt.color.a);
   while (d++ < d_max)
   {
      if (*d >= SPARKS_DATA_0)
      {
         bar_h = (double)grid.h * (int)(*d) / 127;
         cairo_rectangle(graph->cr, x, grid_bottom_y - bar_h, bar_width, bar_h);
         cairo_fill(graph->cr);
      }
      x += x_step;
   }
}

void
sparks_draw_simple_bars (sparks_t* graph, sparks_data_t* data, unsigned int len)
{
   sparks_draw_bars(graph, data, len, sparks_bars_opt_new());
}

sparks_bars_opt_t
sparks_bars_opt_new ()
{
   sparks_bars_opt_t opt = {
      .color = {.r=0.2, .g=0.27, .b=0.84, .a=1},
      .spacing = 1
   };
   return opt;
}

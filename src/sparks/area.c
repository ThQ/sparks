#include "sparks/area.h"


void
sparks_draw_area (sparks_t* graph, sparks_data_t* data, unsigned int data_len,
   sparks_area_opt_t opt)
{
   sparks_grid_t grid = sparks_grid_new(graph);
   sparks_data_t* d = data;
   const sparks_data_t* d_max = d + data_len - 1;
   float x = graph->margins.left;
   const float x_step = (float)grid.w / graph->data_length;
   unsigned int y = 0;
   unsigned char begin_new_area = 1;

   cairo_set_source_rgba(graph->cr, opt.color.r, opt.color.g, opt.color.b,
      opt.color.a);

   while (d++ <= d_max)
   {
      y = grid.y + grid.h - (grid.h * (*d) / 127);
      if (*d >= 0)
      {
         if (begin_new_area == 1)
         {
            if (d != data)
            {
               cairo_line_to(graph->cr, x-2*x_step, graph->height - graph->margins.bottom);
               cairo_close_path(graph->cr);
            }
            cairo_move_to(graph->cr, x, graph->height - graph->margins.bottom);
            cairo_line_to(graph->cr, x, y);
            begin_new_area = 0;
         }
         else
         {
            cairo_line_to(graph->cr, x, y);
         }
      }
      else
      {
         begin_new_area = 1;
      }
      x += x_step;
   }
   cairo_line_to(graph->cr, x-x_step, graph->height - graph->margins.bottom);
   cairo_close_path(graph->cr);

   cairo_fill(graph->cr);

}

void
sparks_draw_simple_area (sparks_t* graph, sparks_data_t* data, unsigned int len)
{
   sparks_draw_area(graph, data, len, sparks_area_opt_new());
}

sparks_area_opt_t
sparks_area_opt_new ()
{
   sparks_area_opt_t opt = {
      .color = {.r=0.2, .g=0.27, .b=0.84, .a=1},
   };
   return opt;
}

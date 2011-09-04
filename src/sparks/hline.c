#include "sparks/hline.h"


sparks_hline_opt_t
sparks_hline_opt_new ()
{
   sparks_hline_opt_t opt = {
      .color = {.r=0.8, .g=0.8, .b=0.8, .a=1},
      .width = 1.4
   };
   return opt;
}


void
sparks_draw_hline (sparks_t* graph, sparks_data_t data,
   sparks_hline_opt_t opt)
{
   sparks_grid_t grid = sparks_grid_new(graph);
   double y = graph->height - graph->margins.bottom - ((double)data/SPARKS_DATA_MAX)*grid.h;

   cairo_set_line_width(graph->cr, opt.width);
   cairo_set_source_rgba(graph->cr, opt.color.r, opt.color.g, opt.color.b,
      opt.color.a);
   cairo_move_to(graph->cr, graph->margins.left, y);
   cairo_line_to(graph->cr, graph->margins.left + grid.w, y);
   cairo_stroke(graph->cr);
}

void
sparks_draw_simple_hline (sparks_t* graph, sparks_data_t data)
{
   sparks_draw_hline(graph, data, sparks_hline_opt_new());
}

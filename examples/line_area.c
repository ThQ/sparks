#include "sparks/sparks.h"
#include "sparks/area.h"
#include "sparks/line.h"

int main (int argc, char** argv)
{
   sparks_data_t data[] = {
      10, 100, 30, 50, 70, 117, 80, 120, 10, 20,
      50, 40, 20, 100, 110, 80, 120, 90, 100, 110
   };

   sparks_area_opt_t opt = sparks_area_opt_new();
   opt.color = sparks_get_rgb_color(0.9, 0.9, 0.9);

   sparks_t graph = sparks_new(150, 20);
   sparks_set_data_length(&graph, 20);
   sparks_draw_simple_line(&graph, data, 20);
   sparks_draw_area(&graph, data, 20, opt);
   sparks_save_png(&graph, "line_area.png");
   sparks_clean(&graph);

   return 0;
}

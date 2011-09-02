#include "sparks/sparks.h"
#include "sparks/area.h"
#include "sparks/line.h"

int main (int argc, char** argv)
{
   sparks_data_t data[] = {
      17, 12, 11, 12, 6, 0, 2, 14, 11, 9,
      12, 8, 9, 5, 9, 14, 17, 20, 31, 36,
      31, 36, 34, 39, 39, 34, 34, 36, 33, 29,
      34, 31, 26, 40, 36, 29, 14, 22, 26, 29,
      16, 5, 9, 11, 16, 5, 11, 8, 11, 9,
      16, 17, 22, 22, 22, 20, 17, 12, 19, 20,
      25, 31, 31, 31, 34, 47, 47, 53, 56, 57,
      59, 54, 56, 54, 56, 51, 56, 60, 62, 59,
      65, 67, 73, 71, 73, 78, 79, 81, 79, 82,
      82, 82, 88, 93, 90, 90, 87, 109, 121, 127
   };
   sparks_area_opt_t opt = sparks_area_opt_new();
   opt.color = sparks_get_rgb_color(0.9, 0.9, 0.9);

   sparks_t graph = sparks_new(220, 30);
   sparks_set_data_length(&graph, 100);
   sparks_draw_area(&graph, data, 100, opt);
   sparks_draw_simple_line(&graph, data, 100);
   sparks_save_png(&graph, "line_area.png");
   sparks_clean(&graph);

   return 0;
}

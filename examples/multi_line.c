#include "sparks/sparks.h"
#include "sparks/line.h"

int main (int argc, char** argv)
{
   sparks_data_t data1[] = {10, 100, 30, 50, 70, 117, 80, 120, 10};
   sparks_data_t data2[] = {27, 68, 59, 120, 35, 47, 28, 50, 70};

   sparks_line_opt_t opt2 = sparks_line_opt_new();
   opt2.color = sparks_get_rgb_color(0.8, 0.2, 0.3);

   sparks_t graph = sparks_new(150, 20);
   sparks_set_data_length(&graph, 9);
   sparks_draw_bg(&graph, 1, 1, 1);
   sparks_draw_simple_line(&graph, data1, 9);
   sparks_draw_line(&graph, data2, 9, opt2);
   sparks_save_png(&graph, "multi_line.png");
   sparks_clean(&graph);

   return 0;
}

#include "sparks/sparks.h"
#include "sparks/area.h"

int main (int argc, char** argv)
{
   sparks_data_t data[] = {60, 100, 60, 100, 60, 117, 80, 120, 10, 20, 106, 92};

   sparks_t graph = sparks_new(150, 20);
   sparks_set_data_length(&graph, 12);
   sparks_draw_bg(&graph, 1, 1, 1);
   sparks_draw_simple_area(&graph, data, 12, opt);
   sparks_save_png(&graph, "area.png");
   sparks_clean(&graph);

   return 0;
}

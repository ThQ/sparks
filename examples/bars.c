#include "sparks/sparks.h"
#include "sparks/bars.h"

int main (int argc, char** argv)
{
   sparks_data_t data[] = {10, 100, 30, 50, 70, 127, 80, 120, 10};

   sparks_t graph = sparks_new(220, 30);
   sparks_set_data_length(&graph, 25);
   sparks_draw_bg(&graph, 1, 1, 1);
   sparks_draw_simple_bars(&graph, data, 9);
   sparks_save_png(&graph, "bars.png");
   sparks_clean(&graph);

   return 0;
}

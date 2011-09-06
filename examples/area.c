#include "sparks/sparks.h"
#include "sparks/area.h"

int main (int argc, char** argv)
{
   // Japanese suicide rate (deaths per 100 000 population)
   // Source: OECD
   // http://www.oecd.org/document/60/0,3746,fr_2649_34631_32368700_1_1_1_1,00&&en-USS_01DBC.html
   sparks_data_t data[] = {
      127, 103, 77, 57, 46, 41, 43, 29, 33, 32,
       39,  40, 54, 61, 59, 62, 55, 55, 51, 53,
       45,  35, 37, 73, 63, 50, 68, 47, 34, 18,
        6,   1,  6,  0,  2,  3,  7, 14, 73, 69,
       58,  50, 54, 71, 58, 62, 58, 62, 62, 65
   };

   sparks_t graph = sparks_new(220, 30);
   sparks_set_data_length(&graph, 50);
   sparks_draw_simple_area(&graph, data, 50);
   sparks_save_png(&graph, "area.png");
   sparks_clean(&graph);

   return 0;
}

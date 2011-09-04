#include "sparks/sparks.h"
#include "sparks/line.h"

int main (int argc, char** argv)
{
   sparks_data_t data[] = {
      42, 25, 51, 106,  67, 31,  36, 36, 27,  54,
      16, 16, 37,  50,  17, 43,  59, 81, 54,  32,
      56, 51, 37,  72,  80, 42, 127, 84, 40,  81,
      85, 32, 44,  54,  77, 86,  49, 34, 34,  14,
      67, 63, 37,  51,   0,  8,  89, 34, 25,  42,
      43, 50, 74,  26,  70, 30,  80, 61, 66,  73,
      56, 49, 41,  74,  60, 37,  39, 37, 40, 118,
      65, 45, 31,  60,  70, 63,  62, 34, 46,  82,
      41, 65, 59, 106, 104, 87,  80, 51, 72,  43,
      57, 61, 57,  68,  35, 41,  48, 52, 46,  39
   };

   sparks_t graph = sparks_new(220, 30);
   sparks_set_data_length(&graph, 100);
   sparks_draw_simple_line(&graph, data, 100);
   sparks_save_png(&graph, "line.png");
   sparks_clean(&graph);

   return 0;
}

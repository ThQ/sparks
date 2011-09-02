#include "sparks/sparks.h"
#include "sparks/line.h"

int main (int argc, char** argv)
{
   sparks_data_t ocean_temp[] = {
       4, 0,    2,  17,  11,  31,  43,  20,  20,  30,
      31, 35,  35,  24,  28,  31,  36,  52,  44,  42,
      34, 53,  56,  52,  41,  49,  50,  55,  72,  67,
      73, 75,  90,  72,  71,  85,  80,  42,  38,  38,
      44, 41,  53,  65,  65,  42,  37,  41,  67,  71,
      65, 61,  69,  67,  69,  42,  48,  59,  55,  59,
      80, 66,  49,  74,  78,  54,  49,  49,  71,  66,
      79, 79,  77,  77,  87,  73,  68,  71,  90,  86,
      80, 96,  92,  80,  83,  89,  95,  87, 110, 127,
      98, 99, 114, 119, 122, 120, 120, 114, 107, 103
   };

   sparks_data_t land_temp[] = {
       18, 29,  19,  25,  30,  51,  50,  27,   0,  18,
       35, 31,  44,  35,  33,  26,  34,  52,  37,  44,
       21, 46,  46,  51,  34,  52,  43,  48,  52,  67,
       54, 54,  56,  55,  53,  65,  49,  51,  55,  54,
       46, 32,  48,  54,  62,  42,  41,  22,  54,  65,
       58, 51,  61,  58,  58,  35,  41,  48,  48,  41,
       53, 56,  41,  43,  70,  34,  49,  29,  64,  54,
       64, 70,  79,  61,  85,  54,  58,  69,  83,  87,
       77, 95,  86,  68,  75,  86,  98,  76,  99, 127,
      101, 91, 106, 115, 114, 112, 122, 115, 116, 105
   };

   sparks_line_opt_t land_temp_opt = sparks_line_opt_new();
   land_temp_opt.color = sparks_get_rgb_color(0.8, 0.2, 0.3);

   sparks_t graph = sparks_new(220, 30);
   sparks_set_data_length(&graph, 100);
   sparks_draw_simple_line(&graph, ocean_temp, 100);
   sparks_draw_line(&graph, land_temp, 100, land_temp_opt);
   sparks_save_png(&graph, "multi_line.png");
   sparks_clean(&graph);

   return 0;
}

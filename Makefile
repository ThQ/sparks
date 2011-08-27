
examples: example-area example-bars example-line example-multi-line

example-bars:
	gcc -Wall -O0 examples/bars.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-bars

example-multi-line:
	gcc -Wall -O0 examples/multi_line.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-multi-line

example-line:
	gcc -Wall -O0 examples/line.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-line

example-area:
	gcc -Wall -O0 examples/area.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-area

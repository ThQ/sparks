
examples: example-area example-bars example-line

example-bars:
	gcc -Wall -O0 examples/bars.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-bars

example-line:
	gcc -Wall -O0 examples/line.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-line

example-area:
	gcc -Wall -O0 examples/area.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-area

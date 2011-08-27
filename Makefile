xCC=gcc -std=c99 -Wall -pedantic

examples: example-area example-bars example-line example-line-area example-multi-line

example-bars:
	$(xCC) -O0 examples/bars.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-bars

example-multi-line:
	$xCC -O0 examples/multi_line.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-multi-line

example-line-area:
	$(xCC) -O0 examples/line_area.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-line-area

example-line:
	$(xCC) -O0 examples/line.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-line

example-area:
	$(xCC) -O0 examples/area.c `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo` -o ./build/sparks-area

splint-check:
	splint -Isrc/ `pkg-config --cflags cairo` src/sparks/*.c

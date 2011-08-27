xCC=gcc -std=c99 -Wall -pedantic
xCC_EXAMPLE:=$(xCC) -O0 `echo src/sparks/*.c` -I./src `pkg-config --cflags --libs cairo`


examples: example-area example-bars example-line example-line-area example-multi-line

example-bars:
	$(xCC_EXAMPLE) examples/bars.c -o ./build/sparks-bars

example-multi-line:
	$(xCC_EXAMPLE) examples/multi_line.c -o ./build/sparks-multi-line

example-line-area:
	$(xCC_EXAMPLE) examples/line_area.c -o ./build/sparks-line-area

example-line:
	$(xCC_EXAMPLE) examples/line.c -o ./build/sparks-line

example-area:
	$(xCC_EXAMPLE) examples/area.c -o ./build/sparks-area

splint-check:
	splint -Isrc/ `pkg-config --cflags cairo` src/sparks/*.c

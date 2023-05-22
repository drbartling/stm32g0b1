.PHONY: default
default: build
	cmake --build build --target run

build:
	cmake -S ./examples/blinky_nucleo -B build

clean:
	rm -rf *build*

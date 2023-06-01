.PHONY: default
default: build
	ninja -C build -v

build:
	cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm-none-eabi-gnu.cmake -S ./examples/blinky_nucleo -B build -G Ninja

clean:
	rm -rf build

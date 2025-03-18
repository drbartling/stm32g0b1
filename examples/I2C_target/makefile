.PHONY: default
default: build
	cmake --build build

build:
	cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm-none-eabi-gnu.cmake -S . -B build -G Ninja

clean:
	rm -rf build
build: configure-cmake
	cmake --build build

configure-cmake:
	cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm-none-eabi-gnu.cmake -S ./examples/blinky_nucleo -B build -G Ninja

flash: build
	openocd -f interface/stlink.cfg -f target/stm32g0x.cfg -c "program build/blinky_nucleo.bin exit 0x08000000 reset" -c "shutdown"

clean:
	rm -rf build

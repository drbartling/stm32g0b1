set(CMAKE_SYSTEM_NAME generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

include(${CMAKE_CURRENT_LIST_DIR}/../warnings-gnu.cmake)

set(HOSTING_FLAGS --specs=nosys.specs --specs=nano.specs)
set(ARCH_FLAGS -mthumb -mcpu=cortex-m0plus -mfloat-abi=soft)
# list(ARCH_FLAGS APPEND -nostdlib)

set(OPT_FLAGS -Os -g -gdwarf-4)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)

add_compile_options(${ARCH_FLAGS})
add_compile_options(${OPT_FLAGS})
add_compile_options(
    -ffunction-sections
    -fdata-sections
    -fno-common
    -fmessage-length=0
)
add_definitions(-DDEBUG)

add_link_options(
    -Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map
)
add_link_options(${ARCH_FLAGS})
add_link_options(${OPT_FLAGS})
add_link_options(
    -lc
    -lm
    -lgcc
    ${HOSTING_FLAGS}
)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

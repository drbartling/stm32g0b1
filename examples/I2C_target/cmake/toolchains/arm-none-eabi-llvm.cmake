# Targeting a bare-metal application (generic) on arm
set(CMAKE_SYSTEM_NAME generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# clang needs a stdlib to link to.  We're using gcc's in this example
set(ARM_GCC_C_COMPILER arm-none-eabi-gcc)
set(HOSTING_FLAGS -lcnano -lnosys)
set(ARCH_FLAGS -mthumb -mcpu=cortex-m0plus -mfloat-abi=soft)

execute_process(
    COMMAND ${ARM_GCC_C_COMPILER} -print-sysroot
    OUTPUT_VARIABLE ARM_GCC_SYSROOT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${ARM_GCC_C_COMPILER} ${ARCH_FLAGS} -print-multi-directory
    OUTPUT_VARIABLE ARM_GCC_MULTI_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${ARM_GCC_C_COMPILER} ${ARCH_FLAGS} -print-libgcc-file-name
    OUTPUT_VARIABLE ARM_GCC_LIBGCC
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(TOOLCHAIN_TRIPLE arm-none-eabi)

set(triple ${TOOLCHAIN_TRIPLE})
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${triple})
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${triple})

set(CMAKE_C_FLAGS_INIT " -B${ARM_TOOLCHAIN_DIR}")
set(CMAKE_CXX_FLAGS_INIT " -B${ARM_TOOLCHAIN_DIR} ")
# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_AR llvm-ar)
set(CMAKE_OBJCOPY llvm-objcopy)
set(CMAKE_OBJDUMP llvm-objdump)
set(SIZE llvm-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

include(${CMAKE_CURRENT_LIST_DIR}/../warnings-llvm.cmake)

set(STD_LIB_FLAGS
    -nostdlib -L${ARM_CORTEXM_SYSROOT}/lib/${ARM_CORTEXM_MULTI_DIR}
    ${ARM_GCC_LIBGCC}
)

set(OPT_FLAGS -Og -g -gdwarf-4)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)

add_compile_options(${ARCH_FLAGS})
add_compile_options(${OPT_FLAGS})
add_compile_options(--sysroot=${ARM_GCC_SYSROOT})
add_compile_options(-fshort-enums)
add_compile_options(
    -ffunction-sections
    -fdata-sections
    -fno-common
    -fmessage-length=0
)
add_definitions(-DDEBUG)

add_link_options(${ARCH_FLAGS})
add_link_options(${OPT_FLAGS})
add_link_options(-lm ${HOSTING_FLAGS})
add_link_options(${STD_LIB_FLAGS})

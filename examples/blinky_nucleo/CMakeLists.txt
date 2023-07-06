set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.22)

# project settings
project(blinky_nucleo LANGUAGES C CXX ASM)

# include(../../cmake/CPM.cmake)

# if(NOT TARGET stm32g0b1) CPMAddPackage("gh:drbartling/stm32g0b1#master")
# endif()
add_subdirectory(../.. lib_build)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/stand-alone.ld)

add_link_options(-T ${LINKER_SCRIPT})

add_library(project_warnings INTERFACE)
set_warnings(project_warnings)

add_executable(${PROJECT_NAME}.elf ${LINKER_SCRIPT} src/main.c)
target_link_libraries(${PROJECT_NAME}.elf stm32g0b1 project_warnings)
target_link_libraries(stm32g0b1 PUBLIC project_warnings)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
set(ASM_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.asm)

add_custom_command(
    TARGET ${PROJECT_NAME}.elf
    POST_BUILD
    COMMAND ${SIZE} $<TARGET_FILE:${PROJECT_NAME}.elf>
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf>
            ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf>
            ${BIN_FILE}
    COMMAND ${CMAKE_OBJDUMP} -drwCS $<TARGET_FILE:${PROJECT_NAME}.elf> >
            ${ASM_FILE}
    COMMENT "Building ${HEX_FILE} Building ${BIN_FILE}"
)

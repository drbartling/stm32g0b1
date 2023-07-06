cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(stm32g0b1)

include(cmake/CPM.cmake)

if(NOT TARGET c_static_asserts)
    cpmaddpackage("gh:drbartling/c_static_asserts#master")
endif()

# ---- Create binary ----

add_library(
    ${PROJECT_NAME}
    src/stm32g0b1.c
    src/stm_adc.c
    src/stm_flash.c
    src/stm_gp_timer.c
    src/stm_nvic.c
    src/stm_reset.c
    src/stm_scb.c
    src/stm_vrefbuf.c
    src/uart.c
)
target_link_libraries(${PROJECT_NAME} PUBLIC c_static_asserts)
target_include_directories(${PROJECT_NAME} PUBLIC include)

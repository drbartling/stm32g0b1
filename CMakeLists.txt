cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(stm32g0b1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

include(../../cmake/CPM.cmake)

if(NOT TARGET c_static_asserts)
    CPMAddPackage("gh:drbartling/c_static_asserts#master")
endif()

# ---- Create binary ----

add_library(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE c_static_asserts)
target_include_directories(${PROJECT_NAME} INTERFACE include)


# ---- Run executable ----
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

cmake_minimum_required(VERSION 3.10)

project(02-print-hello-world-loop)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}")

add_executable(hello_world_loop ./src/main.c)

# This makefile expects to be executed from inside the /build folder
install(TARGETS hello_world_loop DESTINATION ../bin)

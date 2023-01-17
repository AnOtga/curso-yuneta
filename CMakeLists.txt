############################################
#    CMake
############################################
cmake_minimum_required(VERSION 3.10)

project(curso-yuneta)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
set(PROJECT_ROOT_DIR /yuneta/development/projects/curso-yuneta/angel-oteros)
set(CMAKE_INSTALL_PREFIX ${PROJECT_ROOT_DIR}/bin)


##############################################
#   Source
##############################################
add_subdirectory(01-print-hello-world/c)
add_subdirectory(02-print-hello-world-loop/c)

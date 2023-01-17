############################################
#    CMake
############################################
cmake_minimum_required(VERSION 3.10)

project(02-print-hello-world-loop)

set(PROJECT_ROOT_DIR /yuneta/development/projects/curso-yuneta/angel-oteros)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_INSTALL_PREFIX ${PROJECT_ROOT_DIR}/bin)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_definitions(-DDEBUG)

  option(SHOWNOTES "Show preprocessor notes" OFF)

  if(CMAKE_COMPILER_IS_GNUCC)
    # GCC specific debug options
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -ggdb3 -gdwarf-2")
    set(AVOID_VERSION -avoid-version)
  endif(CMAKE_COMPILER_IS_GNUCC)
endif(CMAKE_BUILD_TYPE MATCHES Debug)


##############################################
#   Source
##############################################
add_executable(hello_world_loop ./src/main.c)


##############################################
#   Installation
##############################################
# This makefile expects to be executed from inside the /build folder
install(TARGETS hello_world_loop DESTINATION .)

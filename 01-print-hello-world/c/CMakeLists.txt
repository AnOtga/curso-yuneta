############################################
#    CMake
############################################
cmake_minimum_required(VERSION 3.10)
include(CheckIncludeFiles)
include(CheckSymbolExists)


project(01-print-hello-world)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
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


add_definitions(-D_GNU_SOURCE)
add_definitions(-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64)

check_include_files(regex.h HAVE_REGEX_H)
if(HAVE_REGEX_H)
    add_definitions(-DHAVE_REGEX_H)
else(HAVE_REGEX_H)
    message("***  WARNING: GNU C regex library not found.")
endif(HAVE_REGEX_H)

##############################################
#   Source
##############################################
add_executable(hello_world ./src/main.c)


##############################################
#   Installation
##############################################
# This makefile expects to be executed from inside the /build folder
install(TARGETS hello_world DESTINATION .)


# compile in Release mode optimized but adding debug symbols, useful for profiling :
#
#     cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#
# or compile with NO optimization and adding debug symbols :
#
#     cmake -DCMAKE_BUILD_TYPE=Debug ..
#
# To compile targetting ARM, use cmake -DNOT_INCLUDE_LIBUNWIND

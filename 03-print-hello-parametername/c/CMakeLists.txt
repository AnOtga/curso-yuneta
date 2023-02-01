############################################
#    CMake
############################################
cmake_minimum_required(VERSION 3.10)
include(CheckIncludeFiles)
include(CheckSymbolExists)


project(03-print-hello-parametername)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
set(PROJECT_ROOT_DIR /yuneta/development/projects/curso-yuneta/angel-oteros)
#This changes the output direction of the executable created in a <make> to the root of the build output, which is not needed here, thus commented out
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_INSTALL_PREFIX ${PROJECT_ROOT_DIR})

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
SET (SOURCE_BASE_FILES
    ./src/main.c
)

##############################################
#   Add sources to executables to build
##############################################
add_executable(03-hello_parametername ${SOURCE_BASE_FILES})


##############################################
#   Installation
##############################################
# This makefile expects to be executed from inside the /build folder
install(
    TARGETS 03-hello_parametername
    PERMISSIONS
    OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_WRITE GROUP_EXECUTE
    WORLD_READ WORLD_EXECUTE
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)


# compile in Release mode optimized but adding debug symbols, useful for profiling :
#
#     cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#
# or compile with NO optimization and adding debug symbols :
#
#     cmake -DCMAKE_BUILD_TYPE=Debug ..
#
# To compile targetting ARM, use cmake -DNOT_INCLUDE_LIBUNWIND

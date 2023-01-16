cmake_minimum_required(VERSION 3.10)

project(curso-yuneta)

set(PROJECT_ROOT_DIR /yuneta/development/projects/curso-yuneta/angel-oteros)
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

add_subdirectory(01-print-hello-world/c)
add_subdirectory(02-print-hello-world-loop/c)

install(DIRECTORY ${CMAKE_BINARY_DIR/01-print-hello-world/c} DESTINATION .)
install(DIRECTORY ${CMAKE_BINARY_DIR/02-print-hello-world/c} DESTINATION .)

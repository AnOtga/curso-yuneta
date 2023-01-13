cmake_minimum_required(VERSION 3.10)

project(curso-yuneta)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR/bin})

add_subdirectory(01-print-hello-world/c)
add_subdirectory(02-print-hello-world-loop/c)

install(DIRECTORY ${CMAKE_BINARY_DIR/01-print-hello-world/c} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY ${CMAKE_BINARY_DIR/02-print-hello-world/c} DESTINATION ${CMAKE_INSTALL_PREFIX})

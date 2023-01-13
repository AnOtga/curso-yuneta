cmake_minimum_required(VERSION 3.10)

project(curso-yuneta)


#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR/bin})
set(CMAKE_INSTALL_PREFIX /yuneta/development/projects/curso-yuneta/angel-oteros)
set(BIN_DEST_DIR ${CMAKE_INSTALL_PREFIX}/bin)

add_subdirectory(01-print-hello-world/c)
add_subdirectory(02-print-hello-world-loop/c)

install(DIRECTORY ${CMAKE_BINARY_DIR/01-print-hello-world/c} DESTINATION ${BIN_DEST_DIR})
install(DIRECTORY ${CMAKE_BINARY_DIR/02-print-hello-world/c} DESTINATION ${BIN_DEST_DIR})

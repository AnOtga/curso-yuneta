project(curso-yuneta)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR/bin})

add_subdirectory(01-print-hello-world/)
add_subdirectory(02-print-hello-world-loop/)

install(DIRECTORY ${CMAKE_BINARY_DIR/01-print-hello-world DESTINATION ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY ${CMAKE_BINARY_DIR/02-print-hello-world DESTINATION ${CMAKE_INSTALL_PREFIX})

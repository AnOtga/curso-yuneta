project(01-print-hello-world)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

add_executable(hello_world .src/main.c)

install(TARGETS 01-print-hello-world DESTINATION ./bin)

############################################
#    CMake
############################################
cmake_minimum_required(VERSION 3.10)


project(curso-yuneta)


##############################################
#   Source
##############################################
add_subdirectory(01-print-hello-world/c)
add_subdirectory(02-print-hello-world-loop/c)
add_subdirectory(03-print-hello-parametername/c)
add_subdirectory(04-tcp-listener-writer/c)
add_subdirectory(05-tcp-file-io/c)
add_subdirectory(06-tcp-filelist-io/c)

# compile in Release mode optimized but adding debug symbols, useful for profiling :
#
#     cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#
# or compile with NO optimization and adding debug symbols :
#
#     cmake -DCMAKE_BUILD_TYPE=Debug ..
#
# To compile targetting ARM, use cmake -DNOT_INCLUDE_LIBUNWIND

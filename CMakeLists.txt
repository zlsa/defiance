cmake_minimum_required(VERSION 2.6)

project(Defiance)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_CLIENT 1 CACHE BOOL "Build the Defiance client")

if(${BUILD_CLIENT})
  add_subdirectory(src/client)
endif(${BUILD_CLIENT})



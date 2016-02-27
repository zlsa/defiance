cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

include_directories(../../include/shared/)
include_directories(../../include/client/)

add_executable(defiance-client
  main.c
  ../shared/mesh.c
  ../shared/shader.c
  ../shared/object.c
  ../shared/window.c
  ../shared/program.c
  ../shared/util.c
  )

target_link_libraries(defiance-client ${OPENGL_LIBRARIES})
target_link_libraries(defiance-client ${GLFW_LIBRARIES})
target_link_libraries(defiance-client ${GLEW_LIBRARIES})

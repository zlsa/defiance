cmake_minimum_required(VERSION 2.6)

include_directories(../../include/shared/)
include_directories(../../include/client/)

add_executable(defiance-client main.c ../shared/program.c ../shared/util.c)


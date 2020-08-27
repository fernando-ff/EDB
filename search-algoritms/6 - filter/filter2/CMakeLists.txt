cmake_minimum_required(VERSION 3.10)
project(filter2)
set (filter2_VERSION_MAJOR 0)
set (filter2_VERSION_MINOR 0)
set (filter2_VERSION_PATCH 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/filter2Config.h.in"
  "${PROJECT_BINARY_DIR}/filter2Config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")
add_executable(filter2 main.cpp)
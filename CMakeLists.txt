cmake_minimum_required(VERSION 3.20)
project(cpp_lib_personal)

add_library(cpp_lib_personal
  src/main.cpp
)

target_include_directories(cpp_lib_personal
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(cpp_lib_personal PUBLIC cxx_std_20)

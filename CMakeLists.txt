cmake_minimum_required(VERSION 3.20)
project(glok)

add_library(glok
  src/main.cpp
)

target_include_directories(glok
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(glok PUBLIC cxx_std_17)

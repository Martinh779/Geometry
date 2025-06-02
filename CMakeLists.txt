cmake_minimum_required(VERSION 3.30)
project(Geometry LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)

add_library(Geometry INTERFACE)
target_include_directories(Geometry INTERFACE include)
cmake_minimum_required(VERSION 3.24)
project(p1)

set(CMAKE_CXX_STANDARD 17)

add_executable(p1 wcat.cpp wgrep.cpp wzip.cpp wunzip.cpp)

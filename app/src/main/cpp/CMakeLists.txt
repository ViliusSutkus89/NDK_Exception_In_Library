cmake_minimum_required(VERSION 3.10.2)

project("exceptioner")

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

set(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

add_library(thrower-lib SHARED thrower-lib.cpp)
add_library(native-lib SHARED native-lib.cpp)

target_link_libraries(native-lib thrower-lib)

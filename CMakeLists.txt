cmake_minimum_required(VERSION 3.14)
project(Rfm69_Node VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(source/libavrhal)
add_subdirectory(source/avr_node)

cmake_minimum_required(VERSION 3.10)

project(NN)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Add source files
add_executable(NN main.cpp NeuralNetwork.cpp)

set_target_properties(NN PROPERTIES LINKED_MAIN_FILE "NN")

# Set compiler flags
target_compile_options(NN PRIVATE -Wall -Wpedantic)

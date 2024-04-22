cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Add source files
add_executable(MyProject main.cpp NeuralNetwork.cpp)

# Set compiler flags
target_compile_options(MyProject PRIVATE -Wall -Wpedantic)
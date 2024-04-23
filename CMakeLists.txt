cmake_minimum_required(VERSION 3.10)
project(NN CXX)


set(base_directory ${CMAKE_CURRENT_SOURCE_DIR})
# Set source directory
set(resources_directory ${base_directory}/data)
set(sources_directory ${base_directory}/src)
set(include_directory ${base_directory}/include)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${base_directory}/bin)
set(EXECUTABLE_OUTPUT_PATH ${base_directory}/bin)

SET(CMAKE_CXX_STANDARD 14)

#set library directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${base_directory}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${base_directory}/lib)

# Set include directories
include_directories(${CMAKE_CURRENT_BINARY_DIR}  # Remove redundant `${include_directory}`
                   ${include_directory})

# Add source files
file(GLOB_RECURSE nn_source_files ${sources_directory}/*.cpp ${resources_directory}/*.csv)

add_executable(NN ${nn_source_files})

set_target_properties(NN PROPERTIES LINKED_MAIN_FILE "NN")

# Set compiler flags
target_compile_options(NN PRIVATE -Wall -Wpedantic)

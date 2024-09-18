cmake_minimum_required(VERSION 3.10)
project(port_scanner)

set(CMAKE_CXX_STANDARD 17)

# Create the port_scanner library
add_library(port_scanner STATIC
    src/port_scanner.cpp
)

# Specify include directories for the port_scanner library
target_include_directories(port_scanner PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

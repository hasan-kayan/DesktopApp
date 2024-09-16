cmake_minimum_required(VERSION 3.10)
project(device_scanner)

set(CMAKE_CXX_STANDARD 17)

# Add the port_scanner subdirectory
add_subdirectory(${CMAKE_SOURCE_DIR}/../port_scanner ${CMAKE_BINARY_DIR}/port_scanner_build)

# Create the device_scanner library
add_library(device_scanner STATIC
    src/device_scanner.cpp
)

# Specify include directories for the device_scanner library
target_include_directories(device_scanner PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../port_scanner/include
)

# Link the port_scanner library to the device_scanner library
target_link_libraries(device_scanner PRIVATE port_scanner)

# Create the executable
add_executable(device_scanner_test
    main.cpp
)

# Link the device_scanner library to the executable
target_link_libraries(device_scanner_test PRIVATE device_scanner)

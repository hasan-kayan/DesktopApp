cmake_minimum_required(VERSION 3.10)
project(PortScannerLib)

set(CMAKE_CXX_STANDARD 17)

# Add the library
add_library(port_scanner STATIC
    src/port_scanner.cpp
)

# Include platform-specific files based on the platform
if(WIN32)
    target_sources(port_scanner PRIVATE src/platform/port_scanner_win.cpp)
elseif(APPLE)
    target_sources(port_scanner PRIVATE src/platform/port_scanner_mac.cpp)
elseif(UNIX)
    target_sources(port_scanner PRIVATE src/platform/port_scanner_linux.cpp)
endif()

# Include directories for the library
target_include_directories(port_scanner PUBLIC include)

# Platform-specific linking
if(WIN32)
    target_link_libraries(port_scanner setupapi)
elseif(APPLE)
    find_library(IOKIT IOKit)
    target_link_libraries(port_scanner ${IOKIT})
elseif(UNIX)
    target_link_libraries(port_scanner udev)
endif()

# Add the test program
add_executable(test_port_scanner tests/test_port_scanner.cpp)

# Link the test program with the port scanner library
target_link_libraries(test_port_scanner port_scanner)

cmake_minimum_required(VERSION 3.10)
project(PortScannerLib)

set(CMAKE_CXX_STANDARD 17)

# Define the library and include directories
add_library(port_scanner STATIC
    src/port_scanner.cpp
    src/platform/port_scanner_win.cpp
    src/platform/port_scanner_mac.cpp
    src/platform/port_scanner_linux.cpp
)

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

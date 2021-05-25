#Version of cmake minimum required.
cmake_minimum_required(VERSION 3.0  FATAL_ERROR)	 

#Project name
project(ascii_simple)

#BUILD_CPP has got all .cpp files of the project/
file(GLOB BUILD_CPP "../AsciiMachineCurrent/API/src/*.cpp")

# SFML include
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
include_directories( ${SFML_INCLUDE_DIRS} )

# Add AsciiSimple.o and libAscii.so ( or .dll )
add_library(Ascii SHARED ${BUILD_CPP})
add_executable(AsciiSimple Example1.cpp)	

# AsciiSimple build
target_include_directories(AsciiSimple PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(AsciiSimple sfml-graphics)
install(TARGETS AsciiSimple DESTINATION bin)

# libAscii( .so or .dll ) build.
target_include_directories(Ascii PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(Ascii sfml-graphics)
install(TARGETS Ascii DESTINATION bin)

# Merge AsciiSimple.o and libAscii.so ( or .dll )
target_link_libraries(AsciiSimple Ascii)
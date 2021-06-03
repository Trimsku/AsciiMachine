#Version of cmake minimum required. 
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(ascii_simple )

configure_file(AsciiConfig.h.in AsciiConfig.h)
option(USE_PROGS "Create simple programs?" OFF)

add_compile_options(
    # All warnings are errors.
    # -Werror
    # For more information.
    -Wall
    -Wextra
    -Wpedantic
    # Options
    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
    -O0
    -g
)

#BUILD_CPP has got all .cpp files of the project/
file(GLOB BUILD_CPP "API/src/*.cpp")

# SFML include
find_package(SFML 2 COMPONENTS graphics window REQUIRED)
find_package(SFML 2.5.1 COMPONENTS graphics window)
find_package(X11)
include_directories( ${SFML_INCLUDE_DIRS} )
include_directories(${X11_INCLUDE_DIR})

# Add AsciiSimple.o and libAscii.so ( or .dll )
add_library(Ascii STATIC ${BUILD_CPP})
target_link_libraries(Ascii ${X11_LIBRARIES})

# If you want to include simple programs
if(USE_PROGS)
    add_executable(AsciiSimple1 Example1/Example1.cpp)
    add_executable(AsciiSimple2 Example2/Example2.cpp)
    # AsciiSimple1 build
    target_include_directories(AsciiSimple1 PRIVATE "${PROJECT_BINARY_DIR}")
    target_link_libraries(AsciiSimple1 sfml-graphics)
    install(TARGETS AsciiSimple1 DESTINATION bin)
    # AsciiSimple2 build
    target_include_directories(AsciiSimple2 PRIVATE "${PROJECT_BINARY_DIR}")
    target_link_libraries(AsciiSimple2 sfml-graphics)
    install(TARGETS AsciiSimple2 DESTINATION bin)
endif()

# libAscii( .so or .dll ) build.
target_include_directories(Ascii PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(Ascii sfml-graphics)
install(TARGETS Ascii DESTINATION bin)

# Merge AsciiSimple.o and libAscii.so ( or .dll )
if(USE_PROGS)
    # Example1 link
    target_link_libraries(AsciiSimple1 ${X11_LIBRARIES} Ascii)

    #Example2 link
    target_link_libraries(AsciiSimple2 ${X11_LIBRARIES} Ascii) 
endif()
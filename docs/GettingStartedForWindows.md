# How to get started?

On this page, you can get started with the following instructions:

## Requirements( install it ): SFML, git, g++ and CMake.

### You can create and copy folders in GUI

0. Create your main folder in Disk C.
`mkdir Tutorial` 

1. Clone repository and copy the current version to your project.
`git clone https://github.com/Trimsku/AsciiMachine`
Copy Example/ and AsciiMachineCurrent/ to your main dir.
And go to your main folder back.

1. Create font/ folder.
So far, we don't need more, more and more textures and fonts.
Grab them from Example ( Copy from `Example1/` dir in path/to/AsciiMachine/Example1 )

1. Create main.cpp and paste this code:

```cpp
#define GLOBAL_SIZE 50
#include "AsciiMachineCurrent/API/include/GUI_o.hpp"
#include "AsciiMachineCurrent/API/include/utils.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    ascii::GUI_o HelloWorld("HelloWorld");
    HelloWorld.setGlobalXY(500,500);
    HelloWorld.isFontLoaded("../font/10894.otf");
    HelloWorld.newSprites("Hello World!", "HW");
    while (window.isOpen()) {
        window.clear();

        EVENT;
        EVENT_CLOSED(Q);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();

        GUI_O_LOAD(HelloWorld, HW);
        window.display();
    }

    return 0;
}
```

4. Create CMakeLists.txt with the following code:

```cmake
#Version of cmake minimum required.
cmake_minimum_required(VERSION 3.0  FATAL_ERROR)	 

#Project name
project(ascii_simple)

#BUILD_CPP has got all .cpp files of the project/
file(GLOB BUILD_CPP "../AsciiMachineRemake/API/src/*.cpp")

# SFML include
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
include_directories( ${SFML_INCLUDE_DIRS} )

# Add AsciiSimple.o and libAscii.so ( or .dll )
add_library(Ascii SHARED ${BUILD_CPP})
add_executable(AsciiSimple ../Example/Simple.cpp)	

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
```

In main folder:

```
mkdir build 
cd build
cmake ..
```

``` I don't know what's create cmake in windows, sorry... ```
And finally:
Go to your main folder and run AsciiSimple

This tutorial is very bad. Please, help me with AsciiMachine in Windows? 

Thanks for read a tutorial!

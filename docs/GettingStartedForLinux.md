# How to get started?

On this page, you can get started with the following instructions:

## Requirements( install it ):  SFML, git, g++ and CMake.

0. Create your main folder.
```
mkdir Tutorial && cd Tutorial 
```

1. Clone repository and copy the current version.
`git clone https://github.com/Trimsku/AsciiMachine`
`cp AsciiMachine/AsciiMachineCurrent -r .` ( In Tutorial/ folder)

1. Create (textures/ is folder with .rtxt files) textures/ and font/ folders.
Grab them from Example ( we don't need textures/, because in project with entities or items, I recommend create textures/ folder).
```
cp AsciiMachine/Example1/font -r .
```

5. Create main.cpp and paste this code:

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

6. Create CMakeLists.txt with the following code:

```cmake
#Version of cmake minimum required.
cmake_minimum_required(VERSION 3.0  FATAL_ERROR)	 

#Project name
project(ascii_simple )

# SFML include
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)
find_package(SFML 2.5.1 COMPONENTS graphics window system)
include_directories( ${SFML_INCLUDE_DIRS} )

# Add AsciiSimple.o  and libAscii.a
add_subdirectory(AsciiMachine)
add_executable(AsciiSimple ../main.cpp)	

# AsciiSimple build
target_include_directories(AsciiSimple PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(AsciiSimple sfml-graphics)
install(TARGETS AsciiSimple DESTINATION bin)

# Merge AsciiSimple.o and libAscii.a
target_link_libraries(AsciiSimple Ascii)
```

And finally in build/ folder( In tutorial ):

```
mkdir build && cd build
cmake ..
make
./AsciiSimple
```

Thanks for read a tutorial!

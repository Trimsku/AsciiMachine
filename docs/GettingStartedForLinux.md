#How to get started?

On this page, you can get started with the following instructions:

#####Requirements( install it ):
#####SFML and git

0. Create your main folder.
`mkdir Tutorial`

1. Clone repository and copy the current version.
`git clone https://github.com/Trimsku/AsciiMachine`
`mv /path/to/AsciiMachine/AsciiMachineCurrent /path/to/your/project`
And copy Example.
`mv /path/to/AsciiMachine/Example .`
And go to your main folder

2. Create textures/ and font/ folders.
So far, we don't need more, more and more textures and fonts.
Grab them from Example.
```
mv Example/font .
mv Example/textures .
```

3. Create main.cpp and paste this code:

```\#define GLOBAL_SIZE 50
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

```
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

And finally in main folder:

```
mkdir build && cd build
cmake ..
make
./AsciiSimple
```

Thanks for read a tutorial!
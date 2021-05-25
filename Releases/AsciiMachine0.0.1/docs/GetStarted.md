#How to get started?

On this page, you can get started with the following instructions:

##Requirements:
## SFML and git
Clone repository to your project.
1. `git clone https://github.com/Trimsku/AsciiMachine`


2. Create bin/, textures/ and font/ folders.
You can copy this folders from AsciiMachine folder:
`mv /path/to/AsciiMachine/font /path/to/your/project`
`mv /path/to/AsciiMachine/textures /path/to/your/project` 
`mv /path/to/AsciiMachine/bin /path/to/your/project `
Or you can create a custom:
`mkdir bin && mkdir textures && mkdir font`

3. Create main.cpp and paste this code:

```\#define GLOBAL_SIZE 50
#include "path/to/AsciiMachine/API/include/GUI_o.hpp"
#include "path/to/AsciiMachine/API/include/utils.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    ascii::GUI_o HelloWorld("HelloWorld");
    HelloWorld.setGlobalXY(500,500);
    HelloWorld.isFontLoaded("font/10894.otf");
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

4. Create Makefile with the following code:

```
SFML = -lsfml-graphics -lsfml-window -lsfml-system

build:
	g++ -c main.cpp
	g++ main.o bin/*.o -o AsciiSample ${SFML} 

source:
    g++ path/to/AsciiMachine/src/*.cpp -c ${SFML}
	mv path/to/AsciiMachine/src/*.o bin/
```
( path/to/AsciiMachine - it is your path to the AsciiMachine )
If you have Window, doesn't create a Makefile. And command mv not working in Windows. ( In Windows copy to bin ).

And finally:
In cmd:
```
make source
make build
./AsciiSample
```
For Windows, i can't create a normal tutorial, but you can help me and create normal tutorial for Windows.

Thanks for read a tutorial!
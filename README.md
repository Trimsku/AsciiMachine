# Hello! It is AsciiMachine!
It is engine for create ascii games
Hm.. AsciiMachine test on Linux: Manjaro, Arch Linux and Linux Mint.

Engine use C++, but this is project for very small size of programs.
Engine C++: classes, templates.

Engine C: <stdio.h>, std::string don't using in engine, but you can use std::string(.c_str()).

Project has got small alternatives, i.e: 
1. astd::string, do not use in function params(use const char*, and .c_str() in astd::string).
2. astd::container, (std::vector alternative).
3. astd::Clock, getEllapsedTime(), and restart().
4. Uniprint, makes it easier to output astd objects. Is being finalized.

Engine has got: sdl wrapper and SDL_FontCache wrapper(class Font) 

For building example, use make build && ./a.out in AsciiMachine dir

SDL_FontCache is not my project!

SDL_FontCache Github: https://github.com/grimfang4/SDL_FontCache

SDL_FontCache Author: https://github.com/grimfang4

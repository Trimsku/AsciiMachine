# Hello! It is AsciiMachine!
It is engine for create ascii games
Hm.. AsciiMachine test on Linux: Manjaro, Arch Linux and Linux Mint.

Engine use C++, but this is project for very small size of programs.
Engine C++: classes, templates.

Engine C: <stdio.h>, std::string don't using in engine, but you can use std::string(.c_str()).

Project has got small alternatives, i.e: 
1. astd::string.
2. astd::container, (std::vector alternative).
3. astd::Clock, getEllapsedTime(), and restart().
4. Uniprint, makes it easier to output astd objects. Is being finalized.

Engine has got: sdl wrapper and SDL_FontCache wrapper(class Font) 

For building example:
  1. Install spm(this is my project).
  2. in project root dir: ./<path/to/spm

# SDL_FontCache is not my project!

SDL_FontCache Github: https://github.com/grimfang4/SDL_FontCache

SDL_FontCache Author: https://github.com/grimfang4

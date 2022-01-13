# Hello! This is AsciiMachine!
The engine for create ascii games
AsciiMachine tested on Linux.

Project has got small std alternatives and wrappers, i.e: 

1. astd::container, (std::vector alternative) (deprecated).
2. astd::Clock, getEllapsedTime(), and restart().

For building example:
  1. Install spm(this is my project).
  2. in project root dir: ./<path/to/spm
  3. make
  4. ./bin/Release/AsciiGame

### How to build?
In Linux: `sudo bash install.sh` in AsciiMachine root dir

if that doesn't work, then you need to build with `sudo bash ./install-raw.sh`

### SDL_FontCache is not my project!
https://github.com/grimfang4/SDL_FontCache

### And I also use utf8-iterator lib
https://github.com/adrianwk94/utf8-iterator
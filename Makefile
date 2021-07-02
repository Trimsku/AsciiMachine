SDL2 = -lSDL2 -lSDL2_ttf

SDL_Wrapper = src/SDL/*.cpp src/SDL/*.c
Event = src/Event/*.cpp
util = src/util/*.cpp
astd=src/astd/*.cpp
nospeed = -Os
debug = -g -O0 -fsanitize=address

build:
	g++ testGame/main.cpp ${SDL_Wrapper} ${Event} ${util} src/*.cpp ${SDL2} ${astd}
	du -b a.out

optimize-build:
	g++ testGame/main.cpp ${SDL_Wrapper} ${Event} ${util} src/*.cpp ${SDL2} ${astd} ${nospeed}
	du -b a.out

se-build:
	g++ se/SpriteEditor.cpp ${SDL_Wrapper} ${util} src/*.cpp ${SDL2} ${debug} ${astd} -o se-editor
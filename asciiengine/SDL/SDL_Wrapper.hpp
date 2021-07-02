#ifndef SDL_WRAPPER_H
#define SDL_WRAPPER_H
#include "SDL_FontCache.h"
#include "../util/DebugPrint.hpp"

namespace ascii
{
    class SDL_Engine {
        private:
            SDL_FRect rect;
        public:
            SDL_Window *window = nullptr;
            SDL_Renderer *renderer = nullptr;
            ~SDL_Engine();
            void init();
            void createWindow(astd::string name, int width, int height);
            void FillIn(float x, float y, float width, float height);
        friend class Font;
        friend class TInstance;
    };
} // namespace ascii

#define is_event(event_type) e.type == SDL_##event_type
#define is_key_pressed(sdl_key) SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_##sdl_key]
#define game_while \
    SDL_Event e; \
    bool quit = false; \
    while (!quit) \

#define game_while_close quit=true
#define event_while SDL_PollEvent(&e)
#define Draw(x, y, str) FC_Draw(font, Engine.renderer, x, y, str);

#endif // SDL_WRAPPER_H
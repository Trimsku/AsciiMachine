#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "SDL_FontCache.h"
#include "Font.hpp"
#include "utf-8.h"
#include "../common/Scene.hpp"

namespace ascii
{
    class Engine {
        private:
            SDL_FRect engine_rect;
            SDL_Window *engine_window = nullptr;
            SDL_Renderer *engine_renderer = nullptr;
            ascii::scene::Scene currentScene = ascii::scene::Scene(false, false);
            SDL_Rect camera = {0, 0, 1921, 1080};
        public:
            ascii::Font engine_font;
            Engine();
            ~Engine();
            void loadFont(const char* path_to_font_m, int size, int style);
            void createWindow(astd::string name, int width, int height);

            int getFontSize() noexcept;
            SDL_Rect *getCamera() noexcept;
            SDL_Window *getWindow() noexcept;
            SDL_Renderer *getRenderer() noexcept;
            ascii::scene::Scene *getCurrentScene() noexcept;
            void setCurrentScene(ascii::scene::Scene newScene) noexcept;
            bool isUsingCamera() noexcept;
            bool isUsingGravity() noexcept;
            void cleanScreen() noexcept;
            void presentScreen() noexcept;
            void draw(signed int x, signed int y, astd::string Sprite) noexcept;
            void draw(signed int x, signed int y, const char* Sprite) noexcept;
            void drawWithBackground(signed int x, signed int y, astd::string Sprite) noexcept;
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

#endif // ENGINE_HPP

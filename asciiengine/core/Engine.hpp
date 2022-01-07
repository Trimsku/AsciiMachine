#pragma once
#include "SDL_FontCache.h"
#include "Font.hpp"
#include "utf-8.h"
#include "../common/Scene.hpp"
#include "../common/Camera.hpp"
#include "../client/Shader.hpp"

namespace ascii
{
    class Engine {
        private:
            SDL_Window *engine_window = nullptr;
            SDL_Renderer *engine_renderer = nullptr;
            ascii::Font engine_font;
            ascii::scene::IScene *currentScene = nullptr;
            int screenW, screenH;
            ascii::Camera camera;
            SDL_GLContext glContext;
        public:
            Engine() noexcept;
            ~Engine() noexcept;
            void loadFont(const char* path_to_font_m, int size, int style) noexcept;
            void createWindow(astd::string name, int width, int height) noexcept;
            void setScene(ascii::scene::IScene *newScene) noexcept;
            inline int getFontSize() noexcept;
            inline int getScrW() noexcept;
            inline int getScrH() noexcept;
            inline ascii::Camera *getCamera() noexcept;
            inline SDL_Window *getWindow() noexcept;
            inline SDL_Renderer *getRenderer() noexcept;
            inline ascii::scene::IScene *getScene() noexcept;
            inline bool isUsingGravity() noexcept;
            inline void cleanScreen() noexcept;
            inline void presentScreen() noexcept;
            void draw(signed int x, signed int y, astd::string Sprite) noexcept;
            void draw(signed int x, signed int y, const char* Sprite) noexcept;
            void drawWithBackground(signed int x, signed int y, astd::string Sprite) noexcept;
    };
    bool Engine::isUsingGravity() noexcept {
        return currentScene->isUsingGravity();
    }
    int Engine::getScrW() noexcept {
        return screenW;
    }
    int Engine::getScrH() noexcept {
        return screenH;
    }
    void Engine::cleanScreen() noexcept {
        SDL_RenderClear(engine_renderer);
    }
    void Engine::presentScreen() noexcept {
        SDL_RenderPresent(engine_renderer);
    }
    SDL_Window *Engine::getWindow() noexcept{
        return engine_window;
    }
    SDL_Renderer *Engine::getRenderer() noexcept{
        return engine_renderer;
    }
    ascii::Camera *Engine::getCamera() noexcept {
        return &camera;
    }
    ascii::scene::IScene *Engine::getScene() noexcept{
        return currentScene;
    }
    int Engine::getFontSize() noexcept {
        return engine_font.getSize();
    }
} // namespace ascii

#define is_event(event_type) e.type == SDL_##event_type
#define is_key_pressed(sdl_key) SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_##sdl_key]
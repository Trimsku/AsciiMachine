#include "../../asciiengine/core/Font.hpp"
#include "../../asciiengine/core/Engine.hpp"

ascii::Font::Font() noexcept {}
ascii::Font::~Font() noexcept {FC_FreeFont(font);}

void ascii::Font::initializeFont(ascii::Engine* engine, const char* path_to_font, int size_i, int style) noexcept {
    printf("Font %s is created\n", path_to_font);
    font = FC_CreateFont();
    size = size_i;
    if(engine->getRenderer() == nullptr) {
        printf("Please use createWindow(...) before creating Font; SDL_Renderer is null");
        exit(1);
    }
    if(engine->getWindow() == nullptr) {
        printf("Please use createWindow(...) before creating Font; SDL_Window is null");
        exit(1);
    }
    if(!FC_LoadFont(font, engine->getRenderer(), path_to_font, size_i, FC_MakeColor(255,255,255,255), style)) {
        printf("%s", SDL_GetError());
        exit(1);
    }
}
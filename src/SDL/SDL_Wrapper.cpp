#include "../../asciiengine/SDL/SDL_Wrapper.hpp"


void ascii::SDL_Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        printDebug(LogLevel::Error, "Unable to init SDL2: ", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0){
        printDebug(LogLevel::Error, SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}


void ascii::SDL_Engine::createWindow(astd::string name, int width, int height) {
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr){
       printDebug(LogLevel::Error, "Unable to create window: %s", SDL_GetError());
       SDL_Quit();
       exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        printf("%s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}

void ascii::SDL_Engine::FillIn(float x, float y, float width, float height) {
    rect.h = height;
    rect.w = width;
    rect.x = x;
    rect.y = y;
    SDL_RenderFillRectF(renderer, &rect);
}

ascii::SDL_Engine::~SDL_Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); 
    SDL_Quit();
    printDebug(LogLevel::Log, "SDL_Engine is destroyed\n");
}
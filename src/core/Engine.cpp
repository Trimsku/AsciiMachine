#include "../../asciiengine/core/Engine.hpp"

namespace ascii {

Engine::~Engine() noexcept {
    SDL_DestroyRenderer(engine_renderer);
    SDL_DestroyWindow(engine_window); 
    engine_renderer = NULL;
    engine_window = NULL;
    SDL_Quit();
    if(currentScene != nullptr) delete currentScene;
    printf("Engine is destroyed\n");
}

Engine::Engine() noexcept : engine_font(), camera(this){
    #ifdef __APPLE__
	    ascii::client::initializeFileSystem();
    #endif
    if (SDL_Init(SDL_INIT_EVERYTHING | SDL_VIDEO_OPENGL ) == -1){
        printf("Unable to init SDL2: %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0){
        printf("%s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2")) {
        printf("Cannot set SDL_HINT_RENDER_SCALE_QUALITY to \"1\", report this bug to game developer");
    }
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(0, 0, &mode);
    screenW = mode.w;
    screenH = mode.h;
    camera = ascii::Camera(this);
}

void Engine::setScene(ascii::scene::IScene *newScene) noexcept{
    if(currentScene != nullptr) delete currentScene;
    currentScene = newScene;
    ascii::Listener::Subject::getInstance().createMessage("onSceneChangedEvent");
}

void Engine::loadFont(const char* path_to_font, int size, int style) noexcept {
    engine_font.initializeFont(this, path_to_font, size, style);
}

void Engine::createWindow(astd::string name, int width, int height) noexcept {
    if(width == -1 && height == -1) {
        engine_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    } else if(width == -1) {
        engine_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, screenW, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    } else if(height == -1) {
        engine_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, width, screenH, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    } else {
        engine_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    }
    if (engine_window == nullptr){
       printf("Unable to create window: %s", SDL_GetError());
       SDL_Quit();
       exit(1);
    }
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    engine_renderer = SDL_CreateRenderer(engine_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    if (engine_renderer == nullptr){
        printf("%s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    glContext = SDL_GL_CreateContext(getWindow());
}

void Engine::draw(signed int x, signed int y, astd::string Sprite) noexcept {
    signed int x_ = x;
    signed int y_ = y;
    astd::string r;
    astd::string g;
    astd::string b;
    unsigned char r_ = 255;
    unsigned char g_ = 255;
    unsigned char b_ = 255;
    //Add custom support transparent.
    unsigned char a_ = 255;

    for(long unsigned int i = 0; i < Sprite.size(); i++){
        if(Sprite[i] == '[' && Sprite[i+1] == '@' && Sprite[i+2] == 'R' && Sprite[i+3] == ']') {
            i += 4;
            r_ = 255;
            g_ = 255;
            b_ = 255;
        }
        if(Sprite[i] == '[' && Sprite[i+1] == '@'){
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  b+=Sprite[i];
            i++;

            r_ = atoi(r.c_str());
            g_ = atoi(g.c_str());
            b_ = atoi(b.c_str());
            r ="", g = "", b = "";
            }
                
        if(Sprite[i] == '\n') {
            y_ += engine_font.getSize();
            x_=x;
            continue;
        }
        x_+=engine_font.getSize()/2;
        FC_DrawColor(engine_font.getRawFont(), engine_renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
    }
}
void Engine::drawWithBackground(signed int x, signed int y, astd::string Sprite) noexcept {
    signed int x_ = x;
    signed int y_ = y;
    astd::string r;
    astd::string g;
    astd::string b;
    unsigned char r_ = 255;
    unsigned char g_ = 255;
    unsigned char b_ = 255;
    SDL_Rect rect;
    rect.h = engine_font.getSize();
    rect.w = engine_font.getSize() / 2;
    //Add custom support transparent.
    unsigned char a_ = 255;

    for(long unsigned int i = 0; i < Sprite.size(); i++){
        if(Sprite[i] == '[' && Sprite[i+1] == '@' && Sprite[i+2] == 'R' && Sprite[i+3] == ']') {
            i += 4;
            r_ = 255;
            g_ = 255;
            b_ = 255;
        }
        if(Sprite[i] == '[' && Sprite[i+1] == '@'){
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  b+=Sprite[i];
            i++;

            r_ = atoi(r.c_str());
            g_ = atoi(g.c_str());
            b_ = atoi(b.c_str());
            r ="", g = "", b = "";
            }
                
        if(Sprite[i] == '\n') {
            y_ += engine_font.getSize();
            x_=x;
            continue;
        }
        x_+=engine_font.getSize()/2;
        rect.x = x_;
        rect.y = y_;
        SDL_RenderFillRect(engine_renderer, &rect);
        FC_DrawColor(engine_font.getRawFont(), engine_renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
    }
}
void Engine::draw(signed int x, signed int y, const char* Sprite) noexcept {
    signed int x_ = x;
    signed int y_ = y;
    astd::string r;
    astd::string g;
    astd::string b;
    unsigned char r_ = 255;
    unsigned char g_ = 255;
    unsigned char b_ = 255;
    //Add custom support transparent.
    unsigned char a_ = 255;
    utf8_iter ITER;
    utf8_init(&ITER, Sprite);
    for(int i = 0; utf8_next(&ITER); i++) {
        if(Sprite[i] == '[' && Sprite[i+1] == '@' && Sprite[i+2] == 'R' && Sprite[i+3] == ']') {
            i += 4;
            r_ = 255;
            g_ = 255;
            b_ = 255;
        }
        if(Sprite[i] == '[' && Sprite[i+1] == '@') {
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  b+=Sprite[i];
            i++;

            r_ = atoi(r.c_str());
            g_ = atoi(g.c_str());
            b_ = atoi(b.c_str());
            r ="", g = "", b = "";
        }
                
        if(Sprite[i] == '\n') {
            y_ += engine_font.getSize();
            x_=x;
            continue;
        }
        x_+=engine_font.getSize()/2;
        FC_DrawColor(engine_font.getRawFont(), engine_renderer, x_, y_, {r_,g_,b_,a_} ,"%s", utf8_getchar(&ITER));
    }
}
}
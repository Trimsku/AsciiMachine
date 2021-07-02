#include "../../asciiengine/SDL/Font.hpp"

ascii::Font::Font(SDL_Engine *engine, const char* path_to_font, int size) {
    printDebug(LogLevel::Info, "Font %s is created", path_to_font);
    font = FC_CreateFont();
    this->engine = engine;
    this->path_to_font = path_to_font;
    this->size = size;
}

void ascii::Font::LoadFont(int style) {
    if(engine->renderer == nullptr) {
        printDebug(LogLevel::Error,"Please use LoadFont() function with non-nullptr SDL_Engine");
        exit(1);
    }
    if(engine->window == nullptr) {
        printDebug(LogLevel::Error, "Please use LoadFont() function with non-nullptr SDL_Engine");
        exit(1);
    }
    if(!FC_LoadFont(font, engine->renderer, path_to_font, size, FC_MakeColor(255,255,255,255), style)) {
        printDebug(LogLevel::Error, SDL_GetError());
        exit(1);
    }
}

ascii::Font::~Font() {
    FC_FreeFont(font);
}

void ascii::Font::DrawFile(signed int x, signed int y, const char* filename, int spriten) {
    signed int x_ = x;
    signed int y_ = y;
    astd::string Sprite = ascii::util::getFileResources(filename);
    astd::string r;
    astd::string g;
    astd::string b;
    unsigned char r_ = 255;
    unsigned char g_ = 255;
    unsigned char b_ = 255;
    //Add custom support transparent.
    unsigned char a_ = 255;
    int loop = 0;

    for(long unsigned int i = 0; i < Sprite.len(); i++){

        
        if(loop == 0 && Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == spriten) {
            loop++;
            i += 3;
        } else continue;

        if(Sprite[i] == '#' && (Sprite[i+1] - '0') == spriten && Sprite[i+2] == ']') break;

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
            y_ += size;
            x_=x;
            continue;
        }
        x_+=size/2;
        FC_DrawColor(font, engine->renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
    }
}
void ascii::Font::DrawFile(signed int x, signed int y, const char* filename) {
    signed int x_ = x;
    signed int y_ = y;
    astd::string Sprite = ascii::util::getFileResources(filename);
    astd::string r;
    astd::string g;
    astd::string b;
    unsigned char r_ = 255;
    unsigned char g_ = 255;
    unsigned char b_ = 255;
    //Add custom support transparent.
    unsigned char a_ = 255;
    for(long unsigned int i = 0; i < Sprite.len(); i++){

        if(Sprite[i] == '[' && Sprite[i+1] == '@' && Sprite[i+2] == 'R' && Sprite[i+3] == ']') {
            i += 4;
            r_ = 255;
            g_ = 255;
            b_ = 255;
        }
        if(Sprite[i] == '[' && Sprite[i+1] == '@'){
            r ="", g = "", b = "";
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; Sprite[i] != ']'; i++)  b+=Sprite[i];
            i++;
            //TODO: fix bug with [@...]##[@...] -> [@...]]##
            r_ = atoi(r.c_str());
            g_ = atoi(g.c_str());
            b_ = atoi(b.c_str());
        }
                
        if(Sprite[i] == '\n') {
            y_ += size;
            x_= x;
            continue;
        }
        FC_DrawColor(font, engine->renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
        x_+=size/2;
    }
}
void ascii::Font::DrawText(signed int x, signed int y, astd::string Sprite, int sprite) {
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
    int loop = 0;

    for(long unsigned int i = 0; i < Sprite.len(); i++){

        if(loop == 0) {
        if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == sprite) {
            loop++;
            i += 3;
        } else continue;
        }

        if(Sprite[i] == '#' && (Sprite[i+1] - '0') == sprite && Sprite[i+2] == ']') break;

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
            y_ += size;
            x_=x;
            continue;
        }
        x_+=size/2;
        FC_DrawColor(font, engine->renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
    }
}
void ascii::Font::DrawText(signed int x, signed int y, const char* Sprite) {
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
    for(long unsigned int i = 0; i < strlen(Sprite); i++){
        if(Sprite[i] == '[' && Sprite[i+1] == '@' && Sprite[i+2] == 'R' && Sprite[i+3] == ']') {
            i += 4;
            r_ = 255;
            g_ = 255;
            b_ = 255;
        }

        if(Sprite[i] == '[' && Sprite[i+1] == '@'){
            r ="", g = "", b = "";
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;

            while(Sprite[i] == ' ') i++;
            for(; Sprite[i] != ']'; i++)  b+=Sprite[i];
            i++;
            //TODO: fix bug with [@...]##[@...] -> [@...]]##
            r_ = atoi(r.c_str());
            g_ = atoi(g.c_str());
            b_ = atoi(b.c_str());
        }
        if(Sprite[i] == '\n') {
            y_ += size;
            x_= x;
            continue;
        }
        FC_DrawColor(font, engine->renderer, x_, y_, {r_,g_,b_,a_} ,"%c", Sprite[i]);
        x_+=size/2;
    }
}
void ascii::Font::DrawText(signed int x, signed int y, util::SpriteInfo spritei) {

}
void ascii::Font::DrawAnimatedText(signed int x, signed int y, const char* Sprite, int delay_ms) {
    signed int x_ = x;
    signed int y_ = y;
    for(int i = 0; i < strlen(Sprite); i++) {
        if(Sprite[i] == '\n') {
            y_ += size;
            x_= x;
            continue;
        }
        FC_Draw(font, engine->renderer, x_, y_ ,"%c", Sprite[i]);
        x_+=size/2;
        SDL_RenderPresent(engine->renderer);
        SDL_Delay(delay_ms);
    }
}


/*
[@green]

*/
#ifndef IAPP_HPP
#define IAPP_HPP
#include "Engine.hpp"

namespace ascii {
    class IApp : public Engine {
        public:
            void tick(bool *quit);
            void afterInit(bool *quit);
            void catchEvents(SDL_Event e, bool *quit);
    };
}

#ifdef MAIN_INIT_DEF

#define EXECUTE(AppClass) int main(int argc, char **argv) { \
        AppClass run; \
        SDL_Event e; \
        bool quit = false; \
        run.mainInit(&quit, argc, argv); \
        run.afterInit(&quit); \
        while(!quit) { \
            while(SDL_PollEvent(&e)) { \
                run.catchEvents(e, &quit); \
            } \
            if(quit) break; \
            run.tick(&quit); \
        } \
        run.onClose(); \
        return 0; \
    }
#else
    #define EXECUTE(AppClass) int main(int argc, char **argv) { \
        AppClass run; \
        SDL_Event e; \
        bool quit = false; \
        run.afterInit(&quit); \
        while(!quit) { \
            while(SDL_PollEvent(&e)) { \
                run.catchEvents(e, &quit); \
            } \
            if(quit) break; \
            run.tick(&quit); \
        } \
        run.onClose(); \
        return 0; \
    }
#endif

#endif
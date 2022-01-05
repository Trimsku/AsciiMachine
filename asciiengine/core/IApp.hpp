#ifndef IAPP_HPP
#define IAPP_HPP
#include "Engine.hpp"
#include "../astd/Clock.hpp"
#ifdef __EMSCRIPTEN__ 
#include <emscripten.h>
#endif

namespace ascii {
    class IApp : public Engine {
        public:
            void tick(bool *quit);
            void render(double deltaTime);
            void catchEvents(SDL_Event e, bool *quit);
            void processInput(bool *quit);
    };
}

#ifdef MAIN_INIT_DEF

#define EXECUTE(AppClass) int main(int argc, char **argv) { \
        AppClass run; \
        astd::Clock elapsed; \
        double lag = 0.0; \
        SDL_Event e; \
        run.mainInit(&quit, argc, argv); \
        run.afterInit(&quit); \
        while(!run.isClosed()) { \
            lag += elapsed.getEllapsedTime(); \
            while(SDL_PollEvent(&e)) { \
                run.catchEvents(e, &quit); \
            } \
            if(run.isClosed()) break; \
            run.update(); \
            run.render(lag / 8.0D); \
        } \
        return 0; \
    }
#else
    #ifdef __EMSCRIPTEN__
        #define EXECUTE(AppClass) AppClass run; \
        astd::Clock elapsed; \
        double lag = 0.0; \
        SDL_Event e; \
        bool quit = false; \
        void mainLoop() { \
            lag += elapsed.getEllapsedTime(); \
            while(SDL_PollEvent(&e)) { \
                run.catchEvents(e, &quit); \
            } \
            if(quit) emscripten_cancel_main_loop(); \
            run.update(lag / 8.0, &quit); \
            run.render(); \
        } \
        int main(int argc, char **argv) { \
            while(!quit) { \
                emscripten_set_main_loop(mainLoop, 60, 1); \
            } \
            return 0; \
        }
    #else
        #define EXECUTE(AppClass) int main(int argc, char **argv) { \
            AppClass run; \
            astd::Clock elapsed; \
            double lag = 0.0; \
            SDL_Event e; \
            bool quit = false; \
            while(!run.isClosed()) { \
                lag += elapsed.getEllapsedTime(); \
                elapsed.restart(); \
                while(SDL_PollEvent(&e)) run.catchEvents(e); \
                if(run.isClosed()) break; \
                while (lag >= 8.0D) { \
                    run.update(); \
                    lag -= 8.0D; \
                } \
                run.render(lag / 8.0D); \
                SDL_Delay(1); \
            } \
            return 0; \
        }
    #endif
#endif

#endif
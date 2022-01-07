#pragma once
#include "Engine.hpp"
#include "../astd/Clock.hpp"
#ifdef __EMSCRIPTEN__ 
#include <emscripten.h>
#endif

namespace ascii {
    class IApp : public Engine {
        private: 
            astd::container<ascii::client::Shader> shaders;
        public:
            void tick(bool *quit);
            void render(double deltaTime);
            void catchEvents(SDL_Event e, bool *quit);
            inline void addShader(ascii::client::Shader shader) noexcept;
            virtual ascii::client::Shader getCurrentShader() = 0;
    };
    void IApp::addShader(ascii::client::Shader shader) noexcept {
        shaders.push(shader);
    }
}
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
#define EXECUTE(AppClass) void presentBackBuffer(AppClass &app, SDL_Texture* backBuffer, ascii::client::Shader shader) { \
    SDL_SetRenderTarget(app.getRenderer(), NULL); \
	SDL_RenderClear(app.getRenderer()); \
	SDL_GL_BindTexture(backBuffer, NULL, NULL); \
	shader.use(); \
	GLfloat minx = 0.0f, miny = 0.0f, maxx = app.getScrW(), maxy = app.getScrH(); \
	GLfloat minu = 0.0f, maxu = 1.0f, minv = 0.0f, maxv = 1.0f; \
	glBegin(GL_TRIANGLE_STRIP); \
	    glTexCoord2f(maxu, 0.0); glVertex2f(maxx, maxy); \
    	glTexCoord2f(minu, 0.0f); glVertex2f(minx, maxy); \
	    glTexCoord2f(maxu, 1.0f); glVertex2f(maxx, miny); \
    	glTexCoord2f(minu, 1.0f); glVertex2f(minx, miny); \
	glEnd(); \
	SDL_GL_SwapWindow(app.getWindow()); \
	shader.unUse(); \
}\
int main(int argc, char **argv) { \
    AppClass run; \
    astd::Clock elapsed; \
    SDL_Event e; \
    double lag = 0.0; \
    SDL_Texture *texTarget = SDL_CreateTexture(run.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, run.getScrW(), run.getScrH()); \
    while(!run.isClosed()) { \
        lag += elapsed.getEllapsedTime(); \
        elapsed.restart(); \
        while(SDL_PollEvent(&e)) run.catchEvents(e); \
        if(run.isClosed()) break; \
        while (lag >= 8.0) { \
            run.update(); \
            lag -= 8.0; \
        } \
        SDL_SetRenderTarget(run.getRenderer(), texTarget); \
        run.cleanScreen(); \
        run.render(lag / 8.0); \
        presentBackBuffer(run, texTarget, run.getCurrentShader()); \
    } \
    SDL_DestroyTexture(texTarget); \
    return 0; \
}
#endif
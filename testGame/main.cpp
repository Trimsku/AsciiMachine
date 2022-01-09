#include <SDL2/SDL_opengles2.h>
#include "GameApp.hpp"

GameApp run;
astd::Clock elapsed;
double lag;
SDL_Event e;
SDL_Texture *texTarget;

#ifndef __EMSCRIPTEN__
void presentBackBuffer() {
    SDL_SetRenderTarget(run.getRenderer(), NULL);
	SDL_RenderClear(run.getRenderer());
	SDL_GL_BindTexture(texTarget, NULL, NULL);
	run.getCurrentShader().use();
	GLfloat minx, miny, maxx, maxy;
	GLfloat minu, maxu, minv, maxv;
    GLfloat vVertices[] = { 0.0f, 1.0f, 
                            0.0f,-1.0f, 
                           -1.0f, 0.0f, 
                            1.0f,-1.0f, 
                            0.0f };
    // Coordinates
	minx = 0.0f;
	miny = 0.0f;
	maxx = run.getScrW();
	maxy = run.getScrH();
    // I think, these are reversed values
	minu = 0.0f; // 1.0f default
	maxu = 1.0f; // 0.0f default
	minv = 0.0f; // 1.0f default
	maxv = 1.0f; // 0.0f default

    // add and reverse image
	glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(minu, 1.0f);
		glVertex2f(minx, miny);
		glTexCoord2f(maxu, 1.0f);
		glVertex2f(maxx, miny);
		glTexCoord2f(minu, 0.0f);
		glVertex2f(minx, maxy);
		glTexCoord2f(maxu, 0.0f);
		glVertex2f(maxx, maxy);
	glEnd();

	SDL_GL_SwapWindow(run.getWindow());
    run.getCurrentShader().unUse();
}
#endif

#ifdef __EMSCRIPTEN__
void presentBackBuffer() {
    run.presentScreen();
}
void main_loop() {
    lag += elapsed.getEllapsedTime();
    elapsed.restart();
    while(SDL_PollEvent(&e)) run.catchEvents(e); 
    if(run.isClosed()) emscripten_cancel_main_loop();
    while (lag >= 8.0) {
        run.update();
        lag -= 8.0;
    }
    run.cleanScreen();
    run.render(lag / 8.0);
    presentBackBuffer();
}
#endif

int main(int argc, char **argv) {
    lag = 0.0;
    elapsed = astd::Clock();
    texTarget = SDL_CreateTexture(run.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, run.getScrW(), run.getScrH());
    #ifndef __EMSCRIPTEN__
    while(!run.isClosed()) {
        lag += elapsed.getEllapsedTime();
        elapsed.restart();
        while(SDL_PollEvent(&e)) run.catchEvents(e); 
        if(run.isClosed()) break;
        while (lag >= 8.0) {
            run.update();
            lag -= 8.0;
        }
        SDL_SetRenderTarget(run.getRenderer(), texTarget);
        run.cleanScreen();
        run.render(lag / 8.0);
        presentBackBuffer();
    }
    #else
    emscripten_set_main_loop(main_loop, 0, 1);
    exit(0);
    #endif
    SDL_DestroyTexture(texTarget);
    return 0;
}
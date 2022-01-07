#include "GameApp.hpp"

void presentBackBuffer(GameApp &app, SDL_Texture *texTarget) {
    SDL_SetRenderTarget(app.getRenderer(), NULL);
	SDL_RenderClear(app.getRenderer());
	SDL_GL_BindTexture(texTarget, NULL, NULL);
	app.getCurrentShader().use();
	GLfloat minx, miny, maxx, maxy;
	GLfloat minu, maxu, minv, maxv;
	// Coordenadas de la ventana donde pintar.
	minx = 0.0f;
	miny = 0.0f;
	maxx = app.getScrW();
	maxy = app.getScrH();

	minu = 0.0f;
	maxu = 1.0f;
	minv = 0.0f;
	maxv = 1.0f;

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

	SDL_GL_SwapWindow(app.getWindow());
    app.getCurrentShader().unUse();
}

int main(int argc, char **argv) {
    GameApp run;
    astd::Clock elapsed;
    double lag = 0.0;
    SDL_Event e;
    SDL_Texture *texTarget = SDL_CreateTexture(run.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, run.getScrW(), run.getScrH());
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
        presentBackBuffer(run, texTarget);
    }
    SDL_DestroyTexture(texTarget);
    return 0;
}
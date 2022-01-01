#define ON_CLOSE_DEF

#include "../asciiengine/core/IApp.hpp"
#include "MathBits.hpp"
enum mode { //TODO: 
    NormalMode = 1,
    SlideMode = 2,
    Run = 3,
};

class SpriteEditorApp : ascii::IApp {
    private:
        const astd::string context;
        FILE *spriteFilePtr;
        astd::container<astd::string> lines;
        int currentLine = 0;
        int currentChar = 0;
        astd::string cursorStyle = "[@100,100,100]$";
        char inputSymbol;
    public:
        SpriteEditorApp();
        void mainInit(bool *quit, int argc, char **argv);
        void tick(bool *quit);
        void afterInit(bool *quit);
        void catchEvents(SDL_Event e, bool *quit);
        void onClose();
};

SpriteEditorApp::SpriteEditorApp() : context("Please, specify a file name. \n\tUsage: ./se-editor [OPTION] file-name \n\t-n   --new: create new file.\n\t-o   --open: open file(specify ONLY name, not extension).\n") {
    createWindow("SpriteEditor", 1920, 1080);
    loadFont("resources/fonts/10894.otf", 50, ascii::style::normal);
}


void SpriteEditorApp::mainInit(bool *quit, int argc, char **argv) {
    if(argc <= 1) {
        printf("%s", context.c_str());
        exit(0);
    } else {
        if(strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--new") == 0 && argc == 2) {
            printf("Create new file...: ");
            if ((spriteFilePtr = fopen(argv[2], "r")) != NULL) {
                printf("File already exists\n");
                *quit = true;
                return;
            } else if((spriteFilePtr = fopen(argv[2], "w+")) != NULL) printf("OK.\n");

        } else if(strcmp(argv[1], "-o") == 0 || strcmp(argv[1], "--open") == 0) {
            printf("Open file...: ");
            if ((spriteFilePtr = fopen(argv[2], "a+")) == NULL) {
                printf("File doesn't exist\n");
                *quit = true;
                return;
            } else printf("OK.\n");
        } else {
            printf("%s", context.c_str());
            *quit = true;
        }
    }
    SDL_StartTextInput();
}

void SpriteEditorApp::catchEvents(SDL_Event e, bool *quit) {
    if ( is_event(QUIT) ) { *quit = true; }
    if ( is_event(TEXTINPUT) ) {
        inputSymbol = e.text.text[0];
        std::string test;
        test += inputSymbol;
        lines[currentLine].replace(currentChar, currentChar, test);
        SDL_Delay(50);
    }
}

void SpriteEditorApp::tick(bool *quit) {
    cleanScreen();
    if ( is_key_pressed(ESCAPE) ) *quit = true;
    if( is_key_pressed(BACKSPACE)) {
        lines[currentLine][currentChar] = ' ';
        currentChar -= math::min(currentChar, 1);
        SDL_Delay(120);
    }
    if ( is_key_pressed(UP) ) {
        currentLine -= math::min(currentLine, 1);
        while(currentLine >= lines.size()) lines.push("");
        SDL_Delay(60);
    }
    if ( is_key_pressed(DOWN) ) {
        currentLine += 1;
        while(currentLine >= lines.size()) lines.push("");
        SDL_Delay(60);
    }
    if ( is_key_pressed(LEFT) ) { 
        currentChar -= math::min(currentChar, 1);
        while(currentLine > lines.size()) lines.push("");
        while(currentChar > lines[currentLine].size()) lines[currentLine] += ' ';
        SDL_Delay(120);
    }
    if ( is_key_pressed(RIGHT) ) {
        currentChar += 1;
        while(currentLine > lines.size()) lines.push("");
        while(lines[currentLine].size() < currentChar) lines[currentLine] += ' ';
        SDL_Delay(120);
    }
    draw(currentChar * 25, currentLine * 50, cursorStyle);
    printf("Draw: \n");
    for(int i = 0; i < lines.size(); i++) {
        printf("%s \n", lines[i].c_str());
        draw(0, i * 50 + 50, lines[i]);
    }
    presentScreen();
    SDL_Delay(500);
}

void SpriteEditorApp::onClose() {
    SDL_StopTextInput();
    fclose(spriteFilePtr);
}

void SpriteEditorApp::afterInit(bool *quit) {
}

EXECUTE(SpriteEditorApp);
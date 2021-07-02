#include "include/SDL/Font.hpp"
enum mode { //TODO: 
    NormalMode = 1,
    SlideMode = 2,
    Run = 3,
};

/*int getCurrentIndex(astd::string *SpriteFile, int cursorX, int cursorY) {
    int line = 0;
    int column = 0;
    int currentLine = cursorY / 50;
    int currentColumn = cursorX / 25;
    int i = 0;

    for(; currentLine != line; i++) {
        if(*SpriteFile[i] == '\n') line++;
    }
    for(; currentColumn != column; i++, column++);
    return i;
}

astd::string formate(astd::string &file, int correct_lines, int fill_number) {
    astd::string *FormatFile;
    for(int i = 0; i < correct_lines; i++) {
        for(int j = 0; j < fill_number; j++) {
            FormatFile += ' ';
        }
        FormatFile += '\n';
    }
    for(int i = 0; i < file.len(); i++) {
        FormatFile[i] = file[i];
    }
    return *FormatFile;
}

astd::string setCharOnXY(astd::string *SpriteFile, int cursorX, int cursorY, char symbol) {
    int i = getCurrentIndex(SpriteFile, cursorX, cursorY);
    //astd::print("\n\nDEBUG:(len:%d, i:%d)\n\n", SpriteFile.len(), i);
    astd::string SFile;
    SFile += *SpriteFile;
    SFile += ' ';
    for(int j = SpriteFile->len(); j > i; j--) {
        SFile[j] = SFile[j-1];
    }
    SFile[i] = symbol;
    return *SpriteFile;
}

astd::string removeCharFromCursor(astd::string *SpriteFile, int cursorX, int cursorY) {
    int i = getCurrentIndex(SpriteFile, cursorX, cursorY);
    for(int j = i; j < SpriteFile->len(); j++) {
        SpriteFile[j] = SpriteFile[j+1];
    }
    return *SpriteFile;
}
#define removeChar NoColorText = removeCharFromCursor(&NoColorText, cursorX-25, cursorY)
#define setChar(symbol) NoColorText = setCharOnXY(&NoColorText, cursorX, cursorY, symbol)
#define getIndex getCurrentIndex(NoColorText, cursorX, cursorY)*/
#define Update(ms) SDL_Delay(ms); \
            is_update = true;
/*#define init() astd::string window_name = "SpriteEditor ~ ";\
    window_name += argv[2];\
    ascii::SDL_Engine Engine;\
    Engine.init();\
    Engine.createWindow(window_name.c_str(), 1920, 1080);\
\
    ascii::Font font(&Engine, "res/fonts/10894.otf", 50);\
    font.LoadFont(ascii::style::italic);\
    astd::print("\n");*/

int main(int argc, char **argv) {
    astd::string context("Please, specify a file name. \n\
    \tUsage: ./se-editor [OPTION] file-name \n\
    \t-n   --new: create new file.\n\
    \t-o   --open: open file(specify ONLY name, not extension).\n");

    FILE *spritefile_ptr;
    astd::string SpriteFile("");
    astd::string NoColorText("");
    int cursorX = 0;
    int cursorY = 0;

    if(argc <= 1) {
        astd::print("%s", context);
        exit(0);
    } else {
        if(strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--new") == 0 && argc == 2) {
            astd::print("Create new file...: ");
            if ((spritefile_ptr = fopen(argv[2], "r")) != NULL) {
                astd::print("File already exists");
                if(argv[2] != NULL) { 
                    fclose(spritefile_ptr);
                }
                exit(0);
            } else {
                if((spritefile_ptr = fopen(argv[2], "w+")) == NULL) {
                    astd::print("OK.\n");
                }
            }
        } 
        if(strcmp(argv[1], "-o") == 0 || strcmp(argv[1], "--open") == 0) {
            astd::print("Open file...: ");
            if ((spritefile_ptr = fopen(argv[2], "a+")) == NULL) {
                astd::print("File doesn't exist\n");
                exit(0);
            } else {
                astd::print("OK.\n");
            }

        } else {
            astd::print("%s", context);
            exit(0);
        }
    }

    //init()
    astd::string window_name("SpriteEditor ~ ");
    /*window_name += argv2;*/
    
    ascii::SDL_Engine Engine;
    Engine.init();
    Engine.createWindow(window_name, 1920, 1080);

    ascii::Font font(&Engine, "res/fonts/10894.otf", 50);
    font.LoadFont(ascii::style::italic);
    astd::print("\n");

    astd::string cursorStyle("[@100,100,100]$");
    
    SpriteFile = ascii::util::getFileResources(argv[2]);
    //NoColorText = formate(&SpriteFile, 20, 120);
    bool is_update = true;
    char input_symbol;
    SDL_StartTextInput();
    game_while{
        while(event_while) {
            if ( is_event(QUIT) ) { game_while_close; }
            if ( is_event(TEXTINPUT) ) {
                input_symbol = e.text.text[0];
                //setChar(input_symbol);
                Update(60);
            }
        }
        if ( is_key_pressed(ESCAPE) ) game_while_close;
        if( is_key_pressed(BACKSPACE) && e.key.repeat == 0) {
            if(cursorX >= 25) {
                //removeChar;
            }
            cursorX -= 25;
            Update(60);
        }
        if ( is_key_pressed(UP) ) {
            cursorY -= 50;
            Update(60);
        }
        if ( is_key_pressed(DOWN) ) {
            cursorY += 50;
            Update(60);
        }
        if ( is_key_pressed(LEFT) ) { 
            cursorX -= 25;
            Update(120);
        }
        if ( is_key_pressed(RIGHT) ) {
            cursorX += 25;
            Update(120);
        }
        if(is_update) {
            SDL_RenderClear(Engine.renderer);
            font.DrawText(0,0, NoColorText.c_str());
            font.DrawText(cursorX, cursorY, cursorStyle.c_str());
            SDL_RenderPresent(Engine.renderer);
            is_update = false;
        }
    }
    SDL_StopTextInput();
    fclose(spritefile_ptr);
    return 0;
}
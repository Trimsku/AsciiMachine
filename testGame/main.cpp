// For text, debug, color, SDL_wrapper, etc.
#include "../asciiengine/SDL/Font.hpp"
#include "../asciiengine/Rect.hpp"
#include "../asciiengine/astd/Clock.hpp"
#include "Defines.hpp"
enum State {
    Stand = 1,
    Left = 2,
    Right = 3,
    None = 4,
};

int main()
{
    int state = State::Stand;
    int part_number = 0;
    ascii::printDebug(ascii::LogLevel::Debug, "[[INITILIZATION]]\n\n");

    astd::string GodsEnvoy_s = ascii::util::getFileResources("res/textures/GodsEnvoy.txt");
    astd::string PlayerRight = ascii::util::getFileResources("res/textures/PlayerRight.txt");
    astd::string PlayerLeft = ascii::util::getFileResources("res/textures/PlayerLeft.txt");
    astd::string PlayerStand = ascii::util::getFileResources("res/textures/PlayerStand.txt");
    astd::string tram_station_0 = ascii::util::getFileResources("res/textures/TramStation0.txt");
    astd::string tram_station_aeromald = ascii::util::getFileResources("res/textures/AeromaldTramStation.txt");
    astd::string tram = ascii::util::getFileResources("res/textures/Tram.txt");
    //Initilization Engine, window.
    int x = 25, y = 300;
    ascii::SDL_Engine Engine;
    Engine.init();
    Engine.createWindow("Ascii-G" ,1920,1080);
    astd::string railway("[@128, 119, 119]");
    astd::string pillar("[@41, 40, 38]\\|/\n |\n |\n |\n |");
    astd::string pillar_line("[@41, 40, 38]");
    for(int x = 0; x < 1921; x += 75) {
        pillar_line += "---";
    }

    for(int x = 0; x < 1921; x+=75) {
        if(x != 150) {
            railway += "___";
        } else {
            railway += " __";
        }
    }
    railway += '\n';
    for(int x = 0; x < 1921; x+=75) {
        if(x != 150) {
            railway += "[@128, 119, 119]__[@59, 38, 0]/";
        } else {
            railway += "[@128, 119, 119] _[@59, 38, 0]/";
        }
    }
    astd::string railway1;
    railway1 += "[@128, 119, 119]";
    for(int x = 14*25; x < 1921; x+=75) {
        railway1 += "|__";
    }
    ascii::Rect_i door(600, 300, 675, 500);
    ascii::Rect_i playerH(x, y, x+75, y+200);
    ascii::Rect_i GodsEnvoy(150, 250, 200, 400);
    ascii::Rect_i AeromaldStairs0(200, 350, 300, 400);
    ascii::Rect_i AeromaldStairs1(500, 350, 1200, 400);
    ascii::Rect_i AeromaldStairs2(55*25, 350, 55*25 + 100,400);
    bool gods_envoy = false;
    bool is_tram_move = false;
    int tram_x = 200, tram_y = 100;
    astd::Clock playerAnimated_c;
    astd::Clock playerStand_c;
    int playerAnimated_ns = 1;
    int playerStand_ns = 1;
    // Create Font class
    ascii::Font font(&Engine, "res/fonts/10894.otf", 50);
    font.LoadFont(ascii::style::normal);
    //Debug
    ascii::printDebug(ascii::LogLevel::Debug, "\n[[GAME_WHILE]]\n");
    SDL_RenderClear(Engine.renderer);
    /*font.DrawAnimatedText(500, 400, "Hello. This is Ascii-G. Adventure with RPG elements.", 100);
    font.DrawAnimatedText(500, 450, "Use left, right, up and down for move.", 50);
    font.DrawAnimatedText(500, 500, "Use _______________", 50);
    font.DrawAnimatedText(500, 550, "   |             | |", 25);
    font.DrawAnimatedText(500, 600, "   |  /__________| |", 25);
    font.DrawAnimatedText(500, 650, "   |  \\            |", 25);
    font.DrawAnimatedText(500, 700, "   |________________| (button return) for shops,  ", 50);
    font.DrawAnimatedText(1250, 750, "tram, cars, buttons and i.e", 25);
    font.DrawAnimatedText(500, 800, "Okay, soon, we .nia gauo yte emlliw", 25);
    font.DrawAnimatedText(500, 850, "Go to the tram, hero.", 50);
    font.DrawAnimatedText(500, 900, "[Return]", 50);
    {
        game_while {
            SDL_PollEvent(&e);
            if(is_key_pressed(RETURN)) game_while_close;
        }
    }*/
    //game_while - 
    //SDL_ShowCursor(0);
    SDL_RenderClear(Engine.renderer);
    game_while
    {
        
        if(playerAnimated_c.getEllapsedTime() >= 100) {
            playerAnimated_ns++;
            if(playerAnimated_ns > 4){
                playerAnimated_ns = 1;
            }
            playerAnimated_c.restart();
        } 
        if(playerStand_c.getEllapsedTime() >= 800) {
            playerStand_ns++;
            if(playerStand_ns > 4){
                playerStand_ns = 1;
            }
            playerStand_c.restart();
        }
        // events
        while(event_while) {
            if ( is_event(QUIT) ) game_while_close;
        }
        if ( is_key_pressed(Q) ) game_while_close;
        state = State::Stand;
        if(part_number == 0) {
            if( is_key_pressed(RIGHT) && x <= 1350) {
                x += 8; playerH = playerH + ascii::Vector2i(8,0);
                state = State::Left;
            } else if ( is_key_pressed(LEFT) && x >= 25 ) {
                x -= 8; playerH = playerH - ascii::Vector2i(8,0);
                state = State::Left;
            }
            if( is_key_pressed(O)) {
                part_number++;  
                SDL_Delay(100);
            } 
            main_menu;
            if(part_number == 1) {
                SDL_RenderClear(Engine.renderer);
                font.DrawAnimatedText(500, 500, "Aeromald", 100);
                tram_x = 1921;
                tram_y = 0;
                SDL_Delay(1000);
                SDL_RenderClear(Engine.renderer);
                font.DrawText(0, 200, railway.c_str());
                font.DrawText(0,0, tram_station_aeromald.c_str());
                for(int i = 1921; i > 300; ) {
                    part_number0_title
                    //SDL_Delay(100);
                }
                x = tram_x + 375;
                y = tram_y + 200;
                playerH = ascii::Rect_i(x, y, x+75, y+200);

                SDL_Delay(1000);
            }
        } else if(part_number == 1) {
            if( is_key_pressed(RIGHT) && x <= 59*25) {
                x += 8; playerH = playerH + ascii::Vector2i(8,0);
                state = State::Right;
            } else if ( is_key_pressed(LEFT) && x >= 25 ) {
                x -= 8; playerH = playerH - ascii::Vector2i(8,0);
                state = State::Left;
            }
            font.DrawText(0, 250, railway.c_str());
            Engine.FillIn(tram_x+12, tram_y + 150, 21*25-12, 188); 
            font.DrawText(tram_x, tram_y, tram.c_str()); 
            font.DrawText(0,0, tram_station_aeromald.c_str());

            if(ascii::isCollision(playerH, AeromaldStairs0) || ascii::isCollision(playerH, AeromaldStairs1) || ascii::isCollision(playerH, AeromaldStairs2)) {
                if( is_key_pressed(DOWN) && y < 350 && e.key.repeat == 0) {
                    y += 50;
                    playerH = playerH + ascii::Vector2i(0, 50);
                    SDL_Delay(100);
                } else if(is_key_pressed(UP) && y > 250 &&  e.key.repeat == 0) {
                    y -= 50;
                    playerH = playerH - ascii::Vector2i(0, 50);
                    SDL_Delay(100);
                } else if(is_key_pressed(UP) && y == 250 &&  e.key.repeat == 0) {
                    font.DrawText(x, y-50, "Oh... leg... hurts");
                    SDL_Delay(100);
                };
            }

            if(state == State::Right) { 
                font.DrawText(x, y, PlayerRight.c_str(), playerAnimated_ns); 
            } else if(state == State::Left) { 
                font.DrawText(x, y, PlayerLeft.c_str(), playerAnimated_ns); 
            } else if(state == State::Stand) {
                font.DrawText(x, y, PlayerStand.c_str(), playerStand_ns); 
            }
        }
        SDL_RenderPresent(Engine.renderer); 
        SDL_RenderClear(Engine.renderer); 
    }
    ascii::printDebug(ascii::LogLevel::Debug, "\n\n[[DESTRUCT]]\n\n");
    return 0;
}
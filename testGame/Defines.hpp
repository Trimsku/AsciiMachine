#define main_menu \
        for(int x = 0; x < 1921; x+=18*25) { \
            font.draw(x, 150, pillar.c_str()); \
        } \
        font.draw(14*25,450, railway1.c_str()); \
        font.draw(0, 125, pillar_line.c_str()); \
        Engine.fillIn(0, 14*25, 1450, 150); \
        font.draw(0, 350, railway.c_str()); \
        font.draw(0, 0, tram_station_0.c_str()); \
        if(x >= 125) { \
            font.draw(125, 300, GodsEnvoy_s.c_str(), 2); \
        } else { \
            font.draw(125, 300, GodsEnvoy_s.c_str(), 1); \
        } \
        if(gods_envoy == false) { \
        if(ascii::isCollision(GodsEnvoy, playerH)) { \
            Engine.fillIn(tram_x+12, tram_y + 150, 21*25-12, 188); \
            font.draw(tram_x, tram_y, tram.c_str()); \
            font.draw(x, y, PlayerStand.c_str(), 1); \
            font.drawAnimatedText(500, 300, "Oh.", 500);\
            font.drawAnimatedText(500, 350, "Where did you come from?", 100);\
            font.drawAnimatedText(500, 400, "Okay...", 100); \
            font.drawAnimatedText(500, 450, "(...Go to the tram from this guy...)", 100); \
            gods_envoy = true;\
        } \
        } \
        if(is_tram_move == false) { \
            Engine.fillIn(tram_x+12, tram_y + 150, 21*25-12, 188); \
            font.draw(tram_x, tram_y, tram.c_str()); \
            if( is_key_pressed(RIGHT)) { \
                x += 8; playerH = playerH + ascii::Vector2i(8,0); \
                state = State::Right; \
            } else if ( is_key_pressed(LEFT)) { \
                x -= 8; playerH = playerH - ascii::Vector2i(8,0); \
                state = State::Left; \
            } \
            if(ascii::isCollision(door, playerH)) { \
                if ( is_key_pressed(RETURN)) { \
                    is_tram_move = true; \
                } \
                font.draw(tram_x+300, tram_y+150, "[Return]");\
            } \
            if(state == State::Right) {  \
                font.draw(x, y, PlayerRight.c_str(), playerAnimated_ns); \
            } else if(state == State::Left) {  \
                font.draw(x, y, PlayerLeft.c_str(), playerAnimated_ns); \  
            } else if(state == State::Stand) { \
                font.draw(x, y, PlayerStand.c_str(), playerStand_ns);  \
            } \ 
        } else { \
            Engine.fillIn(tram_x+12, tram_y + 150, 21*25-12, 188); \
            font.draw(tram_x, tram_y, tram.c_str()); \
            font.draw(x, y, PlayerStand.c_str(), 1); \
            Engine.fillIn(x, y, 100, 200);\
            font.draw(x, y, PlayerRight.c_str(), 3);\
            SDL_RenderPresent(Engine.renderer); \
            SDL_Delay(500); \
            SDL_RenderPresent(Engine.renderer); \
            for(int i = 200; i > -1000; i-=25, tram_x -= 25) { \
                font.draw(14*25,450, railway1.c_str()); \
                font.draw(0, 125, pillar_line.c_str()); \
                Engine.fillIn(0, 14*25, 1450, 150); \
                font.draw(0, 350, railway.c_str()); \
                font.draw(0, 0, tram_station_0.c_str()); \
                Engine.fillIn(tram_x+12, tram_y + 150, 21*25-12, 188); \
                font.draw(tram_x, tram_y, tram.c_str()); \
                font.draw(125, 300, GodsEnvoy_s.c_str(), 1); \
                font.draw(tram_x+375, tram_y+150, PlayerStand.c_str(), 1); \
                SDL_RenderPresent(Engine.renderer); \
                SDL_RenderClear(Engine.renderer); \
                SDL_Delay(100); \
            } \
            part_number++; \
        }

#define part_number0_title \
    SDL_RenderClear(Engine.renderer); \
    if(i > 900) { i -= 25; tram_x -= 25;} \
    else if(i > 500) {i -= 13; tram_x -= 13; } \
    else { i -= 6; tram_x -= 6; } \
    font.draw(0, 250, railway.c_str()); \
    Engine.fillIn(tram_x+12, tram_y + 150, 21*25-12, 188); \
    font.draw(tram_x, tram_y, tram.c_str()); \
    font.draw(0,0, tram_station_aeromald.c_str()); \
    font.draw(tram_x+375, tram_y+150, PlayerStand.c_str(), 1); \
    SDL_RenderPresent(Engine.renderer); 
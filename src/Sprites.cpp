Sprite::Sprite(){
    logs.writeLog("Sprite class is created");
}
Sprite::~Sprite(){
    logs.writeLog("Sprite class is destroyed");
}

/**
 * @brief 
 * 
 * @param sprite 
 * @param window for window
 * @param x 
 * @param y 
 * @param SpriteNum 
 */
void Sprite::loadSprite(sf::Text sprite, float x, float y, int SpriteNum = 1){
    std::string Sprite = sprite.getString();
    int saveX = x;
    int loop = 0;
    std::string r,g,b, size;
    for(int i = 0; i < Sprite.length(); i++){
        sprite.setPosition(x,y);
        if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == SpriteNum) {
            loop++;
            i+=3;
        }
        if(Sprite[i] == '#' && (Sprite[i+1] - '0') == SpriteNum && Sprite[i+2] == ']') break;

        if(loop == 1){
            
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

                sprite.setFillColor(sf::Color( convertStringToInt(r), convertStringToInt(g), convertStringToInt(b)));
                r ="", g = "", b = "";
            }
            if(Sprite[i] == '\n') {
                //Sprite[i] = ' ';
                y += sprite.getCharacterSize();
                x=saveX;
                sprite.setPosition(x, y); 
                continue;
            }
        x+=sprite.getCharacterSize()/2;
        sprite.setPosition(x,y);
        
        sprite.setString(Sprite[i]);	
        window.draw(sprite);
        }
    }
}
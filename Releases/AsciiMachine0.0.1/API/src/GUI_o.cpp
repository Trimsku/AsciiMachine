#include "../include/GUI_o.hpp"
#include "../include/utils.hpp"
std::string ascii::GUI_o::getName(){
    return name;
}

ascii::GUI_o::GUI_o(std::string name_)
{
    name = name_;
}

void ascii::GUI_o::setGlobalXY(int x_, int y_){
    coords.global_x = x_;
    coords.global_y = y_;
}

int ascii::GUI_o::getX(){
    return coords.global_x;
}
int ascii::GUI_o::getY(){
    return coords.global_y;
}

void ascii::GUI_o::MoveX(float x_) {
    coords.global_x += (x_);
}
void ascii::GUI_o::MoveY(float y_) {
    coords.global_y += (y_);
}

//! ******************
//!       Signal 
//! ******************

bool ascii::GUI_o::is_connect(std::string message){
    for(auto& signal_ : signal_out ){
        if(signal_ == (getName()+"::"+message)){
            return true;
        }
    }
    return false;
}

void ascii::GUI_o::send(std::string message){
    signal_out.push_back(getName()+"::"+message);
}

void ascii::GUI_o::printSignals(){
    std::cout<<'\n';
    for(auto& signal_ : signal_out ){
        std::cout << signal_<<'\n';
    }
    std::cout<<'\n';
}

//! *****************************************
//!          Animation and sprites.
//! *****************************************


bool ascii::GUI_o::isOneSprite(std::string fsprite){
    for(int i = 0; i < fsprite.length(); i++) {
        if(fsprite[i] == '[' && fsprite[i+1] == '#' && fsprite[i+2] == '1') {
            return false;
        }
    }
    return true;
}

void ascii::GUI_o::loadSprite(std::string name, sf::RenderTarget* window, int sprite_num_) {
    int x_ = getX();
    int y_ = getY();
    int loop;
    // Init sprite_ for working. Start
    sf::Text sprite_;
    int j;
    if(name != "anonymous") {
        j = 0;
        for(auto& sprite : spritesNames) {
            if(sprite == name) {
                sprite_  = sprites[j];
                break;
            }
            j++;
        } 
    } else {
        j = spritesNames.size() - 1;
        for(; j > 0; j--){
            if(spritesNames[j] == "anonymous"){
                sprite_ = sprites[j];
                break;
            }
        }
    }
    std::string Sprite = sprite_.getString();

    bool is1sprite = isOneSprite(Sprite);
    int saveX = x_;
    std::string r,g,b, size;

    if ( is1sprite ) loop = 1;
    else loop = 0;

    for(int i = 0; i < Sprite.length(); i++){
        sprite_.setPosition(x_,y_);

        if( is1sprite == false ) {
            if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == sprite_num_) {
                loop++;
                i+=3;
            }
            if(Sprite[i] == '#' && (Sprite[i+1] - '0') == sprite_num_ && Sprite[i+2] == ']') break;
        }

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

                sprite_.setFillColor(sf::Color( convertStringToInt(r), convertStringToInt(g), convertStringToInt(b)));
                r ="", g = "", b = "";
                }
                
            if(Sprite[i] == '\n') {
                y_ += sprite_.getCharacterSize();
                x_=saveX;
                sprite_.setPosition(x_, y_); 
                continue;
            }
            x_+=sprite_.getCharacterSize()/2;
            sprite_.setPosition(x_ ,y_);
        
            sprite_.setString(Sprite[i]);	
            window->draw(sprite_);
        }
    }
    /*else {

        for(int i = 0; i < Sprite.length(); i++){
            sprite_.setPosition(x_,y_);
        
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

                sprite_.setFillColor(sf::Color( convertStringToInt(r), convertStringToInt(g), convertStringToInt(b)));
                r ="", g = "", b = "";
            }
            if(Sprite[i] == '\n') {
                y_ += sprite_.getCharacterSize();
                x_=saveX;
                sprite_.setPosition(x_, y_); 
                continue;
            }
            x_+=sprite_.getCharacterSize()/2;
            sprite_.setPosition(x_ ,y_);
        
            sprite_.setString(Sprite[i]);	
            window->draw(sprite_);
        }
    }*/
}


void ascii::GUI_o::newSprites(std::string path_to_file, std::string name, int size) {
    sf::Text textureInfo(ascii::getFileResources(path_to_file), font, size );
    sprites.push_back(textureInfo);
    spritesNames.push_back(name);
}


bool ascii::GUI_o::isFontLoaded(std::string path_to_file) {
    if(!font.loadFromFile(path_to_file)) {
        std::cout<<"FONT NOT LOADED\n";
        exit(0);
    }
    else{
        return true;
    }
    exit(0);
}

void ascii::GUI_o::clearSprites(){
    sprites.clear();
    sprites.shrink_to_fit();
    spritesNames.clear();
    spritesNames.shrink_to_fit();
}
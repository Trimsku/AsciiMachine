#include "../include/GUI_o.hpp"
#include "../include/utils.hpp"

ascii::GUI_o::~GUI_o() {}

ascii::GUI_o::GUI_o(std::string name_)
{
    name = name_;
} 

std::string ascii::GUI_o::getName(){
    return name;
}

void ascii::GUI_o::setGlobalXY(float x_, float y_){
    g_coords.global_x = x_;
    g_coords.global_y = y_;
}

signed int ascii::GUI_o::getX(){
    return g_coords.global_x;
}
signed int ascii::GUI_o::getY(){
    return g_coords.global_y;
}

void ascii::GUI_o::MoveX(float x_) {
    g_coords.global_x += (x_);
}
void ascii::GUI_o::MoveY(float y_) {
    g_coords.global_y += (y_);
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


// Give name of sprite: newSprites(path_to_file, name /*<--------- this name*/)
void ascii::GUI_o::loadSprite(std::string name, sf::RenderTarget* window, int sprite_num_) {
    signed int x_;
    signed int y_;
    if(!local_coords_x_on) {
        if(getX() < 0 ) {
            x_ = getX() + getDisplayWidth() * (ascii::getChunkX( getX() ) + 1);
        }
        else{
            x_ = getX() - getDisplayWidth() * (ascii::getChunkX( getX() ) - 1);
        }
    } else {
        x_ = g_coords.global_x;
    }
    if (getY() < 0 ) {
        y_ = getY() + getDisplayHeight() * (ascii::getChunkY( getY() ) + 1);
    }
    else{
        y_ = getY() - getDisplayHeight() * (ascii::getChunkY( getY() ) - 1);
    }
    int loop;
    // Init sprite_ for working. Start
    // Look for "name" in vector sprites.
    // For example "PlayerStand" - name, and program lookfor "PlayerStand".
    sf::Text sprite_;
    long unsigned int j;
    if(name != "anonymous") {
        j = 0;
        for(auto& sprite : sprites) {
            if(sprite.second == name) {
                sprite_  = sprites[j].first;
                break;
            }
            j++;
        } 
    } else {
        j = sprites.size() - 1;
        for(; j > 0; j--){
            if(sprites[j].second == "anonymous"){
                sprite_ = sprites[j].first;
                break;
            }
        }
    }
    std::string Sprite = sprite_.getString();

    bool is1sprite = ascii::isOneSprite(Sprite);
    float saveX = x_;
    std::string r,g,b, size;

    if ( is1sprite ) loop = 1;
    else loop = 0;

    for(long unsigned int i = 0; i < Sprite.length(); i++){
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

                sprite_.setFillColor(sf::Color( convertStringToInt<sf::Uint8>(r), convertStringToInt<sf::Uint8>(g), convertStringToInt<sf::Uint8>(b) ) );
                r ="", g = "", b = "";
                }
                
            if(Sprite[i] == '\n') {
                y_ += static_cast<float>(sprite_.getCharacterSize());
                x_=saveX;
                sprite_.setPosition(x_, y_); 
                continue;
            }
            x_+=static_cast<float>(sprite_.getCharacterSize()/2);
            sprite_.setPosition(x_ ,y_);
        
            sprite_.setString(Sprite[i]);	
            window->draw(sprite_);
        }
    }
}


void ascii::GUI_o::newSprites(std::string filename, bool is_file) {
    sf::Text textureInfo;
    if( is_file ) {
        textureInfo = { ascii::getFileResources(config.path_to_main+"textures/"+filename+".rtxt"), font, config.global_size };
    } else {
        textureInfo = { filename, font, config.global_size };
    }
    if(is_anonymous_o == True) {
        sprites.push_back({textureInfo, "anonymous"});
    } else {
        sprites.push_back({textureInfo, filename});
    }
}


void ascii::GUI_o::isFontLoaded(std::string fontname) {
    if(!font.loadFromFile(config.path_to_main+"font/"+fontname)) {
        std::cout<<"FONT NOT LOADED in "<<getName()<<'\n';
        exit(0);
    }
}

sf::Text ascii::GUI_o::getElement(int element_c) {
    if( 0 > element_c || element_c > sprites.size()){
        std::cout<<"ascii::GUI_o::getElement("<<element_c<<"), but "<<(element_c<0?"smaller than 0":"greater than sprites.size()")<<'\n';
        exit(0);
    }
    return sprites[element_c].first;
}

void ascii::GUI_o::setAnonymous() {
    is_anonymous_o = true;
}
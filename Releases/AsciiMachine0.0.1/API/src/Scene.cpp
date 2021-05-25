#include "../include/Scene.hpp"


void ascii::Scene::setWidthAndHeight(int width_, int height_) {
    widthOfScreen = width_;
    heightOfScreen = height_;
}


void ascii::Scene::PushObject(GUI_o object, bool createcopy) {
    bool copy = false;
    int i = 0;
    if( createcopy == false ) {

        for(auto &object_ : Objects){
            if(object_.getName() == object.getName() ){
                copy = true;
                break;
            }
            i++;
        }

    }
    if( copy ) {
        Objects[i] = object;
        CoordsOfObjects[i].local_x = object.getX() - ( getChunkX ( object.getX() ) - 1 ) * widthOfScreen; 
        CoordsOfObjects[i].local_y = object.getY() - ( getChunkY ( object.getY() ) - 1 ) * heightOfScreen;
        CoordsOfObjects[i].x_chunk = getChunkX( object.getX() );
        CoordsOfObjects[i].y_chunk = getChunkY( object.getY() );
    }
    else {
        Objects.push_back(object);
        Vector2dlocalInfo info;
        info.local_x = object.getX() - ( getChunkX ( object.getX() ) - 1 ) * widthOfScreen; 
        info.local_y = object.getY() - ( getChunkY ( object.getY() ) - 1 ) * heightOfScreen;
        info.x_chunk = getChunkX( object.getX() );
        info.y_chunk = getChunkY( object.getY() );
        CoordsOfObjects.push_back(info);
    }
}

int ascii::Scene::getChunkX( int global_x ) {
    int chunk = 1;
    int x = global_x;
    while( !(x <= widthOfScreen) ){
        x -= widthOfScreen;
        chunk++;
    }
    return chunk;
}

int ascii::Scene::getChunkY( int global_y ) {
    int chunk = 1;
    int y = global_y;
    while( !(y <= heightOfScreen) ){
        y -= heightOfScreen;
        chunk++;
    }
    return chunk;
}

/*void ascii::Scene::pushAnonymousObject(std::string path_to_file, int global_x, int global_y, bool createcopy, std::string path_to_font){
    std::string name = "anonym"+(char)(__COUNTER__+'0');
    GUI_o anonymousObject(name);
    anonymousObject.setGlobalXY(global_x, global_y);
    anonymousObject.isFontLoaded(path_to_font);
    anonymousObject.newSprites(path_to_file, name, size);
    PushObject(anonymousObject, createcopy);
}*/



void ascii::Scene::DrawMap(/*sf::RenderWindow* window*/) {
    int j = 0;
    int counter = 0;
    std::cout << '\n';
    for (auto &i : CoordsOfObjects)
    {
        if(i.x_chunk == x_chunk_now && i.y_chunk == y_chunk_now){
            Objects[j].loadSprite(Objects[j].getName(), &ttexture);
            if(Objects[j].getName() == Objects[j+1].getName()){
                counter++;
            } else {
                if(counter == 0){
                    std::cout<<"Object name['"<<Objects[j].getName()<<"'] is loaded\n";
                }
                else {
                    std::cout<<"Object name['"<<Objects[j].getName()<<"'] is loaded "<<counter<<" times\n";
                    counter = 0;
                }
            }
        }
        j++;
    }
    std::cout<<'\n';
    ttexture.display();
}

void ascii::Scene::ClearMap() {
    ttexture.clear();
} 

void ascii::Scene::AnonymousSettings(int size_, std::string path_to_font_) {
    anonymous_size = size_;
    path_to_font = path_to_font_;
    
}

/*
         _________________________________
        |                |                |
        |                |                |
        |      (1, 2)    |     (2, 2)     |
        |                |                |
        |________________|________________| <-- Chunk borders.
        |                |                |
        |       _        |                |
        |      \o        |      *         |
        |       %>       |      ^         |
        |______/_\_______|________________|
              (1, 1)          (2, 1)       
               x, y                         
*/
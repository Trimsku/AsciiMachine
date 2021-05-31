#include "../include/Scene.hpp"

// Scene.cpp

/*      y
        ^
        |_________________________________
        |                |                |
        |                |                |
        |      (1, 2)    |     (2, 2)     |
        |                |                |
        |________________|________________| <-- Chunk borders.
        |                |                |
        |       _        |                |
        |      \o        |      * <-------|- don't render, but saves in vector Object.
     -->|       %>       |                |
Render  |______/_\_______|________________|--->x
 chunk with  (1, 1)          (2, 1)       
           player.
*/
ascii::Scene::Scene(Configuration cbind) : aobj("anonymous") {  
    Bind(cbind);
    aobj.Bind(cbind);
    if(!ttexture.create(config.widthOfScreen, config.heightOfScreen)){
        std::cout<<"Config error: \n\theight: "<<config.heightOfScreen<<"\n\twidth: "<<config.widthOfScreen<<'\n';
        exit(0);
    }
}

void ascii::Scene::PushObject(GUI_o object, bool createcopy) {
    bool copy = false;
    unsigned int i = 0;

    signed int SpriteLen = object.getElementText(0).getCharacterSize()/2 * getMaxCol( object.getElementText(0) );
    signed int local_x;
    signed int local_y;
    if(object.getX() < 0){
        local_x = object.getX() + getDisplayWidth() * ( getChunkX( object.getX() ) + 1);
    } else {
        local_x = object.getX() - getDisplayWidth() * ( getChunkX( object.getX() ) - 1);
    }
    if (object.getY() < 0 ) {
        local_y = object.getY() + getDisplayHeight() * ( getChunkY( object.getY() ) + 1);
    }
    else{
        local_y = object.getY() - getDisplayHeight() * ( getChunkY( object.getY() ) - 1);
    }

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
        if ( local_x + SpriteLen > getDisplayWidth() ){
            if(local_x + SpriteLen > getDisplayWidth()) {
            int count = 1;
            CoordsOfObjects[i].x_chunk = static_cast<int>(getChunkX( object.getX() ) );
            CoordsOfObjects[i].y_chunk = static_cast<int>(getChunkY( object.getY() ) );
            
            Vector2dlocalInfo info;

            info.x_chunk = static_cast<int>(getChunkX( object.getX() ) ) + 1;
            info.y_chunk = CoordsOfObjects[i].y_chunk;
            CoordsOfObjects.push_back(info);

            Objects[i] = object;
            GUI_o object2 = object;
            while(!(local_x + object.getElementText(0).getCharacterSize()/2*count > getDisplayWidth())) {
                count++;
            }
            object2.local_coords_x_on = true;
            object2.setGlobalXY(-static_cast<signed int>(object.getElementText(0).getCharacterSize()/2*count), object.getY());
            Objects.push_back(object2);
        }
        }
        
        else {
            Objects[i] = object;
            CoordsOfObjects[i].x_chunk = static_cast<int>(getChunkX( object.getX() ) );
            CoordsOfObjects[i].y_chunk = static_cast<int>(getChunkY( object.getY() ) );
        }
    }
    else {

        if(local_x + SpriteLen > getDisplayWidth()) {
            int count = 1;
            Vector2dlocalInfo info;
            info.x_chunk = static_cast<int>(getChunkX( object.getX() ) );
            info.y_chunk = static_cast<int>(getChunkY( object.getY() ) );
            CoordsOfObjects.push_back(info);

            info.x_chunk = static_cast<int>(getChunkX( object.getX() ) ) + 1;
            CoordsOfObjects.push_back(info);

            Objects.push_back(object);
            while(!(local_x + object.getElementText(0).getCharacterSize()/2*count > getDisplayWidth())) {
                count++;
            }
            GUI_o object2 = object;
            object2.local_coords_x_on = true;
            object2.setGlobalXY(-static_cast<signed int>(object.getElementText(0).getCharacterSize()/2*count), object.getY());
            Objects.push_back(object2);
        }
        else {
            Objects.push_back(object);
            Vector2dlocalInfo info;
            info.x_chunk = static_cast<int>(getChunkX( object.getX() ) );
            info.y_chunk = static_cast<int>(getChunkY( object.getY() ) );
            CoordsOfObjects.push_back(info);
        }
    }
}

void ascii::Scene::ClearMap() {
    ttexture.clear({0,0,0,0});
} 

void ascii::Scene::chunk_x_change(signed int to_change_) {
    x_chunk_now += to_change_;
}

void ascii::Scene::chunk_y_change(signed int to_change_) {
    y_chunk_now += to_change_;
}

void ascii::Scene::DrawMap() {
    long unsigned int j = 0;
    std::cout << "Map chunk(x,y):"<<x_chunk_now<<','<<y_chunk_now<<" is start drawing\n";
    for (auto &i : CoordsOfObjects)
    {
        std::cout<<Objects[j].getName()<<' '<<Objects[j].getX()<<' '<<Objects[j].getY()<<' '<<i.x_chunk<<' '<<i.y_chunk<<'\n';
        if(i.x_chunk == x_chunk_now && i.y_chunk == y_chunk_now) {
            Objects[j].loadSprite(Objects[j].getElementName(0), &ttexture);
        }
        ++j;
    }
    ttexture.display();
    std::cout<<"Map chunk(x,y):"<<x_chunk_now<<','<<y_chunk_now<<" is end drawing\n";
}

void ascii::Scene::DisplayMap() {
    if(y_chunk_map != y_chunk_now || x_chunk_map != x_chunk_now) {
        ClearMap();
        DrawMap();
        MapTexture = static_cast<sf::Sprite>(ttexture.getTexture());
        y_chunk_map = y_chunk_now;
        x_chunk_map = x_chunk_now;
    }
    config.window->draw(MapTexture);
}

void ascii::Scene::updateMap() {
    config.window->draw(MapTexture);
}

void ascii::Scene::addAnonymousObject(std::string name, std::string data, signed int global_x, signed int global_y, bool createcopy, bool is_file) {
    aobj.clearSprites();
    aobj.setString(name); // anonymus-object - aobj
    aobj.setGlobalXY( global_x , global_y );
    aobj.isFontLoaded(config.font_name);
    aobj.addSprite(data, is_file); 
    PushObject(aobj, createcopy);
}

void ascii::Scene::loadAObject(std::string name, std::string data, signed int global_x, signed int global_y, bool is_file) {
    aobj.clearSprites(); // anonymus-object - aobj
    aobj.setString(name); 
    aobj.setGlobalXY( global_x , global_y );
    aobj.isFontLoaded(config.font_name);
    aobj.addSprite(data, is_file); 
    aobj.loadSprite(data, config.window);
}
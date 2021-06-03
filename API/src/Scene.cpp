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

    signed int local_x;
    if(object.getX() < 0){
        local_x = object.getX() + getDisplayWidth() * ( getChunkX( object.getX() ) + 1);
    } else {
        local_x = object.getX() - getDisplayWidth() * ( getChunkX( object.getX() ) - 1);
    }

    signed int local_y;
    if (object.getY() < 0 ) {
        local_y = object.getY() + getDisplayHeight() * ( getChunkY( object.getY() ) + 1);
    }
    else{
        local_y = object.getY() - getDisplayHeight() * ( getChunkY( object.getY() ) - 1);
    }
    signed int SpriteLen = object.getElementText(0).getCharacterSize()/2 * getMaxCol( object.getElementText(0) );
    //std::cout<<"\n>>>>>>>>>>>>>>>>>>>DEBUG:("<<SpriteLen<<")<<<<<<<<<<<<<<<<<<<\n";
    if(local_x + SpriteLen > config.widthOfScreen) 
        if(!(true_chunk_size_x_add > SpriteLen)){
            ttexture.create(config.widthOfScreen+SpriteLen, config.heightOfScreen);
            true_chunk_size_x_add = SpriteLen;
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
        CoordsOfObjects[i].x_chunk = static_cast<int>(getChunkX( object.getX() ) );
        CoordsOfObjects[i].y_chunk = static_cast<int>(getChunkY( object.getY() ) );

        object.setGlobalXY(local_x, local_y);
        Objects[i] = object;
    }
    else {
        Vector2dlocalInfo info;
        info.x_chunk = static_cast<int>(getChunkX( object.getX() ) );
        info.y_chunk = static_cast<int>(getChunkY( object.getY() ) );
        CoordsOfObjects.push_back(info);

        object.setGlobalXY(local_x, local_y);
        Objects.push_back(object);
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

void ascii::Scene::DrawMap(signed int chunk_x, signed int chunk_y) {
    long unsigned int j = 0;
    std::cout << "Map chunk(x,y):"<<chunk_x<<','<<chunk_y<<" is start drawing\n";
    for (auto &i : CoordsOfObjects)
    {
        //std::cout<<Objects[j].getName()<<' '<<Objects[j].getX()<<' '<<Objects[j].getY()<<' '<<i.x_chunk<<' '<<i.y_chunk<<'\n';
        if(i.x_chunk == chunk_x && i.y_chunk == chunk_y) {
            Objects[j].loadSprite(Objects[j].getElementName(0), &ttexture);
        }
        ++j;
    }
    ttexture.display();
    std::cout<<"Map chunk(x,y):"<<chunk_x<<','<<chunk_y<<" is end drawing\n";
}

void ascii::Scene::DisplayMap(signed int chunk_x, signed int chunk_y) {
    bool found = false;
    unsigned int i = 0;
    for(auto chunk : LoadedChunks) {
        i++;
        //std::cout<<"DEBUG::SIZE:("<<LoadedChunks.size()<<','<<i<<")\n";
        //std::cout<<chunk_x<<' '<<getChunkX(chunk->getPosition().x)<<' '<<chunk_y<<' '<<getChunkY(chunk->getPosition().y)<<'\n';
        
        if(chunk_x == getChunkX(chunk->getPosition().x)&& chunk_y == getChunkY(chunk->getPosition().y)) {
            found = true;
            break;
        }
    }
    std::cout<<'\n';
    if(!found) {
        ClearMap();
        DrawMap(chunk_x, chunk_y);
        MapTexture = static_cast<sf::Sprite>(ttexture.getTexture());
        MapTexture.setPosition(config.widthOfScreen*(chunk_x-1), config.heightOfScreen*(chunk_y-1));
        //std::cout<<"DEBUG::MapTexture:("<<getChunkX(config.widthOfScreen*(chunk_x-1))<<' '<<chunk_x<<")\n";
        //std::cout<<"DEBUG::MapTexture:("<<getChunkY(config.heightOfScreen*(chunk_y-1))<<' '<<chunk_y<<")\n";
        //LoadedChunks.push_back(&MapTexture);
        config.window->draw(MapTexture);
    }
    else {
       // std::cout<<"DEBUG::FILL:("<<sizeof(LoadedChunks[i])<<")\n";
       // std::cout<<"DEBUG::XSF:("<<LoadedChunks[i-1]->getPosition().x<<")\n";
       // std::cout<<"DEBUG::YSF:("<<LoadedChunks[i-1]->getPosition().y<<")\n";
       // std::cout<<"DEBUG::SIZE:("<<LoadedChunks.size()<<','<<i<<")\n";
        //LoadedChunks[i].setPosition(0,0);
        config.window->draw(*LoadedChunks[i]);
    }
}

void ascii::Scene::updateMap() {
    config.window->draw(MapTexture);
}
void ascii::Scene::addAObject(std::string name, std::string data, signed int global_x, signed int global_y, bool createcopy, bool is_file) {
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
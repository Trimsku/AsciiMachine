#include "../include/Scene.hpp"


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

void ascii::Scene::setWidthAndHeight(float width_, float height_) {
    widthOfScreen = width_;
    heightOfScreen = height_;
    if(!ttexture.create(widthOfScreen, heightOfScreen))
        exit(0);
}


void ascii::Scene::PushObject(GUI_o object, bool createcopy) {
    bool copy = false;
    unsigned int i = 0;

    signed int SpriteLen = object.getElement(0).getCharacterSize()/2 * getMaxCol( object.getElement(0) );
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
            while(!(local_x + object.getElement(0).getCharacterSize()/2*count > getDisplayWidth())) {
                count++;
            }
            object2.local_coords_x_on = true;
            object2.setGlobalXY(-static_cast<signed int>(object.getElement(0).getCharacterSize()/2*count), object.getY());
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
            while(!(local_x + object.getElement(0).getCharacterSize()/2*count > getDisplayWidth())) {
                count++;
            }
            GUI_o object2 = object;
            object2.local_coords_x_on = true;
            object2.setGlobalXY(-static_cast<signed int>(object.getElement(0).getCharacterSize()/2*count), object.getY());
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
    ttexture.clear();
} 

void ascii::Scene::chunk_x_change(signed int to_change_) {
    x_chunk_now += to_change_;
}

void ascii::Scene::chunk_y_change(signed int to_change_) {
    y_chunk_now += to_change_;
}

void ascii::Scene::AnonymousSettings(int size_, std::string path_to_font_) {
    anonymous_size = size_;
    path_to_font = path_to_font_;
}


void ascii::Scene::DrawMap() {
    long unsigned int j = 0;
    std::cout << "Map chunk(x,y):"<<x_chunk_now<<','<<y_chunk_now<<" is start drawing\n";
    for (auto &i : CoordsOfObjects)
    {
        if(i.x_chunk == x_chunk_now && i.y_chunk == y_chunk_now) {
            Objects[j].loadSprite(Objects[j].getName(), &ttexture);
        }
        ++j;
    }
    ttexture.display();
    std::cout<<"Map chunk(x,y):"<<x_chunk_now<<','<<y_chunk_now<<" is end drawing\n";
}

void ascii::Scene::DisplayMap(sf::RenderWindow *window) {
    if(y_chunk_map != y_chunk_now || x_chunk_map != x_chunk_now) {
        ClearMap();
        DrawMap();
        MapTexture = static_cast<sf::Sprite>(ttexture.getTexture());
        y_chunk_map = y_chunk_now;
        x_chunk_map = x_chunk_now;
    }
    window->draw(MapTexture);
}
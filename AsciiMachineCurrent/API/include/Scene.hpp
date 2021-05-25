#pragma once
#include <vector>
#include <tuple>
#include <string>
#include "GUI_o.hpp"
#include "Vector2d.hpp"
#include "utils.hpp"

namespace ascii {
    class Scene {
        private:
            int getChunkX(int global_x);
            int getChunkY(int global_y);

            int widthOfScreen, heightOfScreen;
            signed int x_chunk_now = 1, y_chunk_now = 1;
            std::vector<Vector2dlocalInfo> CoordsOfObjects;
            std::vector<GUI_o> Objects;
            int anonymous_size;
            std::string path_to_font; 
        public:
            sf::RenderTexture ttexture;
            void setWidthAndHeight(int width, int height);
            void PushObject(GUI_o object, bool createcopy = false);
            void AnonymousSettings(int size, std::string path_to_font_);

            void pushAnonymousObject(std::string path_to_file, int global_x, int global_y, bool createcopy = true);
            void DrawMap();
            void ClearMap();
            void DisplayMap(sf::RenderWindow *window);
    };
}

#define ANONYMOUS_OBJECT(path_to_file, global_x, global_y) \
    AnonymousObject.setGlobalXY( global_x , global_y ); \
    AnonymousObject.isFontLoaded(FONT_PATH); \
    AnonymousObject.newSprites(path_to_file, "anonymous"); \
    scene.PushObject(AnonymousObject, true);

#define USE_ANONYMOUS ascii::GUI_o AnonymousObject("anonymous");
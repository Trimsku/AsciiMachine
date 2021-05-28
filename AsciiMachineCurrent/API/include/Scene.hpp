#pragma once
#include <vector>
#include <tuple>
#include <string>
#include "GUI_o.hpp"
#include "Vector2d.hpp"
#include "utils.hpp"

namespace ascii {
    class Scene {
        protected:

            float widthOfScreen, heightOfScreen;
            signed int x_chunk_now = 1, y_chunk_now = 1;
            signed int x_chunk_map, y_chunk_map;
            std::vector<Vector2dlocalInfo> CoordsOfObjects;
            std::vector<GUI_o> Objects;
            int anonymous_size;
            std::string path_to_font;
        public:
            sf::RenderTexture ttexture;
            sf::Sprite MapTexture;
            void setWidthAndHeight(float width, float height);
            void PushObject(GUI_o object, bool createcopy = false);
            void AnonymousSettings(int size, std::string path_to_font_);
            void chunk_x_change(signed int to_change_);
            void chunk_y_change(signed int to_change_);

            // Map manipulations.
            void DrawMap();
            void ClearMap();

            // Display
            void DisplayMap(sf::RenderWindow *window);
    };
}

#define ANONYMOUS_OBJECT(path_to_file, global_x, global_y) \
    AnonymousObject.setGlobalXY( global_x , global_y ); \
    AnonymousObject.isFontLoaded(FONT_PATH); \
    AnonymousObject.newSprites(path_to_file, "anonymous"); \
    scene.PushObject(AnonymousObject, true);

#define USE_ANONYMOUS ascii::GUI_o AnonymousObject("anonymous");
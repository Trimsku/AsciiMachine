#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "GUI_o.hpp"
#include "UtilTypes.hpp"
#include "utils.hpp"
#include "Config.hpp"

namespace ascii {
    class Scene : protected ConfigurationBind{
        protected:
            signed int x_chunk_now = 1, y_chunk_now = 1;
            signed int x_chunk_map, y_chunk_map;
            
            std::vector<Vector2dlocalInfo> CoordsOfObjects;
            std::vector<GUI_o> Objects;
            // Anonymous objects.
            GUI_o anonymous_object;
            // SFML-types.
            sf::RenderTexture ttexture;
            sf::Sprite MapTexture;
        public:

            Scene(Configuration cbind);
            void PushObject(GUI_o object, bool createcopy = false);
            void PushAnonymousObject(std::string path_to_file, signed int global_x, signed int global_y, bool is_file = true);
            void chunk_x_change(signed int to_change_);
            void chunk_y_change(signed int to_change_);

            // Map manipulations.
            void DrawMap();
            void ClearMap();

            // Display
            void DisplayMap(sf::RenderWindow *window);
    };
}

/*#define ANONYMOUS_OBJECT(path_to_file, global_x, global_y) \
    AnonymousObject.setGlobalXY( global_x , global_y ); \
    AnonymousObject.isFontLoaded(FONT_PATH); \
    AnonymousObject.newSprites(path_to_file, "anonymous"); \
    scene.PushObject(AnonymousObject, true);

#define USE_ANONYMOUS ascii::GUI_o AnonymousObject("anonymous");
*/
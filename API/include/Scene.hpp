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
            // SFML-types.
            sf::RenderTexture ttexture;
            sf::Sprite MapTexture;
            GUI_o aobj;
        public:
            // From
            Scene(Configuration cbind);
            void PushObject(GUI_o object, bool createcopy = false);
            void addAnonymousObject(std::string name, std::string path_to_file, signed int global_x, signed int global_y, bool createcopy = true, bool is_file = true);
            void loadAObject(std::string name, std::string path_to_file, signed int global_x, signed int global_y, bool is_file = true);
            void chunk_x_change(signed int to_change_);
            void chunk_y_change(signed int to_change_);

            // Map manipulations.
            void DrawMap();
            void ClearMap();

            // Display
            void DisplayMap();
            void updateMap();
    };
}

#define addText(name, text, global_x, global_y, createcopy) addAnonymousObject(name, text, global_x, global_y, createcopy, false)
#define addFromFile(name, path_to_file, global_x, global_y, createcopy) addAnonymousObject(name, path_to_file, global_x, global_y, createcopy, true)

#define loadText(name, path_to_file, global_x, global_y) loadAObject(name, path_to_file, global_x, global_y, false)
#define loadFromFile(name, path_to_file, global_x, global_y) loadAObject(name, path_to_filem global_x, global_y, true)
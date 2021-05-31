#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace ascii {
    class Configuration {
        private:
        public:
            std::string font_name;
            std::string path_to_main;
            int global_size;
            int widthOfScreen;
            int heightOfScreen;
            sf::RenderWindow *window;
    };

    class ConfigurationBind {
        protected:
            Configuration config;
        public:
            virtual void Bind(Configuration cbind);
    };
}
#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace ascii {
    class Configuration {
        private:
        public:
            std::string font_name;
            std::string path_to_main;
            int global_size;
            int widthOfScreen;
            int heightOfScreen;
    };

    class ConfigurationBind {
        protected:
            Configuration config;
        public:
            void Bind(Configuration cbind);
    };
}
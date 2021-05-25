#pragma once
#include "utils.hpp"
#include <ctype.h>
#include <iostream>
#include <string>
#include <fstream>
namespace ascii {
        class Global
        {
        private:
            std::ofstream global_variables;
            std::string global_name, width, height;
            std::string token;
        public:
            Global();
            void Parse(std::string path_to_file/* = "global.txt"*/);
        };

        #include "Parse.cpp"
} 
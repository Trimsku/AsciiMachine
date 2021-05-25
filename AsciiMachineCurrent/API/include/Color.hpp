#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace ascii {
    
    class Palitra {
        private:
            std::string PalitraName;
            std::vector<std::string> colornames;
            std::vector<int> r;
            std::vector<int> g;
            std::vector<int> b;
            std::vector<int> a;
        public:
            //! Default functions.

            void PushColor(std::string color_name, int r_, int g_, int b_, int a_ = 10);
            Palitra(std::string palitra_name);
            void printColors();

            //! Getters

            std::string getPalitraName();
    };

    // ? Create a RGBA-class
}


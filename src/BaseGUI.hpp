/***************************************************
****************************************************
AsciiMachine - Engine for create ascii games. Enjoy!
AsciiMachine is a free game engine, but you are:
    1. Don't copyright product. 

        You cannot to pose as an a project as your own 
        without the permission of Trimsky.

    2. You cannot to pose as an modified versions as your own.

If these conditions are met, you can use the product.
Copyright 2021-2021
*****************************************************
****************************************************/

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "assertvariables.hpp"
namespace ascii{
    
    class BaseGUI{
        private:
            std::string Name;
            float x0,y0, x1, y1;
        public:
            BaseGUI(std::string Name);
            void setHitbox(float x01, float y01, float x02, float y02);
            float getY0();
            float getX0();
            float getY1();
            float getX1();
            std::string getName();
    };
    #include "BaseGUI.cpp"

}
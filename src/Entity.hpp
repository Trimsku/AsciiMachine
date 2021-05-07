/***************************************************
****************************************************
AsciiMachine - Engine for create ascii games. Enjoy!
AsciiMachine is a free game engine, but you are:
    1. Don't copyright product. 

        You can't pose as an a project as your own 
        without the permission of Trimsky.

    2. You can't pose as an modified versions as your own.

If these conditions are met, you can use the product.
Copyright 2021-2021
*****************************************************
****************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "BaseGUI.hpp"
#include "GlobalVars.hpp"

namespace ascii{
    class Entity : public BaseGUI
    {
    private:
        std::string Name;
        float Attack;
        float hp;
    public:
        Entity(std::string Name0);
        virtual ~Entity();
        void MinusHP(float minHP);
        void PlusHP(float plusHP);

        // Getters

        void setAttack(float attack);
        void setHP(float HP);
        
        // Setters
        
        float getHP();
        std::string getName();
        float getAttack();
    };
    #include "Entity.cpp"
}
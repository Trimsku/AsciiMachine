#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUI_o.hpp"

namespace ascii{
    class Entity : public GUI_o
    {
    private:
        std::string name;
        float Attack;
        float hp; // Entity's HP.
    public:
        //! Defaults:

        Entity(std::string name_);
        virtual ~Entity();
        void MinusHP(float minHP);
        void PlusHP(float plusHP);

        //! Getters

        void setAttack(float attack);
        void setHP(float HP);
        
        //! Setters
        
        float getHP();
        float getAttack();
    };
}
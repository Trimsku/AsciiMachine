#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Object.hpp"
#include "assertvariables.hpp"
namespace ascii{
    class Entity : public Object
    {
    private:
        std::string Name;
    public:
        int x,y;
        Entity(std::string Name0);
        virtual ~Entity();
        int Attack;
        int Move;
        std::string getName();
    };
    #include "Entity.cpp"
}
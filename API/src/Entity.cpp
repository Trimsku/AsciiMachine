#include "../include/Entity.hpp"
#include "../include/utils.hpp"
// Default functions

ascii::Entity::Entity(std::string name_)
    :GUI_o(name_)
{
    name = name_;
    std::cout << getName() << "(type: Entity) is created\n";
}

ascii::Entity::~Entity()
{
    std::cout << getName() << "(type: Entity) is destroyed\n";
}
void ascii::Entity::MinusHP(float minHP){
    hp -= minHP;
}
void ascii::Entity::PlusHP(float plusHP){
    hp += plusHP;
}

// Setters

void ascii::Entity::setAttack(float attack){
    Attack = attack;
}
void ascii::Entity::setHP(float HP){
    hp = HP;
}

//* Getters; GUI

float ascii::Entity::getHP(){
    return hp;
}


float ascii::Entity::getAttack(){
    return Attack;
}


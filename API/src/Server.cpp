#include "../include/Server.hpp"

ascii::Server::Server(){
    std::cout<<"\nServer class is created\n";
}
ascii::Server::~Server(){
    std::cout<<"\nServer class is destroyed\n";
}
void ascii::Server::sendStatus(GUI_o *obj){
    GUI_objects.push_back(obj);
}
void ascii::Server::update(GUI_o *obj){
    for(int i = 0; i < GUI_objects.size(); i++){
        if(obj->getName() != GUI_objects[i]->getName()){

            if( obj->getHitboxX1() <= GUI_objects[i]->getHitboxX1() && GUI_objects[i]->getHitboxX1() <= obj->getHitboxX2() ){
                //std::cout<<obj->getHitboxY1()<<' '<<GUI_objects[i]->getHitboxY1()<<' '<<obj->getHitboxY2()<<' ';

                if( obj->getHitboxY1() <= GUI_objects[i]->getHitboxY1() && GUI_objects[i]->getHitboxY1() <= obj->getHitboxY2() ) {
                    GUI_names.push_back(GUI_objects[i]->getName());
                    continue;
                }
            }
            else if( GUI_objects[i]->getHitboxX1() <= obj->getHitboxX1() && obj->getHitboxX1() <= GUI_objects[i]->getHitboxX2() ) {
                if( obj->getHitboxY1() <= GUI_objects[i]->getHitboxY1() && GUI_objects[i]->getHitboxY1() <= obj->getHitboxY2() ) {
                    GUI_names.push_back(GUI_objects[i]->getName());
                    continue;
                }
                continue;
            }
            continue;
        }
    }
}

int ascii::Server::isNear(GUI_o *main_obj, std::string TargetName) {
    int count = 0;
    for(int i = 0; i < GUI_objects.size(); i++) {
        if( GUI_objects[i]->getName() == TargetName ) {
            if( main_obj->getHitboxX1() <= GUI_objects[i]->getHitboxX1() && GUI_objects[i]->getHitboxX1() <= main_obj->getHitboxX2() ){
                if( main_obj->getHitboxY1() <= GUI_objects[i]->getHitboxY1() && GUI_objects[i]->getHitboxY1() <= main_obj->getHitboxY2() ) {
                    count++;
                    continue;
                }
            }
            else if( GUI_objects[i]->getHitboxX1() <= main_obj->getHitboxX1() && main_obj->getHitboxX1() <= GUI_objects[i]->getHitboxX2() ) {
                if( main_obj->getHitboxY1() <= GUI_objects[i]->getHitboxY1() && GUI_objects[i]->getHitboxY1() <= main_obj->getHitboxY2() ) {
                    count++;
                    continue;
                }
                continue;
            }
            continue;
        }
    }
    return count;
}

void ascii::Server::refresh(){
    #ifdef ENABLE_GUI_BASE
        BGUI_names.clear();
        BGUI_names.shrink_to_fit();
    #endif
}

bool ascii::Server::lookfor(std::string name){
    for(int i = 0; i < GUI_names.size(); i++){
        if(GUI_names[i] == name) {
            GUI_names.erase(GUI_names.begin() + i);
            return true;
        }
    }
    return false;
}
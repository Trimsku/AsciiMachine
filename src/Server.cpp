Server::Server(){
    logs.writeLog("Server class is created");
}
Server::~Server(){
    logs.writeLog("Server class is destroyed");
}
void Server::sendStatus(BaseGUI *obj){
    BGUI_Object.push_back(obj);
}
std::vector<std::string> Server::update(BaseGUI *obj){
    for(int i = 0; i < BGUI_Object.size(); i++){
        if(obj->getName() != BGUI_Object[i]->getName()){

            if( obj->getX0() <= BGUI_Object[i]->getX0() && BGUI_Object[i]->getX0() <= (int)obj->getX1() ){
                //std::cout<<obj->getY0()<<' '<<BGUI_Object[i]->getY0()<<' '<<obj->getY1()<<' ';

                if( obj->getY0() <= BGUI_Object[i]->getY0() && BGUI_Object[i]->getY0() <= obj->getY1() ) {
                    BGUI_names.push_back(BGUI_Object[i]->getName());
                    continue;
                }
            }
            else if( BGUI_Object[i]->getX0() <= obj->getX0() && obj->getX0() <= BGUI_Object[i]->getX1() ) {
                if( obj->getY0() <= BGUI_Object[i]->getY0() && BGUI_Object[i]->getY0() <= obj->getY1() ) {
                    BGUI_names.push_back(BGUI_Object[i]->getName());
                    continue;
                }
                continue;
            }
            continue;
        }
    }
    return BGUI_names;
}

void Server::refreshBGUI(){
    BGUI_names.clear();
    BGUI_names.shrink_to_fit();
}
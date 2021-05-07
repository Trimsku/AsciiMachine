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
#include <vector>
#include <tuple>
#include "utils.hpp"
#include "GlobalVars.hpp" //- TODO making system.
#include "BaseGUI.hpp"
namespace ascii{

    class Server{
        private:
            #ifdef ENABLE_GUI_BASE
                std::vector<BaseGUI*> BGUI_Object;
                std::vector<std::string> BGUI_names;
            #endif
        public:
            #ifdef ENABLE_GUI_BASE
                void update(BaseGUI *obj);
                void sendStatus(BaseGUI *obj);
                bool lookfor(std::string name);
            #endif

            Server();
            ~Server();
            void refresh();
    };
    #include "Server.cpp"
    
}
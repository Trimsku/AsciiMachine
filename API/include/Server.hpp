#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "GUI_o.hpp"
namespace ascii
{
    
    class Server {
        private:
            std::vector<GUI_o*> GUI_objects;
            std::vector<std::string> GUI_names;
        public:
            Server();
            ~Server();
            void sendStatus(GUI_o *obj);
            void update(GUI_o *obj);
            void refresh();
            bool lookfor(std::string name);
            int isNear(GUI_o *main_obj, std::string TargetName);
    };
} // namespace ascii 
#pragma once
#include <vector>
#include <tuple>
#include "utils.hpp"
#include "assertvariables.hpp" //- TODO making system.
#include "Object.hpp"
namespace ascii{

    class Server{
        public:
            Server();
            ~Server();
            #ifdef ENABLE_OBJECT
                std::vector<Object*> OObject;
            #endif
            void SendStatus(Object *obj);
    };
    #include "Server.cpp"
    
}
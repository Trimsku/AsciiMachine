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
#include <fstream>
#include <ctime>
#include <iostream>
#include <string>
namespace ascii
{
    class Log {
        private:
            std::ofstream log;   
        public:
            Log(std::string log_src);
            void writeLog(std::string Str);
    };
    #include "Log.cpp"
} // namespace ascii

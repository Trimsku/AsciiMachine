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
            void WriteLog(std::string Str);
    };
    #include "Log.cpp"
} // namespace ascii

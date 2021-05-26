#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace ascii {

    class ASignal {
        private:
            std::vector<std::string> signal_out;
        public:
            virtual ~ASignal() { }
            virtual bool is_connect(std::string message) = 0;
            virtual void send(std::string message) = 0;
            virtual void printSignals() = 0;
    };

}
#pragma once
#include <string>
#define SIG_BREAK 1
#define SIG_ERR 0

namespace ascii {

    template<typename T>
    void signal(T *object, std::string message) {
        object->send(message);
    }

    template<typename T>
    void signal(T *object, int message) {
        if(message == SIG_ERR){ // SIG_ERR = -1
            object->send("SIG_ERR");
        }
        else if(message == SIG_BREAK){ // SIG_BREAK = 0
            object->send("SIG_BREAK");
        }
        else {
            object->send("UNKNOWN_INT_OPERATION");
        }
    }
}
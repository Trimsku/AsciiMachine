#include "Container.hpp"

std::string astd::asString(std::vector<std::string> &container) {
    std::string str;
    for(int i = 0; i < container.size(); i++) str += container[i] + ' ';
    return str;
}

std::vector<std::string> astd::split(std::string str, char delimiter) {
    std::vector<std::string> splittedStr;
    size_t last = 0; 
    size_t next = 0; 
    while ((next = str.find(delimiter, last)) != std::string::npos) {   
        splittedStr.push_back(str.substr(last, next-last));   
        last = next + 1; 
    } 
    splittedStr.push_back(str.substr(last));

    return splittedStr;
}
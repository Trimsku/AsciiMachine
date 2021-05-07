#include "src/Parse.hpp"
#include <algorithm>
int main(){
    ascii::Global global;
    std::string path_to_file;
    std::cin>>path_to_file;
    std::string SavePath = path_to_file;
    if(path_to_file == "NONE") global.Parse();
    else global.Parse(path_to_file);
}
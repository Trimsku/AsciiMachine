#include "../include/utils.hpp"

namespace ascii {

    std::string getFileResources(std::string path_to_file) {
        std::ifstream PathFile(path_to_file);
        std::string strh;
        std::string str;
        if (!PathFile.is_open()) {
            return path_to_file; // Is abstraction level.
            /*#ifdef __linux__
                std::cerr<<"File \033[1;31m"<<path_to_file<<"\033[0m not found. \n";
                exit(0);
            #else // TODO: create text lighting
                std::cerr<<"File "<<path_to_file<<"not found. \n";
            #endif*/
        } 
        while(!PathFile.eof()){
            getline(PathFile, strh);
            str = str + strh.c_str();
            if (!PathFile.eof()){
                str += '\n';
            }
        }   
        PathFile.close();
        return str;
    }   
    int getFileAnimationsCount(std::string path_to_file){
        std::string txtFormat = getFileResources(path_to_file);
        int counter = 1;
        for(long unsigned int i = 0; i < txtFormat.length(); i++){
            if(txtFormat[i] == '[' && txtFormat[i+1] == '#' && txtFormat[i+2] == static_cast<char>((counter+1)+'0') ){
                counter++;
            }
        }
        return counter;
    }

} // namespace ascii

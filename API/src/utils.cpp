#include "../include/utils.hpp"

namespace ascii {
    #ifdef __linux__
        Display* disp = XOpenDisplay(NULL);
        Screen*  scrn = DefaultScreenOfDisplay(disp);
    #endif

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

    signed int getChunkX( signed int global_x ) {
        signed int chunk = 1;
        signed int x = global_x;
        while ( x < 0 ) {
            x += getDisplayWidth();
            chunk--;
        }
        while( x >= getDisplayWidth() ){
            x -= getDisplayWidth();
            chunk++;
        }
        return chunk;
    }

    signed int getChunkY( signed int global_y ) {
        float chunk = 1;
        float y = global_y;
        while( !(y <= getDisplayHeight() && y >= 0) ){
            y -= getDisplayHeight();
            chunk++;
        }
        return chunk;
    }

    int getDisplayWidth(){
        #ifdef _WIN32
            return (int) GetSystemMetrics(SM_CXSCREEN);
        #else
            return scrn->width;
        #endif
    }
    int getDisplayHeight(){
        #ifdef _WIN32
            return (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            return scrn->height;
        #endif
    }

    int getMaxCol(sf::Text sprite, int sprite_num_){
        int colrowssize = 0;
        int loop = 0;
        bool is1sprite = isOneSprite(sprite.getString());

        if(is1sprite == true) loop = 1;
        else loop = 0;

        std::vector<int> maxElement;
        std::string Sprite = sprite.getString();

        for(long unsigned int i = 0; i < Sprite.size(); i++){
            if( !is1sprite ) {
                if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == sprite_num_) {
                    loop++;
                    i+=3;
                }
                if(Sprite[i] == '#' && (Sprite[i+1] - '0') == sprite_num_ && Sprite[i+2] == ']') break;
            }
            if(loop == 1){

                if(Sprite[i] == '[' && Sprite[i+1] == '@'){
                    while(Sprite[i] != ']'){
                        i++;
                    }
                }
                if(Sprite[i] == '\n' ){
                    maxElement.push_back(colrowssize);
                    colrowssize = 0;
                }
                colrowssize++;
            }
        }
        maxElement.push_back(colrowssize);
        int mcol = maxElement[0];
        for(int i = 0; i < maxElement.size(); i++){
            if(maxElement[i] > mcol){
                mcol = maxElement[i];
            } 
        }
        return mcol;
    }

    int getRows(sf::Text sprite, int sprite_num_){
        int row = 1;
        bool is1sprite = isOneSprite(sprite.getString());
        int loop;

        if(is1sprite == true) loop = 1;
        else loop = 0;

        std::string Sprite = sprite.getString();

        for(long unsigned int i = 0; i < Sprite.length(); i++){
            if( !is1sprite ) {
                if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == sprite_num_) {
                    loop++;
                    i+=3;
                }
                if(Sprite[i] == '#' && (Sprite[i+1] - '0') == sprite_num_ && Sprite[i+2] == ']') break;
            }
            if(loop == 1){
                if(Sprite[i] == '\n' ){
                    row++;
                }
            }
        }
        return row;
    }

    bool isOneSprite(std::string fsprite){
        for(long unsigned int i = 0; i < fsprite.length(); i++) {
            if(fsprite[i] == '[' && fsprite[i+1] == '#' && fsprite[i+2] == '1') {
                return false;
            }
        }
        return true;
    }
} // namespace ascii

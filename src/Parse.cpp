Global::Global(){
}
void Global::Parse(std::string path_to_file = "global.txt"){
    global_variables.open("src/GlobalVars.hpp");
    if (global_variables.is_open()) 
        #ifdef _WIN32 
            #include <windows.h>
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
            std::cout<<"\nINFO :: GlobalVars.hpp created\n\n";
        #endif
        #ifdef __linux__
        std::cout<<"\n\033[0;32mINFO :: GlobalVars.hpp created\033[0m\n\n";
        #endif
    else {
        #ifdef _WIN32 
            #include <windows.h>
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, (WORD) ((4 << 4) | 2));
            std::cout<<"\nINFO :: GlobalVars.hpp isn't created\n\n";
        #endif
        #ifdef __linux__
        std::cout<<"\n\033[1;31mINFO :: GlobalVars.hpp isn't created\033[0m\n\n";
        #endif
        exit(0);
    }
    std::string resources = ascii::getFileResources(path_to_file);
    std::string names;
    global_variables<<"#pragma once\n";
    for(int i = 0; i < resources.size(); i++){
        if(!isalpha(resources[i])) {
            names="";
            continue;
        }
        else{
            names+=tolower(resources[i]);
        }
        if(names == "name"){
            i+=3;
            while(!isalnum(resources[i])) i++;
            while(resources[i] != '('){
                global_name += tolower(resources[i]);
                i++;
            }
            ++i;
            global_variables<<"#include <SFML/Graphics.hpp>\n";
            global_variables<<"sf::RenderWindow window(sf::VideoMode(";
            while(!isdigit(resources[i])) i++;
            while(isdigit(resources[i])){
                width += resources[i];
                i++;
            }
            ++i;
            global_variables<<width<<",";
            while(!isdigit(resources[i])) i++;
            while(isdigit(resources[i])){
                height += resources[i];
                i++;
            }
            global_variables<<height<<"),";
            i+=2;
            global_variables<<" \""<<global_name<<"\"";
            while(resources[i] == ' ') i++;
            while(isalpha(resources[i])){
                token+= tolower(resources[i]);
                i++;
            }
            if(token == "fullscreen"){
                global_variables<<", sf::Style::Fullscreen";
                token="";
            }
            global_variables<<");\n";
            names="";
        }
        else if(names == "enable"){
            i++;
            while(!isalpha(resources[i])) i++;
            while(resources[i] != ';'){
                token += tolower(resources[i]);
                i++;
            }
            if(token == "all"){
                global_variables<<"#define ENABLE_GUI_BASE\n";
                global_variables<<"#define OBJECT_COUNT_ERROR \"SIZE IS MORE THAN SIZE OF SPRITES.\"\n";
                global_variables<<"#include \"Log.hpp\"\n";
                global_variables<<"ascii::Log logs(\"log.txt\");\n";
            }
        }
    }
}

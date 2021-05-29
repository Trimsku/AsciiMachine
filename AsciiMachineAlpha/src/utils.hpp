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
#include <string>
#include <math.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#if WIN32
    #include <window.h>
#else
    #include <X11/Xlib.h>
#endif


namespace ascii{
    #ifdef __linux__
        Display* disp = XOpenDisplay(NULL);
        Screen*  scrn = DefaultScreenOfDisplay(disp);
    #endif
    int convertStringToInt(std::string rgb){
        int torgb = 0;
        for(int i = 0; i < rgb.length(); i++){
            torgb += rgb[i] * pow(10, rgb.length() - i - 1); 
        }
        return torgb;
    }
    void setDisplayYX(int &width, int &height) {
        #ifdef _WIN32
            width  = (int) GetSystemMetrics(SM_CXSCREEN);
            height = (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            width  = scrn->width;
            height = scrn->height;
        #endif
    }
    int getDisplayX(){
        #ifdef _WIN32
            return (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            return scrn->width;
        #endif
    }
    int getDisplayY(){
        #ifdef _WIN32
            return (int) GetSystemMetrics(SM_CXSCREEN);
        #else
            return scrn->height;
        #endif
    }
    int getRows(sf::Text TextR, int SpriteNum = 1){
        int row = 1;
        int loop = 0;
        std::string TextRR = (std::string)TextR.getString();
        for(int i = 0; i < TextRR.length(); i++){
            
            if(TextRR[i] == '[' && TextRR[i+1] == '#' && TextRR[i+2] - '0' == SpriteNum ){
                i+=3;
                loop++;
            }

            if(TextRR[i] == '#' && TextRR[i+1] - '0' == SpriteNum && TextRR[i+2] == ']') break;

            if(loop == 1){
                if(TextRR[i] == '\n')
                    row++;
            }
        }
        return row;
    }
    int getMaxCol(sf::Text TextMaxC, int SpriteNum = 1){
        int colrowssize = 0;
        int loop = 0;
        std::vector<int> maxElement;
        std::string textm = TextMaxC.getString();
        for(int i = 0; i < textm.size(); i++){
            if(textm[i] == '[' && textm[i+1] == '#' && textm[i+2] - '0' == SpriteNum ){
                i+=3;
                loop++;
            }
            if(textm[i] == '#' && textm[i+1] - '0' == SpriteNum && textm[i+2] == ']') break;
            if(loop == 1){
            
                if(textm[i] == '[' && textm[i+1] == '%'){
                    while(textm[i] != ']'){
                        i++;
                    }
                }
                if(textm[i] == '[' && textm[i+1] == '@'){
                    while(textm[i] != ']'){
                        i++;
                    }
                }
                if(textm[i] == '\n'){
                    maxElement.push_back(colrowssize);
                    colrowssize = 0;
                }
                colrowssize++;
            }
        }
        int mcol = maxElement[0];
        for(int i = 0; i < maxElement.size(); i++){
            if(maxElement[i] > mcol){
                mcol = maxElement[i];
            } 
        }
        return mcol;
    }
    std::string getFileResources(std::string path_to_file){
        std::ifstream PathFile(path_to_file);
        std::string strh;
        std::string str;
        if (!PathFile.is_open()) {
            std::cerr<<"Файл \033[1;31m"<<path_to_file<<"\033[0m не существует\n";
            exit(0);
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
    int getCenterX(){
        return ascii::getDisplayX()/2;
    }
    int getCenterY(){
        return ascii::getDisplayY()/2;
    }
    int getCenterX(sf::Text text, int SpriteNum = 1){
        return getCenterX()-getMaxCol(text, SpriteNum)/4*text.getCharacterSize();
    }
    int getCenterY(sf::Text text, int SpriteNum = 1){
        return getCenterY()-getRows(text, SpriteNum)/2*text.getCharacterSize();
    }
    int getDownY(sf::Text text, int SpriteNum = 1){
        return getDisplayY()-getRows(text, SpriteNum)*text.getCharacterSize();
    }
    int getRightX(sf::Text text, int SpriteNum = 1){
        return getCenterX()/2-getMaxCol(text,SpriteNum)/2*text.getCharacterSize()/2;
    }
    int getLeftX(sf::Text text, int SpriteNum = 1){
        return getCenterX() + getRightX(text, SpriteNum);
    }
}
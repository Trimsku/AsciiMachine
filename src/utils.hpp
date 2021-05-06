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
#if WIN32
    #include <window.h>
#else
    #include <X11/Xlib.h>
#endif

namespace ascii{
    #if WIN32
            width  = (int) GetSystemMetrics(SM_CXSCREEN);
            height = (int) GetSystemMetrics(SM_CYSCREEN);
    #else
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
        #if WIN32
            width  = (int) GetSystemMetrics(SM_CXSCREEN);
            height = (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            width  = scrn->width;
            height = scrn->height;
        #endif
    }
    int getDisplayX(){
        #if WIN32
            return (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            return scrn->width;
        #endif
    }
    int getDisplayY(){
        #if WIN32
            return (int) GetSystemMetrics(SM_CXSCREEN);
        #else
            return scrn->height;
        #endif
    }
    int getRows(sf::Text TextR, int SpriteNum = 1){
        int row = 0;
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
        return row+1;
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
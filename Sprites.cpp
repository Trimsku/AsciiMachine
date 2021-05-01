#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
std::string GetSpriteResources(std::string PathToSprite){
    std::ifstream PathFile(PathToSprite);
    std::string strh;
    std::string str;
     if (!PathFile.is_open()) {
        std::cerr<<"Файл \033[1;31m"<<PathToSprite<<"\033[0m не существует\n";
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

void LoadSprite(sf::Text sprite, sf::RenderWindow& window, float x, float y, int SpriteNum = 1){
    std::string Sprite = sprite.getString();
    int saveX = x;
    int loop = 0;
    std::string r,g,b, size;
    for(int i = 0; i < Sprite.length(); i++){
        sprite.setPosition(x,y);
        if(Sprite[i] == '[' && Sprite[i+1] == '#' && (Sprite[i+2] - '0') == SpriteNum) {
            loop++;
            i+=3;
        }
        if(Sprite[i] == '#' && (Sprite[i+1] - '0') == SpriteNum && Sprite[i+2] == ']') break;

        if(loop == 1){
        if(Sprite[i] == '[' && Sprite[i+1] == '%'){
            i+=2;
            for(; Sprite[i] != ']'; i++) size += Sprite[i];
            i++;
            sprite.setCharacterSize(ConvertToInt(size));
            size = "";
        }
        if(Sprite[i] == '[' && Sprite[i+1] == '@'){
            i+=2;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++) r+=Sprite[i];
            i++;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  g+=Sprite[i];
            i++;
            while(Sprite[i] == ' ') i++;
            for(; isdigit(Sprite[i]); i++)  b+=Sprite[i];
            i++;

            /*rgb(Number, ConvertRGBtoInt(r), ConvertRGBtoInt(g), ConvertRGBtoInt(b));*/
            sprite.setFillColor(sf::Color( ConvertToInt(r), ConvertToInt(g), ConvertToInt(b)));
            r ="", g = "", b = "";
        }
        if(Sprite[i] == '\n') {
                Sprite[i] = ' ';
                //i++;
                y += sprite.getCharacterSize();
                x=saveX;
                sprite.setPosition(x, y); 
                continue;
            }
        
        x+=sprite.getCharacterSize()/2;
        sprite.setPosition(x,y);
        
        sprite.setString(Sprite[i]);	
        window.draw(sprite);
        }
    }
}
#pragma once
#include <string>
#include <math.h>
int ConvertToRGB(std::string rgb){
    int torgb = 0;
    for(int i = 0; i < rgb.length(); i++){
        intrgb = rgb[i] * pow(10, rgb.length() - i - 1); 
    }
}
#pragma once
#include <string>
#include <math.h>

#if WIN32
    #include <window.h>
#else
    #include <X11/Xlib.h>
#endif

namespace ascii{
    int ConvertToInt(std::string rgb){
        int torgb = 0;
        for(int i = 0; i < rgb.length(); i++){
            torgb += rgb[i] * pow(10, rgb.length() - i - 1); 
        }
        return torgb;
    }


    void getDisplayYX(int &width, int &height) {
        #if WIN32
            width  = (int) GetSystemMetrics(SM_CXSCREEN);
            height = (int) GetSystemMetrics(SM_CYSCREEN);
        #else
            Display* disp = XOpenDisplay(NULL);
            Screen*  scrn = DefaultScreenOfDisplay(disp);
            width  = scrn->width;
            height = scrn->height;
        #endif
    }
}
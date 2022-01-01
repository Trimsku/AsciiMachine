#include <stdio.h>
#include "asciiengine/astd/String.hpp"
#include "asciiengine/common/util/StringUtil.hpp"

astd::string ascii::util::getFileResources(const char *path_to_file) {
    FILE *fstr = fopen(path_to_file, "r");
    if(fstr == NULL) {
        astd::print("File \"%s\" is not found. Check your filename or path.", path_to_file);
        exit(1);
    }
    astd::string str;
    int c;
    while ((c = fgetc(fstr)) != EOF) {
        str+=char(c);
    }
    fclose(fstr);
    return str;
}

int main() {
    astd::string texture = ascii::util::getFileResources("resources/textures/PlayerLeft.txt");
    int current_animation = 1;
    bool isWritingToStringNow = false;
    astd::string stringToAdd;

    for(int i = 0; i < texture.len(); i++){
        if(!isWritingToStringNow && texture[i] == '[' && texture[i+1] == '#' && (texture[i+2] - '0') == current_animation) {
            isWritingToStringNow = true;
            i += 3;
        }

        if(isWritingToStringNow && texture[i] == '#' && (texture[i+1] - '0') == current_animation && texture[i+2] == ']') {
            isWritingToStringNow = false;
            printf("%s \n\n\n", stringToAdd.c_str());
            current_animation++;
            i+=3;
            stringToAdd = "";
        } else if(isWritingToStringNow) stringToAdd += texture[i];
    }
}
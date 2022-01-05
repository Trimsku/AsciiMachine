//
// Created by trimsky on 28.11.2021.
//

#include "../../asciiengine/client/AnimatedTexture.hpp"

ascii::client::AnimatedTexture::AnimatedTexture(astd::string texture) noexcept {
    int current_animation = 1;
    bool isWritingToStringNow = false;
    astd::string stringToAdd;

    for(int i = 0; i < texture.size(); i++){
        if(!isWritingToStringNow && texture[i] == '[' && texture[i+1] == '#' && (texture[i+2] - '0') == current_animation) {
            isWritingToStringNow = true;
            i += 3;
        }

        if(isWritingToStringNow && texture[i] == '#' && (texture[i+1] - '0') == current_animation && texture[i+2] == ']') {
            isWritingToStringNow = false;
            textures.push(stringToAdd);
            current_animation++;
            i+=3;
            stringToAdd = "";
        } else if(isWritingToStringNow) stringToAdd += texture[i];
    }
}
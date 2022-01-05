#ifndef ANIMATED_TEXTURE_HPP
#define ANIMATED_TEXTURE_HPP

#include "../astd/String.hpp"
#include "../astd/Container.hpp"
#include "../astd/Clock.hpp"

namespace ascii { namespace client {
class AnimatedTexture {
    private:
        astd::container<astd::string> textures;
    public:
        AnimatedTexture(astd::string texture) noexcept;
        AnimatedTexture() = default;
        inline int getAnimationsNumber() noexcept;
        inline astd::string getCurrentTexture(int animation_tick) noexcept;
};

int AnimatedTexture::getAnimationsNumber() noexcept {
    return textures.size();
}
astd::string AnimatedTexture::getCurrentTexture(int animation_tick) noexcept {
    return textures[animation_tick];
}
}}
#endif // !ANIMATED_TEXTURE_HPP
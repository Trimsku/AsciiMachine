#ifndef ANIMATED_TEXTURE_HPP
#define ANIMATED_TEXTURE_HPP

#include "../astd/String.hpp"
#include "../astd/Container.hpp"
#include "../astd/Clock.hpp"

namespace ascii::client {
class AnimatedTexture {
    private:
        astd::container<astd::string> textures;
    public:
        AnimatedTexture(astd::string texture);
        AnimatedTexture() = default;
        int getAnimationsNumber();
        astd::string getCurrentTexture(int animation_tick);
};
}
#endif // !ANIMATED_TEXTURE_HPP
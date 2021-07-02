#ifndef TEXT_INSTANCE_H
#define TEXT_INSTANCE_H

#include "util/util_types.hpp"

namespace ascii
{
    // Text Instance
    class TInstance {
        private:
            // Helpful information for drawing
            util::SpriteInfo SpriteT;
        public:
            void newSprite(const char* filename);

    };

} // namespace ascii
#endif // TEXT_INSTANCE_H
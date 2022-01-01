#ifndef INTERFACE_TICKING_RENDERER
#define INTERFACE_TICKING_RENDERER

#include "../core/Engine.hpp"

#define MAKE_ITICKING_RENDERER void tick(); \
    void render(ascii::Engine *engine);

namespace ascii::client {

class ITickingRenderer {
};

}

#endif
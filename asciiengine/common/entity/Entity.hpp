#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../../core/Engine.hpp"

#define MAKE_ENTITY() \
    void render() noexcept; \
    void tick() noexcept; \
    int getX() noexcept; \
    int getY() noexcept; \
    int getW() noexcept; \
    int getH() noexcept; \
    void setX(int x) noexcept; \
    void setY(int y) noexcept; \
    const char* getSceneName() noexcept;

namespace ascii
{
    // Abstract class! has got empty functions!
    class Entity {
        protected:
            Engine *engine;
        public:
            Entity(Engine *m_engine);
    };
} // namespace ascii

#endif
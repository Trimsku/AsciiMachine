#include <SFML/Graphics.hpp>
#include "UtilTypes.hpp"
#include "Config.hpp"

namespace ascii
{
    class Camera : protected ConfigurationBind{
        private:
            sf::View camera;
        public:
            Camera(Configuration cbind);
            void move(float y, float x);
            void move(Vector2d mv_xy);
            sf::View getCamera();
            //void move
    };
} // namespace ascii
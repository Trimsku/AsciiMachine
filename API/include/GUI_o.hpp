#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>
#include "AsciiSignal.hpp"
#include "UtilTypes.hpp"
#include "Config.hpp"

namespace ascii
{
    class GUI_o : protected ASignal, public ConfigurationBind{
        private:
            std::string name; // Name of GUI_o object.
            std::vector<std::pair<sf::Text, std::string>> sprites; // Sprites: texture and texture_name; 
            sf::Font font; // Font
            Vector2d g_coords; // TODO: Create z coordinate.
            bool is_anonymous_o = false;
        public:
            bool local_coords_x_on = false;
            bool local_coords_y_on = false;
            //! ****************
            //! *   Default    *
            //! ****************
            virtual ~GUI_o();
            GUI_o(std::string name_);
            std::string getName();
        
            signed int getX();
            signed int getY();
            void MoveX(float x_);
            void MoveY(float y_);
            void setGlobalXY(float x_, float y_);

            //! ****************************
            //! *  Animation and sprites.  *
            //! ****************************
            void newSprites(std::string filename, bool is_file = true);
            void isFontLoaded(std::string fontname);
            void loadSprite(std::string sprite_, sf::RenderTarget* window, int sprite_num_ = 1);
            void clearSprites();
            sf::Text getElement(int element_c);
            void setAnonymous();
            //! *********************
            //! *      Signal       *
            //! *********************

            bool is_connect(std::string message); // Sended or not?
            virtual void send(std::string message); // Push_back to object's signal output. 
            virtual void printSignals(); // Debug function: print all Signals in object's signal out
    }; // GUI_object
} // namespace ascii


#define GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(nameofanimated, path_to_file) \
    int nameofanimated##counter##max = ascii::getFileAnimationsCount(ascii::getCurrentDir(__FILE__)+"textures/"+path_to_file+".rtxt"); \
    int nameofanimated##counter = 0; \
    sf::Clock nameofanimated; 

#define GUI_CLOCKS_TIMER(nameofanimated, time) \
    if( nameofanimated.getElapsedTime().asMilliseconds() >= time ){ \
        nameofanimated##counter++; \
        if (nameofanimated##counter > nameofanimated##counter##max){\
            nameofanimated##counter = 1;\
        }\
        nameofanimated.restart(); \
    } 

#define GUI_O_ANIMATED(object, nameofanimated) \
    object.loadSprite(#nameofanimated, &window, nameofanimated##counter);


#define GUI_O_ANIMATED_MV(object, nameofanimated, mvx, mvy) \
    if (!(mvy == 0)) object.MoveY(mvy); \
    object.MoveX(mvx); \
    object.loadSprite(#nameofanimated, &window, nameofanimated##counter);

#define GUI_O_LOAD(object, nameofanimated) \
    object.loadSprite(#nameofanimated, &window);

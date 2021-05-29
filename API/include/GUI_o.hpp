#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AsciiSignal.hpp"
#include "Vector2d.hpp"

namespace ascii
{
    class GUI_o : ASignal{
        private:
            std::string name; // Name of GUI_o object.
            std::vector<std::string> signal_out; //signal's "mail".
            std::vector<sf::Text> sprites; // Vector with sprites ( from txt to std::string );
            std::vector<std::string> spritesNames; // Vector with sprite name.
            sf::Font font;
            Vector2d g_coords; // TODO: Create z coordinate.
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

            #ifdef GLOBAL_SIZE
                void newSprites(std::string path_to_file, std::string name, unsigned int size = GLOBAL_SIZE);
            #else //
                void newSprites(std::string path_to_file, std::string name, unsigned int size);
            #endif
            bool isFontLoaded(std::string path_to_file);
            void loadSprite(std::string sprite_, sf::RenderTarget* window, int sprite_num_ = 1);
            void clearSprites();
            sf::Text getElement(int element_c);
            //! *********************
            //! *      Signal       *
            //! *********************

            bool is_connect(std::string message); // Sended or not?
            virtual void send(std::string message); // Push_back to object's signal output. 
            virtual void printSignals(); // Debug function: print all Signals in object's signal out
    }; // GUI_object
} // namespace ascii


#define GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(nameofanimated, path_to_file) \
    int nameofanimated##counter##max = ascii::getFileAnimationsCount(path_to_file); \
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

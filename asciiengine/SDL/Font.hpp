#ifndef FONT_H
#define FONT_H
#include <stdlib.h>
#include "SDL_FontCache.h"
#include "SDL_Wrapper.hpp"
#include "../util/util_types.hpp"
#include "../util/str.hpp"

namespace ascii
{
    class Font
    {
    private:
        Font();
        SDL_Engine *engine;
        FC_Font *font;
    public:
        ~Font();
        int size;
        const char* path_to_font;
        //! Wrapper
        Font(SDL_Engine *engine, const char* path_to_font, int size);
        void LoadFont(int style);
        void DrawFile(signed int x, signed int y, const char* filename, int sprite);
        void DrawFile(signed int x, signed int y, const char* filename);
        void DrawText(signed int x, signed int y, astd::string Sprite, int sprite);
        void DrawText(signed int x, signed int y, const char* Sprite);
        void DrawText(signed int x, signed int y, ascii::util::SpriteInfo spritei);
        void DrawAnimatedText(signed int x, signed int y, const char* Sprite, int delay_ms);
    };
} // namespace ascii

namespace ascii
{
    enum style
    {
        italic = TTF_STYLE_ITALIC,
        bold = TTF_STYLE_BOLD,
        normal = TTF_STYLE_NORMAL,
        outline = TTF_STYLE_OUTLINE,
        strikethrough = TTF_STYLE_STRIKETHROUGH,
        underline = TTF_STYLE_UNDERLINE,
    };
} // namespace ascii
#endif // FONT_H
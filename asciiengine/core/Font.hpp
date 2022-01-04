#ifndef ASCII_FONT_H
#define ASCII_FONT_H
#include <stdlib.h>
#include "SDL_FontCache.h"
#include "../common/util/StringUtil.hpp"

namespace ascii
{
    class Engine;
    
    class Font
    {
    private:
        FC_Font *font;
        int size;
    public:
        Font();
        ~Font();
        void initializeFont(Engine *engine, const char* path_to_font, int size, int style);
        int getSize() noexcept;
        FC_Font *getRawFont() noexcept;
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
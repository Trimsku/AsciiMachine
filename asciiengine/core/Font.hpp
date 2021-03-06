#pragma once
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
        Font() noexcept;
        ~Font() noexcept;
        void initializeFont(Engine *engine, const char* path_to_font, int size, int style) noexcept;
        inline int getSize() noexcept;
        inline FC_Font *getRawFont() noexcept;
    };
    int Font::getSize() noexcept {
        return size;
    }
    FC_Font *Font::getRawFont() noexcept {
        return font;
    }
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
#include "../../asciiengine/astd/uniprint.hpp"

const char* astd::Argument(astd::string *value) noexcept {
    return value->c_str();
}
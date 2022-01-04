#include "Options.hpp"

Options::Options() noexcept {}
Options::~Options() noexcept {}

Options &Options::getInstance() noexcept {
    static Options *instance = new Options();
    return *instance;
}

void Options::setDebugging(bool value) noexcept {
    _isDebugging = value;
}
bool Options::isDebugging() noexcept {
    return _isDebugging;
}
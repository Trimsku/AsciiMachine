#include "ITarget.hpp"

ITarget::ITarget(std::string _mainContent) noexcept {
    mainContent = _mainContent;
}
ITarget::~ITarget() noexcept {
    jointTarget = nullptr;
}
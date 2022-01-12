#include "IfEqualTarget.hpp"

IfEqualTarget::~IfEqualTarget() noexcept {}

IfEqualTarget::IfEqualTarget(std::string mainContent, bool *isNewLine) noexcept : ITarget(parseArg(mainContent, isNewLine)) {}
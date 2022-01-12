#include "IfdefTarget.hpp"

IfdefTarget::~IfdefTarget() noexcept {}

IfdefTarget::IfdefTarget(std::string mainContent, bool *isNewLine) noexcept : ITarget(parseArg(mainContent,isNewLine)) {}
#include "IfndefTarget.hpp"

IfndefTarget::~IfndefTarget() noexcept {}

IfndefTarget::IfndefTarget(std::string mainContent, bool *isNewLine) noexcept : ITarget(parseArg(mainContent, isNewLine)) {}
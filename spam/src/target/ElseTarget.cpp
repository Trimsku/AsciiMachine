#include "ElseTarget.hpp"

ElseTarget::~ElseTarget() noexcept {}

ElseTarget::ElseTarget(bool *isNewLine) noexcept : ITarget(parseArg(isNewLine)) {}
#include "PhonyTarget.hpp"

PhonyTarget::~PhonyTarget() noexcept {}

PhonyTarget::PhonyTarget() noexcept : ITarget(parseArg()) {}
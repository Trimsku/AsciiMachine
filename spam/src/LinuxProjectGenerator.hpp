#pragma once
#include "IProjectGenerator.hpp"

class LinuxProjectGenerator : public IProjectGenerator {
  public:
    LinuxProjectGenerator(std::string name) noexcept;
    ~LinuxProjectGenerator() noexcept;
};
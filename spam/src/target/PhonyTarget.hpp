#pragma once
#include "ITarget.hpp"

class PhonyTarget : public ITarget {
	private:
    inline std::string parseArg() noexcept;
	public:
		PhonyTarget() noexcept;
		~PhonyTarget() noexcept;
		inline std::string pop() noexcept override;
};

std::string PhonyTarget::parseArg() noexcept {
  return ".PHONY: ";
}

std::string PhonyTarget::pop() noexcept {
	return mainContent + content + '\n';
}
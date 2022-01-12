#pragma once
#include "ITarget.hpp"

class ElseTarget : public ITarget {
	private:
		inline std::string parseArg(bool *isNewLine) noexcept;
	public:
		ElseTarget(bool *isNewLine) noexcept;
		~ElseTarget() noexcept;
		inline std::string pop() noexcept override;
		inline bool isJointTarget() noexcept override;
};

bool ElseTarget::isJointTarget() noexcept {
	return true;
}

std::string ElseTarget::parseArg(bool *isNewLine) noexcept {
	*isNewLine = true;
  return "else";
}

std::string ElseTarget::pop() noexcept {
	return mainContent + '\n' + content + '\n';
} 
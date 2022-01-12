#pragma once
#include "ITarget.hpp"

class IfdefTarget : public ITarget {
	private:
		inline std::string parseArg(std::string content, bool *isNewLine) noexcept;
	public:
		IfdefTarget(std::string mainContent, bool *isNewLine) noexcept;
		~IfdefTarget() noexcept;
		inline std::string pop() noexcept override;
};
std::string IfdefTarget::parseArg(std::string content, bool *isNewLine) noexcept {
  return "ifdef " + content + '\n';
}

std::string IfdefTarget::pop() noexcept {
	return mainContent + '\n' + content + (jointTarget != nullptr ? '\n' + jointTarget->pop() : "") + "endif\n";
}
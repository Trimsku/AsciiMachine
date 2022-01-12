#pragma once
#include "ITarget.hpp"

class IfndefTarget : public ITarget {
	private:
		inline std::string parseArg(std::string content, bool *isNewLine) noexcept;
	public:
		IfndefTarget(std::string mainContent, bool *isNewLine) noexcept;
		~IfndefTarget() noexcept;
		inline std::string pop() noexcept override;
};

std::string IfndefTarget::parseArg(std::string content, bool *isNewLine) noexcept {
	*isNewLine = true;
  return "ifndef " + content;
}

std::string IfndefTarget::pop() noexcept {
	return mainContent + '\n' + content + '\n' + (jointTarget != nullptr ? '\n' + jointTarget->pop() : "") + "endif\n";
}
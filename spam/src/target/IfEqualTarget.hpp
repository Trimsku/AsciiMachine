#pragma once
#include "ITarget.hpp"

class IfEqualTarget : public ITarget {
	private:
		inline std::string parseArg(std::string content, bool *isNewLine) noexcept;
	public:
		IfEqualTarget(std::string mainContent, bool *isNewLine) noexcept;
		~IfEqualTarget() noexcept;
		inline std::string pop() noexcept override;
};
std::string IfEqualTarget::parseArg(std::string content, bool *isNewLine) noexcept {
	int delimiter = content.find("==");
  if( delimiter == std::string::npos ) {
    printf("In IfdefTarget class. ParseArgException: can't parse `%s`, expected '==' ", content.c_str());
    exit(0);
	}
	*isNewLine = true;
  return "ifeq (" + content.substr(0, delimiter) + ',' + content.substr(delimiter + 2, content.size()-delimiter-2) + ')';
}

std::string IfEqualTarget::pop() noexcept {
	return mainContent + '\n' + content + (jointTarget != nullptr ? '\n' + jointTarget->pop() : "") + "endif\n";
}
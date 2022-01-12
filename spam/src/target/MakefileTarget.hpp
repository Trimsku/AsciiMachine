#pragma once
#include "ITarget.hpp"

class MakefileTarget : public ITarget {
	private:
		std::string parseArg(std::string content, bool *isNewLine) noexcept;
	public:
    // ( target ) { dependency } -> target: dependency
		MakefileTarget(std::string mainContent, bool *isNewLine) noexcept;
		~MakefileTarget() noexcept;
		inline std::string pop() noexcept override;
};

std::string MakefileTarget::pop() noexcept {
	return mainContent + '\n' + content + '\n';
}
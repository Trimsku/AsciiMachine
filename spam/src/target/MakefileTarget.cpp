#include "MakefileTarget.hpp"

MakefileTarget::~MakefileTarget() noexcept {}

MakefileTarget::MakefileTarget(std::string mainContent, bool *isNewLine) noexcept : ITarget(parseArg(mainContent, isNewLine)) {}

std::string MakefileTarget::parseArg(std::string content, bool *isNewLine) noexcept {
	int startBracketPos = content.find('[');
	int endBracketPos = content.find(']');
	int startCurlyBracketPos = content.find('{');
	int endCurlyBracketPos = content.find('}');
	if(startBracketPos == std::string::npos) {
		printf("In MakefileTarget class. ParseArgError: can't parse `%s`, expected '['", content.c_str());
		exit(0);
	} else if(endBracketPos == std::string::npos) {
		printf("In MakefileTarget class. ParseArgError: can't parse `%s`, expected ']'", content.c_str());
		exit(0);
	} else if(startCurlyBracketPos == std::string::npos) {
		printf("In MakefileTarget class. ParseArgError: can't parse `%s`, expected '{'", content.c_str());
		exit(0);
	} else if(endCurlyBracketPos == std::string::npos) {
		printf("In MakefileTarget class. ParseArgError: can't parse `%s`, expected '}'", content.c_str());
		exit(0);
	}
	*isNewLine = true;

  return content.substr(startBracketPos+1, endBracketPos-startBracketPos-1) + ": " + content.substr(startCurlyBracketPos+1, endCurlyBracketPos-startCurlyBracketPos-1);
}
#include <string>

int main() {
	std::string name = "AsciiGame.mk";
	int extensionPointStrNumber = name.find('.');
	printf("%s\n", name.substr(0, extensionPointStrNumber).c_str());
	return 0;
}
#include "IProjectGenerator.hpp"

IProjectGenerator::~IProjectGenerator() noexcept {
  if(currentTarget != nullptr) delete currentTarget;
  if(jointTarget != nullptr) delete jointTarget;
}

IProjectGenerator::IProjectGenerator(std::string _name) noexcept : name(_name) {}

void IProjectGenerator::push(TargetType targetType, std::string content) noexcept {
  if(targetType == TargetType::ELSE) {
    if(jointTarget != nullptr) delete jointTarget;
    jointTarget = new ElseTarget(&isNewLine);
    currentTarget->jointTarget = jointTarget;
  } else {
    if(currentTarget != nullptr) delete currentTarget;
    switch(targetType) {
      case(TargetType::IFDEF): currentTarget = new IfdefTarget(content, &isNewLine); break;
      case(TargetType::IFEQ): currentTarget = new IfEqualTarget(content, &isNewLine); break;
      case(TargetType::IFNDEF): currentTarget = new IfndefTarget(content, &isNewLine); break;
      case(TargetType::MAKEFILE_TARGET): currentTarget = new MakefileTarget(content, &isNewLine); break;
      case(TargetType::PHONY): currentTarget = new PhonyTarget(); break;
    }
  }
}
void IProjectGenerator::add(std::string str) noexcept {
  if(currentTarget == nullptr) {
    if(str != "\n") printf("[Warning] str \"%s\" is not in TargetType scope.\n", str.c_str());
    content += str;
  } else if(jointTarget != nullptr) jointTarget->add(str, &isNewLine);
  else currentTarget->add(str, &isNewLine);

  isNewLine = currentTarget != nullptr ? str.find('\n') != std::string::npos : false;
}
void IProjectGenerator::pop() noexcept {
  if(currentTarget != nullptr) {
    content += currentTarget->pop();
    delete currentTarget;
    if(jointTarget != nullptr) delete jointTarget;
    currentTarget = nullptr;
    jointTarget = nullptr;
    return;
  }
  currentTarget = nullptr;
  jointTarget = nullptr;
  printf("[Warning] Catch `void IProjectGenerator::pop()` using without scope.");
}
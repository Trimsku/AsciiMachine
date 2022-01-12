#pragma once
#include <string>
#include <vector>

enum class TargetType : short int {
  PHONY = 1,
  IFEQ = 2,
  IFNDEF = 3,
  IFDEF = 4,
  ELSE = 5,
  MAKEFILE_TARGET = 6
};

class ITarget {
  protected:
    friend class IProjectGenerator;
    ITarget* jointTarget = nullptr;
    std::string content;
    std::string mainContent;
  public:
    virtual ~ITarget() noexcept;
  	ITarget(std::string mainContent) noexcept;
    inline virtual void add(std::string newContent, bool *isNewLine) noexcept;
    virtual std::string pop() = 0;
    inline virtual bool isJointTarget() noexcept;
};

bool ITarget::isJointTarget() noexcept {
    return false;
}
void ITarget::add(std::string newContent, bool *isNewLine) noexcept {
    if(*isNewLine) {
      content += '\t';
      *isNewLine = false;
    }
    *isNewLine = newContent.find('\n') != std::string::npos;
    content += newContent;
}
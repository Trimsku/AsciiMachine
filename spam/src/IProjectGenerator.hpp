#pragma once

#include <string>
#include <vector>
#include "target/ITarget.hpp"
#include "target/ElseTarget.hpp"
#include "target/IfdefTarget.hpp"
#include "target/IfEqualTarget.hpp"
#include "target/IfndefTarget.hpp"
#include "target/MakefileTarget.hpp"
#include "target/PhonyTarget.hpp"

class IProjectGenerator
{
protected:
    using super = IProjectGenerator;
    std::string content, name;
    ITarget *currentTarget = nullptr;
    ITarget *jointTarget = nullptr;
    bool isNewLine = false;
public:
    virtual ~IProjectGenerator() noexcept;
    IProjectGenerator(std::string name) noexcept;
    inline virtual std::string getCppCompiler() noexcept;
    void push(TargetType targetType, std::string content = "") noexcept;
    void add(std::string str) noexcept;
    inline void endl() noexcept;
    void pop() noexcept;
    inline std::string getContent() noexcept;
};

void IProjectGenerator::endl() noexcept {
    add("\n");
}

std::string IProjectGenerator::getContent() noexcept {
    return content;
}

std::string IProjectGenerator::getCppCompiler() noexcept {
    return "g++";
}
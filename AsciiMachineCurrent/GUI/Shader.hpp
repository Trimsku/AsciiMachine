#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

namespace asciiGUI {
    
    class Shader
    {
    public:    
        GLuint Program;
        unsigned int ID;
        // Make shader
        Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
        void Use();
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
    };
}
#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "../astd/String.hpp"
#include "../common/util/StringUtil.hpp"

#ifndef __APPLE__
namespace gl {

static bool isGLExtensionsInitialized = false;

static PFNGLCREATESHADERPROC glCreateShader;
static PFNGLSHADERSOURCEPROC glShaderSource;
static PFNGLCOMPILESHADERPROC glCompileShader;
static PFNGLGETSHADERIVPROC glGetShaderiv;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
static PFNGLDELETESHADERPROC glDeleteShader;
static PFNGLATTACHSHADERPROC glAttachShader;
static PFNGLCREATEPROGRAMPROC glCreateProgram;
static PFNGLLINKPROGRAMPROC glLinkProgram;
static PFNGLVALIDATEPROGRAMPROC glValidateProgram;
static PFNGLGETPROGRAMIVPROC glGetProgramiv;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
static PFNGLUSEPROGRAMPROC glUseProgram;

bool initGLExtensions();
}
#endif

namespace ascii { namespace client {

#ifdef __APPLE__
void initializeFileSystem() {
	CFBundleRef mainBundle = CFBundleGetMainBundle();
	CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
	char path[PATH_MAX];
	if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
	{
		printf("Couldn't get file system representation!\n");
	}
	CFRelease(resourcesURL);
	chdir(path);
}
#endif

class Shader {
    public:
        Shader();
        Shader(astd::string vertShaderFilePath, astd::string fragShaderFilePath);
        void use();
		void unUse();
    private:
        unsigned int programId;
        bool compile(astd::string &vertShaderSource, astd::string &fragShaderSource);
};
}}

#endif
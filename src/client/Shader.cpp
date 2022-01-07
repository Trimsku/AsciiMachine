#include "../../asciiengine/client/Shader.hpp"

namespace gl {
    bool initGLExtensions() {
        glCreateShader = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
    	glShaderSource = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
    	glCompileShader = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
    	glGetShaderiv = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
    	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");
    	glDeleteShader = (PFNGLDELETESHADERPROC)SDL_GL_GetProcAddress("glDeleteShader");
    	glAttachShader = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
    	glCreateProgram = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
    	glLinkProgram = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
    	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)SDL_GL_GetProcAddress("glValidateProgram");
    	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");
    	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)SDL_GL_GetProcAddress("glGetProgramInfoLog");
    	glUseProgram = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");

	    return glCreateShader && glShaderSource && glCompileShader && glGetShaderiv && 
		    glGetShaderInfoLog && glDeleteShader && glAttachShader && glCreateProgram &&
    		glLinkProgram && glValidateProgram && glGetProgramiv && glGetProgramInfoLog &&
	    	glUseProgram;
    }
}

namespace ascii { namespace client {

Shader::Shader() {

}

Shader::Shader(astd::string vertShaderFilePath, astd::string fragShaderFilePath) {
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    
    #ifndef __APPLE__
    if(!gl::isGLExtensionsInitialized) {
        if(!gl::initGLExtensions()) {
            printf("Your device cannot load GLExtensions! Report bug to game developer!");
            return;
        }
        gl::isGLExtensionsInitialized = true;
    }
    #endif

    printf("Starting shader loading(vertex_shader: %s, fragment_shader: %s)...\n", vertShaderFilePath.c_str(), fragShaderFilePath.c_str());
    astd::string vertShaderSource, fragShaderSource;
    vertShaderSource = ascii::util::getFileResources(vertShaderFilePath.c_str());
    fragShaderSource = ascii::util::getFileResources(fragShaderFilePath.c_str());
    if(!compile(vertShaderSource, fragShaderSource)) {
        printf("Error: cannot compile shader sources!\n");
        return;
    }
    printf("Shaders loaded successful! (programId: %i)\n", programId);
}

bool Shader::compile(astd::string &vertShaderSource, astd::string &fragShaderSource) {
    const char* vertShaderRawSource = vertShaderSource.c_str();
    const char* fragShaderRawSource = fragShaderSource.c_str();
    GLuint fragShader, vertShader;
    int success;
    char infoLog[512];
    // vertex Shader
    vertShader = gl::glCreateShader(GL_VERTEX_SHADER);
    gl::glShaderSource(vertShader, 1, &vertShaderRawSource, NULL);
    gl::glCompileShader(vertShader);
    gl::glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    
    if(!success) {
        gl::glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
        printf("Shader::compile(), vertex_shader_compiling_stage:\n%s\n", infoLog);
        return GL_FALSE;
    }
    // fragment Shader
    fragShader = gl::glCreateShader(GL_FRAGMENT_SHADER);
    gl::glShaderSource(fragShader, 1, &fragShaderRawSource, NULL);
    gl::glCompileShader(fragShader);
    gl::glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        gl::glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        printf("Shader::compile(), fragment_shader_compiling_stage:\n%s\n", infoLog);
        return GL_FALSE;
    };

    // shader Program
    programId = gl::glCreateProgram();
    gl::glAttachShader(programId, vertShader);
    gl::glAttachShader(programId, fragShader);
    gl::glLinkProgram(programId);

    gl::glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if(!success)
    {
        gl::glGetProgramInfoLog(programId, 512, NULL, infoLog);
        printf("In Shader::compile(), linking_stage: \n%s\n", infoLog);
        return GL_FALSE;
    }
    gl::glDeleteShader(vertShader);
    gl::glDeleteShader(vertShader);
    return GL_TRUE;
}

void Shader::use() {
    gl::glUseProgram(programId);
}
void Shader::unUse() {
    gl::glUseProgram( NULL );
}

}}
#ifndef _SHADER_LOADER_H
#define _SHADER_LOADER_H

#include <GL/glew.h>
#include <string>

namespace Shader {
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);    
}

#endif

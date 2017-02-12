#ifndef _SHADER_PROGRAM_H
#define _SHADER_PROGRAM_H

#include <GL/glew.h>
#include <string>
#include "../GlmCommon.h"

namespace Shader {
    class ShaderProgram {
    private:
        GLuint m_programId;
    protected:
        virtual void getUniformLocations() = 0;
        GLuint getId() const;
        void loadFloat(GLuint location, float value);
        void loadMatrix4(GLuint location, const glm::mat4& matrix);
    public:
        ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
        ~ShaderProgram();

        void bind();
        void unbind();
    };
}

#endif

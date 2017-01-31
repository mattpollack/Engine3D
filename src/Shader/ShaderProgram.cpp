#include "ShaderProgram.h"
#include "ShaderLoader.h"

namespace Shader {
    ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    : m_programId (loadShader(vertexShaderFile, fragmentShaderFile)) {
        // ..
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(m_programId);
    }

    void ShaderProgram::bind() {
        glUseProgram(m_programId);
    }

    void ShaderProgram::unbind() {
        glUseProgram(0);
    }

    GLuint ShaderProgram::getId() const {
        return m_programId;
    }

    void ShaderProgram::loadFloat(GLuint location, float value) {
        glUniform1f(location, value);
    }

    void ShaderProgram::loadMatrix4(GLuint location, const glm::mat4& matrix) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}

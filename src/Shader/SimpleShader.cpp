#include "SimpleShader.h"
#include "../Maths/Matrix.h"

namespace Shader {
    SimpleShader::SimpleShader()
    : ShaderProgram("SimpleVertex", "SimpleFragment") {
        getUniformLocations();

        bind();
        loadMatrix4(m_locationProjMatrix, Maths::createProjMatrix());
        unbind();
    }

    void SimpleShader::setTime(float time) {
        loadFloat(m_locationTime, time);
    }

    void SimpleShader::setViewMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationViewMatrix, matrix);
    }

    void SimpleShader::setModelMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationModelMatrix, matrix);
    }

    void SimpleShader::setProjMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationProjMatrix, matrix);
    }

    void SimpleShader::getUniformLocations() {
        m_locationTime = glGetUniformLocation(getId(), "time");
        m_locationViewMatrix = glGetUniformLocation(getId(), "viewMatrix");
        m_locationModelMatrix = glGetUniformLocation(getId(), "modelMatrix");
        m_locationProjMatrix = glGetUniformLocation(getId(), "projMatrix");
    }
}

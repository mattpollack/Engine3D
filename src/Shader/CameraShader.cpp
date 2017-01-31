#include "CameraShader.h"
#include "../Maths/Matrix.h"

namespace Shader {
    CameraShader::CameraShader()
    : ShaderProgram("CameraVertex", "CameraFragment") {
        getUniformLocations();

        bind();
        loadMatrix4(m_locationProjMatrix, Maths::createProjMatrix());
        unbind();
    }

    void CameraShader::setViewMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationViewMatrix, matrix);
    }

    void CameraShader::setModelMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationModelMatrix, matrix);
    }

    void CameraShader::setProjMatrix(const glm::mat4& matrix) {
        loadMatrix4(m_locationProjMatrix, matrix);
    }

    void CameraShader::getUniformLocations() {
        m_locationViewMatrix = glGetUniformLocation(getId(), "viewMatrix");
        m_locationModelMatrix = glGetUniformLocation(getId(), "modelMatrix");
        m_locationProjMatrix = glGetUniformLocation(getId(), "projMatrix");
    }
}

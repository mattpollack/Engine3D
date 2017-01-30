#include "SimpleShader.h"

namespace Shader {
    SimpleShader::SimpleShader()
    : ShaderProgram("SimpleVertex", "SimpleFragment") {
        getUniformLocations();
    }

    void SimpleShader::setTime(float time) {
        loadFloat(m_locationTime, time);
    }

    void SimpleShader::getUniformLocations() {
        m_locationTime = glGetUniformLocation(getId(), "time");
    }
}

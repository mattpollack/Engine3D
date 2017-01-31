#ifndef _SIMPLE_SHADER_H
#define _SIMPLE_SHADER_H

#include "ShaderProgram.h"
#include "../GlmCommon.h"

namespace Shader {
    class SimpleShader : public ShaderProgram {
    private:
        GLuint m_locationTime = 0;
        GLuint m_locationViewMatrix = 0;
        GLuint m_locationModelMatrix = 0;
        GLuint m_locationProjMatrix = 0;

        void getUniformLocations() override;
    public:
        SimpleShader();
        void setTime(float time);
        void setViewMatrix(const glm::mat4& matrix);
        void setModelMatrix(const glm::mat4& matrix);
        void setProjMatrix(const glm::mat4& matrix);
    };
}

#endif

#ifndef _SIMPLE_SHADER_H
#define _SIMPLE_SHADER_H

#include "ShaderProgram.h"

namespace Shader {
    class SimpleShader : public ShaderProgram {
    private:
        GLuint m_locationTime = 0;
        void getUniformLocations() override;
    public:
        SimpleShader();
        void setTime(float time);
    };
}

#endif

#ifndef _MATRIX_H
#define _MATRIX_H

#include "../GlmCommon.h"

namespace Renderer {
    class Entity;
}

namespace Maths {
    glm::mat4 createViewMatrix(const Renderer::Entity& entity);
    glm::mat4 createModelMatrix(const Renderer::Entity& entity);
    glm::mat4 createProjMatrix();
}

#endif

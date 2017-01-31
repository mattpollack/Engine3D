#include "Matrix.h"
#include "../Renderer.h"
#include "../Display.h"

namespace Maths {
    glm::mat4 createViewMatrix(const Renderer::Entity& entity) {
        glm::mat4 matrix;

        matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});
        matrix = glm::translate(matrix, -entity.position);

        return matrix;
    }

    glm::mat4 createModelMatrix(const Renderer::Entity& entity) {
        glm::mat4 matrix;

        matrix = glm::translate(matrix, entity.position);
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
        matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});    

        return matrix;
    }

    glm::mat4 createProjMatrix() {
        return glm::perspective(
            glm::radians(120.0f),
            (float)Display::WIDTH / (float)Display::HEIGHT,
            0.0010f,
            1000.0f
        );
    }
}

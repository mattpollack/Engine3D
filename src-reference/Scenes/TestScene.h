#include "../Renderer.h"
#include "../Texture/Texture.h"
#include "../Shader/CameraShader.h"
#include "../Maths/Matrix.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene : public Scene {
private:
    Renderer::Entity testEntity;

    std::unique_ptr<Object::Mesh> testMesh;

    sf::Clock clock;
public:
    TestScene() {
        testMesh = std::make_unique<Object::Mesh>();
        testMesh.get()->load("cube");

        /**
         * Register shader, meshes, and textures
         */
        Renderer::registerMesh("cube", testMesh);

        /**
         * Add shaders, meshes, and textures to entities
         */
        testEntity.addMesh("cube");
    }

    void enter() {
        printf("%s\n", "Entering");
    }

    void update() {
        testEntity.position = {
            sin(clock.getElapsedTime().asSeconds())*2,
            cos(clock.getElapsedTime().asSeconds())*2,
            -3
        };
        testEntity.rotation = {
            sin(clock.getElapsedTime().asSeconds()/2)*180,
            0,
            0
        };
    }

    void draw() {
        Renderer::draw(testEntity);
    }

    void exit() {
        printf("%s\n", "Exiting");
    }
};

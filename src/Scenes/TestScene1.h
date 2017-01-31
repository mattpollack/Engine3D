#include "../Renderer.h"
#include "../Texture/Texture.h"
#include "../Shader/CameraShader.h"
#include "../Maths/Matrix.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene1 : public Scene {
private:
    std::vector<Renderer::Entity> testEntities;
    std::unique_ptr<Object::Mesh> testMesh;

    sf::Clock clock;
public:
    TestScene1() {
        testMesh = std::make_unique<Object::Mesh>();
        testMesh.get()->load("cube");

        /**
         * Register shader, meshes, and textures
         */
        Renderer::registerMesh("cube", testMesh);

        /**
         * Add shaders, meshes, and textures to entities
         */
        for (int i = 0; i < 64; ++i) {
            testEntities.push_back(Renderer::Entity());
            testEntities[i].addMesh("cube");
        }
    }

    void enter() {
        printf("%s\n", "Entering");
    }

    void update() {
        for (int i = 0; i < testEntities.size(); ++i) {
            testEntities[i].position = {
                -16 + (i % 8)*4,
                -16 + (i/8)*4,
                -16
            };

            testEntities[i].rotation = {
                sin(clock.getElapsedTime().asSeconds()/2)*180,
                0,
                0
            };
        }
    }

    void draw() {
        for (int i = 0; i < testEntities.size(); ++i) {
            Renderer::draw(testEntities[i]);
        }
    }

    void exit() {
        printf("%s\n", "Exiting");
    }
};

#include "../Renderer.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene1 : public Scene {
private:
    std::vector<Renderer::Entity> testEntities;
    std::unique_ptr<Object::Mesh> testMesh;

    sf::Clock clock;
public:
    TestScene1() {
        /**
         * Create shader, mesh, texture for registering
         */
        testMesh = std::make_unique<Object::Mesh>();
        testMesh.get()->load("cube");

        /**
         * Register shader, mesh, and texture
         */
        Renderer::registerMesh("cube", testMesh);

        /**
         * Add shader, meshe, and texture to entities
         */
        for (int i = 0; i < 64; ++i) {
            testEntities.push_back(Renderer::Entity());
            testEntities[i].addMesh("cube");
            testEntities[i].position = {
                -16 + (i % 8)*4,
                -16 + (i/8)*4,
                -16
            };
        }
    }

    void enter() {
        printf("%s\n", "Entering");
    }

    void update() {
        for (int i = 0; i < testEntities.size(); ++i) {
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

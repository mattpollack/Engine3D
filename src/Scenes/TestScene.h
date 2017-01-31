#include "../Renderer.h"
#include "../Texture/Texture.h"
#include "../Shader/CameraShader.h"
#include "../Maths/Matrix.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene : public Scene {
private:
    Renderer::Entity testEntity;

    sf::Clock clock;
public:
    TestScene() {
        std::unique_ptr<Object::Mesh> testMesh(new Object::Mesh);
        testMesh.get()->load("cube");

        Renderer::registerMesh("cube", testMesh);

        testEntity.addMesh("cube");
    }

    void enter() {
        printf("%s\n", "Entering");
    }

    void update() {
        testEntity.position = {
            0,//sin(clock.getElapsedTime().asSeconds())*2,
            0,//cos(clock.getElapsedTime().asSeconds())*2,
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

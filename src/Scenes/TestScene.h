#include "../Renderer.h"
//#include "../Model.h"
#include "../Texture/Texture.h"
#include "../Shader/SimpleShader.h"
#include "../Maths/Matrix.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene : public Scene {
private:
    Object::Mesh testMesh;
    Shader::SimpleShader testShader;
    Texture::BasicTexture testTexture;
    Renderer::Entity testEntity;
    Renderer::Entity testCamera;

    sf::Clock clock;
public:
    // Custom constructor to pass manager
    TestScene() {
        testMesh.load("cube");
        //testTexture.load("sample0");
        testEntity.position = {0, 0, -3};
        testEntity.rotation = {0, 0, 0};

        testCamera.position = {0, 0, 0};
        testCamera.rotation = {0, 0, 0};
    }

    void enter() {
        printf("%s\n", "Entering");
        testShader.setModelMatrix(Maths::createModelMatrix(testEntity));
    }

    void update() {
        // ..
    }

    void draw() {
        testShader.bind();
        testShader.setTime(clock.getElapsedTime().asSeconds());
        testShader.setViewMatrix(Maths::createViewMatrix(testCamera));
        //testTexture.bind();
        testMesh.bind();

        glDrawElements(GL_TRIANGLES, testMesh.getIndicesCount(), GL_UNSIGNED_INT, nullptr);

        testMesh.unbind();
        //testTexture.unbind();
        testShader.unbind();
    }

    void exit() {
        printf("%s\n", "Exiting");
    }
};

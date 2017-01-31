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
        testEntity.position.z = -3;
    }

    void enter() {
        printf("%s\n", "Entering");
        testShader.bind();
        testShader.setProjMatrix(Maths::createProjMatrix());
        testShader.setViewMatrix(Maths::createViewMatrix(testCamera));
        testShader.unbind();
    }

    void update() {
        testEntity.position.x = sin(clock.getElapsedTime().asSeconds())*2;
        testEntity.position.y = cos(clock.getElapsedTime().asSeconds())*2;
    }

    void draw() {
        testShader.bind();
        testShader.setTime(clock.getElapsedTime().asSeconds());
        //testTexture.bind();
        testMesh.bind();
        testShader.setModelMatrix(Maths::createModelMatrix(testEntity));

        glDrawElements(GL_TRIANGLES, testMesh.getIndicesCount(), GL_UNSIGNED_INT, nullptr);

        testMesh.unbind();
        //testTexture.unbind();
        testShader.unbind();
    }

    void exit() {
        printf("%s\n", "Exiting");
    }
};

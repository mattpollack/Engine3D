#include "../Texture/Texture.h"
#include "../Shader/SimpleShader.h"
#include "../Model.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TestScene : public Scene {
private:
    SceneManager * manager;
    std::vector<GLfloat> vpos = {
        0.5, 0.5,
        -0.5, 0.5,
        -0.5, -0.5,
        0.5, -0.5,
    };
    std::vector<GLfloat> tcoo = {
        1.0, 0.0,
        0.0, 0.0,
        0.0, 1.0,
        1.0, 1.0,
    };
    std::vector<GLuint> indices = {
        0, 1, 2,
        2, 3, 0
    };
    Model testModel;
    Shader::SimpleShader testShader;
    Texture::BasicTexture testTexture;
    sf::Clock clock;
public:
    // Custom constructor to pass manager
    TestScene(SceneManager * p_manager)
    : testModel(vpos, tcoo, indices) {
        manager = p_manager;
        testTexture.load("sample0");
    }

    void enter() {
        printf("%s\n", "Entering");
    }

    void update() {
        // ..
    }

    void draw() {
        testShader.bind();
        testShader.setTime(clock.getElapsedTime().asSeconds());
        testTexture.bind();
        testModel.bind();

        glDrawElements(GL_TRIANGLES, testModel.getIndicesCount(), GL_UNSIGNED_INT, nullptr);

        testModel.unbind();
        testTexture.unbind();
        testShader.unbind();
    }

    void exit() {
        printf("%s\n", "Exiting");
    }
};

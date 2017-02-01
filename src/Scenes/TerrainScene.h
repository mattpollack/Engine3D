#include "../Renderer.h"

#include <math.h>
#include <SFML/System/Clock.hpp>

class TerrainScene : public Scene {
private:
    /**
     * NOISE
     */
    float _r(float value, float offset) {
        float result = sin(value) * offset;
        return result - floor(result);
    }

    float xzToY(float x, float z) {
        float t0 = _r(x, 3499);
        float t1 = _r(x, 3571);
        float t2 = _r(_r(x/z, 3571), 3499);
        float t3 = _r(_r(z/x, 3571), 3499);

        return (_r(t0+t1+t2+t3, 3499) + _r(t0+t1+t2+t3, 3571))/2.0f;
    }

private:
    Renderer::Entity player;
    sf::Clock clock;

    std::unique_ptr<Object::Mesh> terrain;
    std::vector<GLfloat> terrainVertices;
    std::vector<GLuint>  terrainIndices;
    int terrainSize = 100;
    int terrainHeightMax = 3;
public:
    TerrainScene() {
        /**
         * Create shader, mesh, texture for registering
         */
        for (int x = 0; x < terrainSize; ++x) {
            for (int z = 0; z < terrainSize; ++z) {
                terrainVertices.push_back(-terrainSize/2.0f + x);
                terrainVertices.push_back(std::max(xzToY(x, z)*terrainHeightMax, 0.4f));
                terrainVertices.push_back(-terrainSize/2.0f + z);
            }
        }

        for (int x = 0; x < terrainSize - 1; ++x) {
            for (int z = 0; z < terrainSize - 1; ++z) {
                // T1
                terrainIndices.push_back(z + 0 + ((x + 0) * terrainSize));
                terrainIndices.push_back(z + 1 + ((x + 0) * terrainSize));
                terrainIndices.push_back(z + 0 + ((x + 1) * terrainSize));

                // T2
                terrainIndices.push_back(z + 0 + ((x + 1) * terrainSize));
                terrainIndices.push_back(z + 1 + ((x + 0) * terrainSize));
                terrainIndices.push_back(z + 1 + ((x + 1) * terrainSize));
            }
        }

        terrain = std::make_unique<Object::Mesh>();
        terrain.get()->load(terrainVertices, terrainIndices);

        /**
         * Register shader, mesh, and texture
         */
        Renderer::registerMesh("terrain", terrain);

        /**
         * Add shader, mesh, and texture to entities
         */
        player.addMesh("terrain");
    }

    void enter() {
        printf("%s\n", "Entering Terrain");
        player.position = {
            0,
            -5,
            -terrainSize/2
        };
    }

    void update() {
        player.rotation = {
            0,
            fmod(clock.getElapsedTime().asSeconds(), 360),
            0
        };
    }

    void draw() {
        Renderer::draw(player);
    }

    void exit() {
        printf("%s\n", "Exiting Terrain");
    }
};

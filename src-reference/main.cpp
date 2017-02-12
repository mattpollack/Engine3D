#include "Renderer.h"
#include "Scene.h"
#include "Scenes/TerrainScene.h"

#include <memory>

int main() {
    Renderer::init();
    std::unique_ptr<Scene> scene(new TerrainScene());

    Renderer::addScene("Terrain_Scene", scene);
    Renderer::toScene("Terrain_Scene");
    Renderer::start();
}

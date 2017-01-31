#include "Renderer.h"
#include "Scene.h"
#include "Scenes/TestScene.h"

#include <memory>

int main() {
    Renderer::init();
    std::unique_ptr<Scene> testScene(new TestScene());

    Renderer::addScene("test", testScene);
    Renderer::toScene("test");
    Renderer::start();
}

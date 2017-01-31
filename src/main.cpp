#include "Renderer.h"
#include "Scene.h"
#include "Scenes/TestScene1.h"

#include <memory>

int main() {
    Renderer::init();
    std::unique_ptr<Scene> testScene(new TestScene1());

    Renderer::addScene("test", testScene);
    Renderer::toScene("test");
    Renderer::start();
}

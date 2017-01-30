#include "SceneManager.h"
#include "Scene.h"
#include "Scenes/TestScene.h"

#include <memory>

SceneManager game;

int main() {
    std::unique_ptr<Scene> testScene(new TestScene(&game));

    game.addScene("test", testScene);
    game.toScene("test");
    game.start();
}

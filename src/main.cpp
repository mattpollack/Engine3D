
#include "SceneManager.h"
#include "Scene.h"
#include "Scenes/TestScene.h"
#include "Object/Object.h"

#include <memory>

int main() {
    Object::Mesh testMesh = Object::meshLoad("cube");

    SceneManager game;

    std::unique_ptr<Scene> testScene(new TestScene(&game));

    game.addScene("test", testScene);
    game.toScene("test");
    game.start();
}

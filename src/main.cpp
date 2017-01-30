/**
 * PREMISE
 * Gain reputation as you complete dungeons by travelling around a procedurally
 * generated world. Gaining reputation is like gaining experience. Villages and
 * NPC generate responses proportional to local reputation. Emphasis on
 * survival, and crafting.
 *
 * TENTATIVE GOALS
 * - Generate terrain based on character position
 * - Move along terrain endlessly
 *
 * TODO
 * - TODO
 */

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

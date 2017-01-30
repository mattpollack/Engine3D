#include "SceneManager.h"
#include "Scene.h"
#include "Display.h"
#include <stdexcept>

SceneManager::SceneManager() {
    Display::init();
}

void SceneManager::addScene(const std::string title, std::unique_ptr<Scene>& scene) {
    sceneList[title] = std::move(scene);
}

void SceneManager::toScene(std::string title) {
    if (sceneCurrent != nullptr) {
        sceneCurrent->exit();
    }

    auto sceneNext = sceneList.find(title);

    if (sceneNext == sceneList.end()) {
        throw std::runtime_error("Scene with title '" + title + "' doesn't exist");
    }
    else {
        sceneCurrent = sceneNext->second.get();
        sceneCurrent->enter();
    }
}

void SceneManager::start() {
    isStarted = true;

    while (Display::isOpen() && isStarted) {
        Display::checkWindowEvents();
        Display::clear();

        // TODO deltaT
        sceneCurrent->update();
        sceneCurrent->draw();

        Display::display();
    }
}

void SceneManager::stop() {
    isStarted = false;
}

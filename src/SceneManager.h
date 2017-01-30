#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <string>
#include <memory>
#include <map>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

// Forward declaration
class Scene;

class SceneManager {
private:
    std::map<std::string, std::unique_ptr<Scene>> sceneList;
    Scene * sceneCurrent = nullptr;
    bool isStarted = false;
public:
    SceneManager();
    void addScene(const std::string title, std::unique_ptr<Scene>& scene);
    void toScene(const std::string title);
    void start();
    void stop();
};

#endif

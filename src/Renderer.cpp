#include "Renderer.h"
#include "Display.h"

#include <stdexcept>

namespace Renderer {
    /**
     * Rendering Optimizations
     */
    std::map<std::string, std::unique_ptr<Object::Mesh>>          m_meshes;
    std::map<std::string, std::unique_ptr<Shader::ShaderProgram>> m_shaders;
    std::map<std::string, std::unique_ptr<Texture::BasicTexture>> m_textures;

    void registerMesh(const std::string& name, std::unique_ptr<Object::Mesh>& mesh) {

    }

    void registerShader(const std::string& name, std::unique_ptr<Shader::ShaderProgram>& shader) {

    }

    void registerTexture(const std::string& name, std::unique_ptr<Texture::BasicTexture>& texture) {

    }

    /**
     * Scene Management
     */
    std::map<std::string, std::unique_ptr<Scene>> sceneList;
    Scene * sceneCurrent = nullptr;

    void init() {
        Display::init();
    }

    void addScene(const std::string& title, std::unique_ptr<Scene>& scene) {
        sceneList[title] = std::move(scene);
    }

    void toScene(const std::string& title) {
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

    void start() {
        while (Display::isOpen()) {
            Display::checkWindowEvents();
            Display::clear();

            // TODO deltaT
            sceneCurrent->update();
            sceneCurrent->draw();

            Display::display();
        }
    }

    /**
     * Entity Management
     */
}

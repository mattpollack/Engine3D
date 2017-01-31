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
        m_meshes[name] = std::move(mesh);
    }

    void registerShader(const std::string& name, std::unique_ptr<Shader::ShaderProgram>& shader) {
        m_shaders[name] = std::move(shader);
    }

    void registerTexture(const std::string& name, std::unique_ptr<Texture::BasicTexture>& texture) {
        m_textures[name] = std::move(texture);
    }

    /**
     * Scene Management
     */
    std::map<std::string, std::unique_ptr<Scene>> sceneList;
    Scene * sceneCurrent = nullptr;

    void init() {
        Display::init();
    }

    void addScene(const std::string& name, std::unique_ptr<Scene>& scene) {
        sceneList[name] = std::move(scene);
    }

    void toScene(const std::string& name) {
        if (sceneCurrent != nullptr) {
            sceneCurrent->exit();
        }

        auto sceneNext = sceneList.find(name);

        if (sceneNext == sceneList.end()) {
            throw std::runtime_error("Scene with name '" + name + "' doesn't exist");
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
    /*Entity::Entity(const std::string& mesh, const std::string& shader, const std::string& texture) {
        position.x = 0;
        position.y = 0;
        position.z = 0;
    }*/

    void draw(const Entity& entity) {
        // ..
    }
}

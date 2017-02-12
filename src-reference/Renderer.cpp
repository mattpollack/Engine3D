#include "Renderer.h"
#include "Display.h"
#include "Maths/Matrix.h"

#include <stdexcept>

namespace Renderer {
    // Entity management
    std::vector<Entity> entitiesToDraw;

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

    Object::Mesh * getMeshPtr(const std::string& name) {
        return m_meshes[name].get();
    }

    Shader::ShaderProgram * getShaderPtr(const std::string& name) {
        return m_shaders[name].get();
    }

    Texture::BasicTexture * getTexturePtr(const std::string& name) {
        return m_textures[name].get();
    }

    /**
     * Scene Management
     */
    std::map<std::string, std::unique_ptr<Scene>> sceneList;
    Scene * sceneCurrent = nullptr;
    std::unique_ptr<Shader::CameraShader> camera;
    Entity cameraEntity;

    void init() {
        Display::init();

        camera = std::make_unique<Shader::CameraShader>();
        camera->bind();
        camera->setProjMatrix(Maths::createProjMatrix());
        camera->setViewMatrix(Maths::createViewMatrix(cameraEntity));
        camera->unbind();
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

    Shader::ShaderProgram * r_shader = nullptr;
    Texture::BasicTexture * r_texture = nullptr;
    Object::Mesh * r_mesh = nullptr;

    void start() {
        while (Display::isOpen()) {
            Display::checkWindowEvents();
            Display::clear();

            sceneCurrent->update();
            sceneCurrent->draw();

            r_shader = nullptr;
            r_texture = nullptr;
            r_mesh = nullptr;

            camera->bind();
            for (int i = 0; i < entitiesToDraw.size(); ++i) {
                if (m_meshes.find(entitiesToDraw[i].meshName) != m_meshes.end()) {
                    r_mesh = m_meshes[entitiesToDraw[i].meshName].get();
                }
                else {
                    continue;
                }

                if (m_shaders.find(entitiesToDraw[i].shaderName) != m_shaders.end()) {
                    r_shader = m_shaders[entitiesToDraw[i].shaderName].get();
                    r_shader->bind();
                }

                if (m_textures.find(entitiesToDraw[i].textureName) != m_textures.end()) {
                    r_texture = m_textures[entitiesToDraw[i].textureName].get();
                    r_texture->bind();
                }

                r_mesh->bind();
                camera->setModelMatrix(Maths::createModelMatrix(entitiesToDraw[i]));
                glDrawElements(GL_TRIANGLES, r_mesh->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
                r_mesh->unbind();

                if (r_texture != nullptr) {
                    r_texture->unbind();
                }

                if (r_shader != nullptr) {
                    r_shader->unbind();
                }
            }
            camera->unbind();

            entitiesToDraw.clear();

            Display::display();
        }
    }

    /**
     * Entity Management
     */
    void Entity::addMesh(const std::string& name) {
        meshName = name;
    }

    void Entity::addShader(const std::string& name) {
        shaderName = name;
    }

    void Entity::addTexture(const std::string& name) {
        textureName = name;
    }

    void draw(const Entity& entity) {
        entitiesToDraw.push_back(entity);
    }
}

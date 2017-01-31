#ifndef _RENDERER_H
#define _RENDERER_H

#include "Object/Object.h"
#include "Texture/Texture.h"
#include "Shader/ShaderProgram.h"
#include "Scene.h"

#include <map>
#include <string>
#include <memory>

#include "GlmCommon.h"

/**
 * RENDERER
 * ...
 */
namespace Renderer {
    /**
     * Rendering Optimizations
     */
    void registerMesh   (const std::string& name, std::unique_ptr<Object::Mesh>& mesh);
    void registerShader (const std::string& name, std::unique_ptr<Shader::ShaderProgram>& shader);
    void registerTexture(const std::string& name, std::unique_ptr<Texture::BasicTexture>& texture);

    /**
     * Scene Management
     */
    void addScene(const std::string& name, std::unique_ptr<Scene>& scene);
    void toScene (const std::string& name);
    void init();
    void start();
    void stop();

    /**
     * Entity Management
     */
    class Entity {
    private:
    public:
        glm::vec3 position = {0, 0, 0};
        glm::vec3 rotation = {0, 0, 0};
        //Entity(const std::string& mesh, const std::string& shader, const std::string& texture);
    };

    void draw(const Entity& entity);
}

#endif

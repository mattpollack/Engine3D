#ifndef _RENDERER_H
#define _RENDERER_H

#include "Object/Object.h"
#include "Texture/Texture.h"
#include "Shader/ShaderProgram.h"
#include "Scene.h"

#include <map>
#include <string>
#include <memory>

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
    void addScene(const std::string& title, std::unique_ptr<Scene>& scene);
    void toScene(const std::string& title);
    void init();
    void start();
    void stop();

    /**
     * Entity Management
     */
}

#endif

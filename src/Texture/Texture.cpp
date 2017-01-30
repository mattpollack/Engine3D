#include "Texture.h"
#include <SFML/Graphics/Image.hpp>

namespace Texture {
    void BasicTexture::load(const std::string& filename) {
        std::string filepath = "data/textures/" + filename + ".png";
        sf::Image image;
        image.loadFromFile(filepath);

        glGenTextures(1, &m_textureId);
        glBindTexture(GL_TEXTURE_2D, m_textureId);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            image.getSize().x,
            image.getSize().y,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            image.getPixelsPtr()
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void BasicTexture::bind() {
        glBindTexture(GL_TEXTURE_2D, m_textureId);
    }

    void BasicTexture::unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

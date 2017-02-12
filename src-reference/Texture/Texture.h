#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <GL/glew.h>
#include <string>

namespace Texture {
    class BasicTexture {
    private:
        GLuint m_textureId;
    public:
        void load(const std::string& filename);
        void bind();
        void unbind();
    };
}

#endif

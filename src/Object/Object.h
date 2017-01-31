#ifndef _OBJECT_H
#define _OBJECT_H

#include <vector>
#include <GL/glew.h>

/**
 * Currently meshes support triangulated export, no materials, no textures, no
 * NURBS.
 */

/**
 * REMEMBER TO DESTROY properly
     Model::~Model() {
         glDeleteVertexArrays(1, &m_vao);
         glDeleteBuffers(m_buffers.size(), m_buffers.data());
     }
 */
namespace Object {
    class Mesh {
    private:
        std::vector<GLuint>  m_buffers;

        GLuint m_vao = 0;
        GLuint m_vboCount = 0;
        GLuint m_indicesCount = 0;

        void addVBO(int dim, const std::vector<GLfloat>& data);
        void addEBO(const std::vector<GLuint>& indices);
    public:
        std::vector<GLfloat> m_vertices;
        std::vector<GLuint>  m_indices;
        
        void load(const std::string& filename);
        void bind();
        void unbind();
        GLuint getIndicesCount() const;
    };
}

#endif

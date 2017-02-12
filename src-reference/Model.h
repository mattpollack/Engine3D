#ifndef _MODEL_H
#define _MODEL_H

#include <GL/glew.h>
#include <vector>

class Model {
private:
    std::vector<GLuint> m_buffers;
    GLuint m_vao = 0;
    GLuint m_vboCount = 0;
    GLuint m_indicesCount = 0;

    void addVBO(int dim, const std::vector<GLfloat>& data);
    void addEBO(const std::vector<GLuint>& indices);
public:
    Model(
        const std::vector<GLfloat>& vertexPositions,
        const std::vector<GLfloat>& textureCoordinates,
        const std::vector<GLuint>&  indices
    );
    ~Model();
    void bind();
    void unbind();
    GLuint getIndicesCount() const;
};

#endif

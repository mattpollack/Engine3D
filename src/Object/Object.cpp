#include "Object.h"

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace Object {
    void Mesh::load(const std::string& filename) {
        /*std::ifstream inFile("data/objects/" + filename + ".obj");
        std::string line;

        if (!inFile.is_open()) {
            throw std::runtime_error("Could not open file " + filename);
        }

        std::string::size_type size;
        std::string numString;

        while (std::getline(inFile, line)) {
            std::istringstream iss(line);

            if (line[0] == 'v' || line[0] == 'f') {
                for (int i = 2; i < line.size(); ++i) {
                    if (line[i] != ' ') {
                        numString += line[i];
                    }

                    if (line[i] == ' ' || i == line.size() - 1) {
                        if (line[0] == 'v') m_vertices.push_back(std::stof(numString, &size));
                        else                m_indices.push_back(std::stoul(numString, &size));

                        numString = "";
                    }
                }
            }
        }*/

        m_vertices = {
            0.5,    0.5,    0.0,
            -0.5,   0.5,    0.0,
            -0.5,   -0.5,   0.0,
            0.5,    -0.5,   0.0
        };

        m_indices = {
            0, 1, 2,
            2, 3, 0
        };

        m_indicesCount = m_indices.size();

        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        addVBO(3, m_vertices);
        //addVBO(2, textureCoordinates);
        addEBO(m_indices);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Mesh::bind() {
        glBindVertexArray(m_vao);
    }

    void Mesh::unbind() {
        glBindVertexArray(0);
    }

    GLuint Mesh::getIndicesCount() const {
        return m_indicesCount;
    }

    void Mesh::addVBO(int dim, const std::vector<GLfloat>& data) {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(
            GL_ARRAY_BUFFER,
            data.size() * sizeof(data[0]),
            data.data(),
            GL_STATIC_DRAW
        );
        glVertexAttribPointer(
            m_vboCount,
            dim,
            GL_FLOAT,
            GL_FALSE,
            0,
            (GLvoid *) 0
        );
        glEnableVertexAttribArray(m_vboCount++);
        m_buffers.push_back(vbo);
    }

    void Mesh::addEBO(const std::vector<GLuint>& indices) {
        GLuint ebo;
        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            indices.size() * sizeof(indices[0]),
            indices.data(),
            GL_STATIC_DRAW
        );
        m_buffers.push_back(ebo);
    }
}

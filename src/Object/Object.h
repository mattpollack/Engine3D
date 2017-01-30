#ifndef _OBJECT_H
#define _OBJECT_H

#include <vector>
#include <GL/glew.h>

/**
 * Currently meshes support triangulated export, no materials, no textures, no
 * NURBS.
 */
namespace Object {
    typedef struct Mesh {
        std::vector<GLfloat> vertices;
        std::vector<GLuint>  indices;
        // TODO textures, materials, NURBS? (lol)
    } Mesh;

    // Currently assumes a properly formatted file
    Mesh meshLoad(const std::string& filename);
}

#endif

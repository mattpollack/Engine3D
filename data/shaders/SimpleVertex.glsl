#version 330

layout (location = 0) in vec2 inVertexPosition;
layout (location = 1) in vec2 inTextureCoordinates;

out vec2 passTextureCoordinates;

void main() {
    //gl_Position = gl_Vertex;
    gl_Position = vec4(inVertexPosition.x, inVertexPosition.y, 0.0, 1.0);

    passTextureCoordinates = inTextureCoordinates;
}

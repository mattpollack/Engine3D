#version 330

layout (location = 0) in vec3 inVertexPosition;
//layout (location = 1) in vec2 inTextureCoordinates;
//out vec2 passTextureCoordinates;

uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat4 projMatrix;

void main() {
    //gl_Position = gl_Vertex;
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(
        inVertexPosition.x,
        inVertexPosition.y,
        inVertexPosition.z,
        1.0
    );

    //passTextureCoordinates = inTextureCoordinates;
}

#version 330

in vec2 passTextureCoordinates;

uniform sampler2D ourTexture;
uniform float time;

out vec4 color;

void main() {
    color = texture(ourTexture, passTextureCoordinates) * sin(time*4);
}

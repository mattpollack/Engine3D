#version 330

in vec3 passPos;

uniform float time;

out vec4 color;

void main() {
    color = vec4(1.0, passPos.y/10, 1.0, 1.0);
}

#version 150

in vec4 position;
in vec4 color;

out vec4 Color;

void main() {
    Color = color;
    gl_Position = position;
}
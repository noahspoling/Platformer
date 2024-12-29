#version 330 core

uniform mat4 MVPMatrix;

layout(location = 0) in vec3 VertexCoord;
layout(location = 1) in vec2 TexCoord;
layout(location = 2) in vec4 COLOR;

out vec2 TEX0;
out vec4 COL0;

void main()
{
    gl_Position = MVPMatrix * vec4(VertexCoord, 1.0);
    COL0 = COLOR;
    TEX0 = TexCoord;
}
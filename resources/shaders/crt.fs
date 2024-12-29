#version 330 core

#if __VERSION__ >= 130
#define COMPAT_VARYING in
#define COMPAT_TEXTURE texture
out vec4 FragColor;
#else
#define COMPAT_VARYING varying
#define FragColor gl_FragColor
#define COMPAT_TEXTURE texture2D
#endif

#ifdef GL_ES
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#endif

uniform sampler2D Texture;

in vec2 TEX0;
in vec4 COL0;

void main()
{
    vec4 color = COMPAT_TEXTURE(Texture, TEX0);
    FragColor = color * COL0; // Pass through the texture color multiplied by the vertex color
}
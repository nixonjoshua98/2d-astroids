#version 440 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colour;

out vec3 vertexColour;

uniform float offset;

void main()
{
	gl_Position = vec4(pos.x * offset, pos.y * offset, pos.z * offset, 1.0);
	vertexColour = colour;
}
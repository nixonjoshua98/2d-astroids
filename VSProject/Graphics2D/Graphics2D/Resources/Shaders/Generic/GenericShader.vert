#version 440 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 colour;
layout (location = 2) in vec2 textureCoords;

out vec3 vertexColour;
out vec2 texCoords;

uniform mat4 uTransform;

void main()
{
	gl_Position = uTransform * vec4(pos, 1.0);
	
	// Outs
	vertexColour = colour;
	texCoords = vec2(textureCoords.x, 1 - textureCoords.y);
}
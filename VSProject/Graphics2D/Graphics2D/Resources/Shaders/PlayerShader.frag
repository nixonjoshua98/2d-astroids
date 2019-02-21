#version 440 core

in vec3 vertexColour;
in vec2 texCoords;

uniform sampler2D tex;

void main()
{
	gl_FragColor = texture(tex, texCoords);
}
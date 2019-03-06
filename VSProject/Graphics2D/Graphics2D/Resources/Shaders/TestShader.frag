#version 440 core
in vec3 Colour;				// Input the Colour values from Vertex shader
in vec2 textureCoordinate; 	// Texture coords from vertex shader

uniform sampler2D aTex;		// Uniform holding texture info from main programme

void main()
{
	gl_FragColor = texture(aTex, textureCoordinate);
}
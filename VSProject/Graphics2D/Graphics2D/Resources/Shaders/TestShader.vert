#version 440 core
layout (location=0) in vec3 Position;	// Vertex positions
layout (location=1) in vec3 vColour;	//Vertex colours
layout (location=2) in vec2 texCoord;	//Texture coordinates

out vec3 Colour; 						// Output vertex colour to fragment shader
out vec2 textureCoordinate;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main()
{
	gl_Position = uProjection*uView*uModel*vec4(Position, 1.0); // Update position of vertex after transform
	Colour = vColour; 											// Pass the vertex colour unchanged to the fragment shader
	textureCoordinate = vec2(texCoord.x, 1 - texCoord.y);
}
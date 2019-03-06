#ifndef JN_TRIANGLE_H
#define JN_TRIANGLE_H

#include "JN_Texture.h"

#include <GL/glew.h>

class JN_Triangle
{
public:
	JN_Triangle();	// Constructor
	~JN_Triangle();	// Deconstructor

	/* - - - - CONSTANTS - - - -*/
	const int VERTICES_LENGTH = 24;

	void Init(GLfloat vertices[], std::string textureFile);
	void Render();


private:
	JN_Texture texture;

	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint program;

	GLfloat vertices[24];

	void SetBuffers();

};

#endif // !JN_TRIANGLE_H

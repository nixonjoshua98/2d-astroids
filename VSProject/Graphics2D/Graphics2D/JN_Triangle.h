#ifndef JN_TRIANGLE_H
#define JN_TRIANGLE_H

#include <GL/glew.h>

class JN_Triangle
{
public:
	JN_Triangle();	// Constructor
	~JN_Triangle();	// Deconstructor

	void Init();

	void Render();


private:
	GLuint vertexArray;
	GLuint vertexBuffer;

	GLfloat vertices[9] = {
		-0.05f,  -0.05f, 0.0f, // Left
		  0.0f,    0.1f, 0.0f, // Top
		 0.05f,  -0.05f, 0.0f, // Right
	};

	void SetBuffers();

};

#endif // !JN_TRIANGLE_H

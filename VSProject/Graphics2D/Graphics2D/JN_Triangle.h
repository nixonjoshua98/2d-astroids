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
		-1.0f, -1.0f, 0.0f, 
		 0.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
	};

	void SetBuffers();

};

#endif // !JN_TRIANGLE_H

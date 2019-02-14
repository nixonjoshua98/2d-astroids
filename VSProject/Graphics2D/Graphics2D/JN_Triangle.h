#ifndef JN_TRIANGLE_H
#define JN_TRIANGLE_H

#include <GL/glew.h>

class JN_Triangle
{
public:
	JN_Triangle();	// Constructor
	~JN_Triangle();	// Deconstructor

	/* - - - - CONSTANTS - - - -*/
	const int VERTICES_LENGTH = 18;

	void Init(GLfloat vertices[]);
	void Render();


private:
	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint program;

	GLfloat vertices[18];

	void SetBuffers();

};

#endif // !JN_TRIANGLE_H

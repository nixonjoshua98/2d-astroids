#ifndef JN_TRIANGLE_H
#define JN_TRIANGLE_H

#include <GL/glew.h>

#include "TextureClass.h"


class JN_Triangle
{
public:
	JN_Triangle();
	~JN_Triangle();

	void Init(std::string texFile, std::string vertexShaderFile, std::string fragmentShaderFile);
	void Render();

	GLuint GetShaderProgram() { return shaderProgram; }

private:
	GLuint VBO, VAO;
	GLuint shaderProgram;
	Texture texture;

	GLfloat vertices[24] = {
		-0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		 0.5f,  0.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.5f,
	};

	void SetBuffers();
};

#endif // !JN_TRIANGLE_H
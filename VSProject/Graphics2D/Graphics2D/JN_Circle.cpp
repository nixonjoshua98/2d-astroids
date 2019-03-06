

#include "JN_Circle.h"
#include "JN_Shader.h"

#include <iostream>


void JN_Circle::Init(std::string texFile)
{
	float radius = 1.0f;
	float offsetX = 0.0f;
	float offsetY = 0.0f;

	// Origin of circle
	vertices[0] = 0.0f + offsetX;
	vertices[1] = 0.0f + offsetY;
	vertices[2] = 0.0f;

	// Colour of origin vertex
	vertices[3] = 0.0f + offsetX;
	vertices[4] = 0.0f + offsetY;
	vertices[5] = 0.0f;

	// Texture coordinates of centre
	vertices[6] = 0.5f;
	vertices[7] = 0.5f;

	GLfloat angle = 0.0f;

	// Set remaining vertices based on radius
	for (int i = 8; i < 240; i += 8)
	{
		vertices[i] = (radius * cos(angle)) + offsetX;
		vertices[i + 1] = (radius * sin(angle)) + offsetY;
		vertices[i + 2] = 0.0f;

		// Colour information
		for (int j = 3; j <= 5; j++)
			vertices[i + j] = 0.0f;

		// Texture coordinate information
		vertices[i + 6] = ((radius * cos(angle)) * 0.5f) + 0.5f;
		vertices[i + 7] = ((radius * sin(angle)) * 0.5f) + 0.5f;

		angle += (2 * M_PI) / 28.0f;

	}

	texture.Load(texFile);

	SetBuffers();
}




void JN_Circle::SetBuffers()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// X, Y, Z
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// R, G, B
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Tx, Ty
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}



void JN_Circle::Render(GLuint shaderProgram, const float* uProjectionVal, const float* uViewVal, const float* uModelVal)
{
	// Get uniforms
	//GLuint uTransform = glGetUniformLocation(shaderProgram, "uTransform");
	GLuint uProjection = glGetUniformLocation(shaderProgram, "uProjection");
	GLuint uModel = glGetUniformLocation(shaderProgram, "uModel");
	GLuint uView = glGetUniformLocation(shaderProgram, "uView");

	// Set uniforms
	//glUniformMatrix4fv(uTransform, 1, GL_FALSE, uTransformVal);
	//glUniformMatrix4fv(uProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uModel, 1, GL_FALSE, uModelVal);
	//glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Binds
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, texture.GetTexture());

	// Draw
	glDrawElements(GL_TRIANGLES, 87, GL_UNSIGNED_INT, 0);

	// Unbinds
	glBindVertexArray(0);
}

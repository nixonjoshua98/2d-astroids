

#include "JN_Triangle.h"
#include "JN_Logging.h"

#include <iostream>


JN_Triangle::JN_Triangle()
{

}



JN_Triangle::~JN_Triangle()
{

}


void JN_Triangle::Init(GLfloat vertices[])
{
	// Copy vertices data to the triangle vertices
	for (int i = 0; i < VERTICES_LENGTH; i++)
	{ 
		this->vertices[i] = vertices[i];
	}

	SetBuffers();
}



void JN_Triangle::Render()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}



void JN_Triangle::SetBuffers()
{
	glGenBuffers(1, &vertexBuffer);
	glGenVertexArrays(1, &vertexArray);

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// X, Y, Z
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// R, G, B
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}



#include "JN_Triangle.h"
#include "JN_Logging.h"


JN_Triangle::JN_Triangle()
{
	JN_AppendLog("Triangle created");
}



JN_Triangle::~JN_Triangle()
{

}



void JN_Triangle::Init()
{
	SetBuffers();
}



void JN_Triangle::Render()
{
	/*GLfloat x;
	x = vertices[4] >= 1.0f ? 0 : vertices[4] + 0.01;
	vertices[4] = x;

	x = vertices[0] <= -1.0f ? 0 : vertices[0] - 0.01;
	vertices[0] = x;

	x = vertices[6] >= 1.0f ? 0 : vertices[6] + 0.01;
	vertices[6] = x;
	SetBuffers();
	*/


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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

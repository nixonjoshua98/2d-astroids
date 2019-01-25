

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
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &vertexBuffer);												// Generate 1 buffer, put the resulting identifier in <vertexBuffer>
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);								// The following commands will talk about our <vertexBuffer> buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);	// Give our vertices to OpenGL.
}



void JN_Triangle::Render()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

#include "JN_Circle.h"
#include "JN_Shader.h"

#include <cmath>



JN_Circle::JN_Circle()
{
}



JN_Circle::~JN_Circle()
{

}



void JN_Circle::Init(float radius, float offsetX, float offsetY)
{
	std::string vertexShaderFile = "..//..//Assets//Shaders//shader_vColour_Projection.vert";
	std::string fragmentShaderFile = "..//..//Assets//Shaders//shader_vColour_Projection.frag";

	this->radius = radius;

	vertices[0] = 0.0f + offsetX;
	vertices[1] = 0.0f + offsetY;
	vertices[2] = 0.0f;

	vertices[3] = 0.0f;
	vertices[4] = 0.0f;
	vertices[5] = 0.1f;

	vertices[6] = 0.5f;
	vertices[7] = 0.5f;

	GLfloat angle = 0.0f;

	for (int i = 8; i < 240; i += 8)
	{
		vertices[i] = (radius * cos(angle)) + offsetX;
		vertices[i + 1] = (radius * sin(angle)) + offsetY;
		vertices[i + 2] = 0.0f;

		vertices[i + 3] = 1.0f;
		vertices[i + 4] = 1.0f;
		vertices[i + 5] = 1.0f;

		vertices[i + 6] = ((radius * cos(angle))*2.5f) + 0.5f;
		vertices[i + 7] = ((radius * sin(angle))*2.5f) + 0.5f;

		angle += (2 * M_PI) / 28.0f;

	}

	JN_Shader vShader = JN_Shader(JN_Shader::ShaderType::Vertex, vertexShaderFile);
	JN_Shader fShader = JN_Shader(JN_Shader::ShaderType::Fragment, fragmentShaderFile);

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vShader.GetShaderID());
	glAttachShader(shaderProgram, fShader.GetShaderID());
	glLinkProgram(shaderProgram);

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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void JN_Circle::Render(JN_Texture texture)
{
	glUseProgram(shaderProgram);

	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, texture.GetTexture());

	glPointSize(1.0f);

	glDrawElements(GL_TRIANGLES, 87, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

#include "JN_Triangle.h"
#include "JN_Shader.h"


JN_Triangle::JN_Triangle()
{
}


JN_Triangle::~JN_Triangle()
{
}


void JN_Triangle::Init(std::string texFile, std::string vertexShaderFile, std::string fragmentShaderFile)
{
	JN_Shader vShader = JN_Shader(JN_Shader::ShaderType::Vertex, vertexShaderFile);
	JN_Shader fShader = JN_Shader(JN_Shader::ShaderType::Fragment, fragmentShaderFile);

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vShader.GetShaderID());
	glAttachShader(shaderProgram, fShader.GetShaderID());
	glLinkProgram(shaderProgram);

	texture.Load(texFile.c_str());

	SetBuffers();
}


void JN_Triangle::Render()
{
	// Using
	glUseProgram(shaderProgram);

	// Binds
	glBindTexture(GL_TEXTURE_2D, texture.GetTexture());
	glBindVertexArray(VAO);

	// Draw
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Binds
	glBindVertexArray(0);
}


void JN_Triangle::SetBuffers()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

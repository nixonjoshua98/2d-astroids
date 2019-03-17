#include "JN_ImageDisplay.h"

#include <iostream>


JN_ImageDisplay::JN_ImageDisplay()
{

}


JN_ImageDisplay::~JN_ImageDisplay()
{

}



void JN_ImageDisplay::Init(std::string textureFiles[], int argc, glm::vec3 pos)
{
	for (int i = 0; i < argc; i++)
	{
		JN_Square x = JN_Square();
		x.Init(
			"..//..//Assets//Textures//" + textureFiles[i],
			"..//..//Assets//Shaders//shader_vColour_Projection.vert",
			"..//..//Assets//Shaders//shader_vColour_Projection.frag"
		);

		squares.push_back(x);
	}

	transform.Translate(pos);
}




void JN_ImageDisplay::SetUniforms(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	auto shaderProgram = squares[currentIndex].GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");
	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");


	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.MultiplyNoRotate()));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}


void JN_ImageDisplay::Render()
{
	squares[currentIndex].Render();
}

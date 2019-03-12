#include "JN_Background.h"


JN_Background::JN_Background()
{
}


JN_Background::~JN_Background()
{
}


void JN_Background::Init()
{
	square.Init(
		"..//..//Assets//Textures//Background.png",
		"..//..//Assets//Shaders//shader_Projection_basicLight.vert",
		"..//..//Assets//Shaders//shader_Projection_basicLight.frag"
	);

	borderSquare.Init(
		"..//..//Assets//Textures//Border.png",
		"..//..//Assets//Shaders//shader_Projection_basicLight.vert",
		"..//..//Assets//Shaders//shader_Projection_basicLight.frag"
	);

	transform.scale = glm::scale(transform.scale, glm::vec3({ 20.0f, 15.0f, 1.0f }));
	transform.translate = glm::translate(transform.translate, glm::vec3(2.0f, 1.5f, 0.0f));
}

void JN_Background::Render()
{
	square.Render();
	borderSquare.Render();
}


void JN_Background::SetUniforms(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	lightCol.z += 0.001f;

	auto shaderProgram = square.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uLightColourLoc = glGetUniformLocation(shaderProgram, "uLightColour");
	auto uAmbientIntensityLoc = glGetUniformLocation(shaderProgram, "uAmbientIntensity");
	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");
	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");

	glProgramUniform3fv(shaderProgram, uLightColourLoc, 1, glm::value_ptr(lightCol));
	glProgramUniform1f(shaderProgram, uAmbientIntensityLoc, ambientIntensity);

	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.scale));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	shaderProgram = borderSquare.GetShaderProgram();

	glUseProgram(shaderProgram);

	uLightColourLoc = glGetUniformLocation(shaderProgram, "uLightColour");
	uAmbientIntensityLoc = glGetUniformLocation(shaderProgram, "uAmbientIntensity");
	uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	uViewLoc = glGetUniformLocation(shaderProgram, "uView");
	uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");

	glProgramUniform3fv(shaderProgram, uLightColourLoc, 1, glm::value_ptr(lightCol));
	glProgramUniform1f(shaderProgram, uAmbientIntensityLoc, ambientIntensity);

	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.scale));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

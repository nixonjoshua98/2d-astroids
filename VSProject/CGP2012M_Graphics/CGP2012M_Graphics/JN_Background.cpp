#include "JN_Background.h"
#include "JN_Logging.h"

JN_Background::JN_Background()
{
	JN_AppendLog("Background created");

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

	transform.Scale(glm::vec3(20.0f, 15.0f, 1.0f));
	transform.Translate(glm::vec3(2.0f, 1.5f, 0.0f));
}



JN_Background::~JN_Background()
{
}


void JN_Background::Render()
{
	square.Render();
	borderSquare.Render();
}


void JN_Background::SetUniforms(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	auto shaderProgram = square.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uLightColourLoc = glGetUniformLocation(shaderProgram, "uLightColour");
	auto uAmbientIntensityLoc = glGetUniformLocation(shaderProgram, "uAmbientIntensity");
	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");
	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");

	glProgramUniform3fv(shaderProgram, uLightColourLoc, 1, glm::value_ptr(lightCol));
	glProgramUniform1f(shaderProgram, uAmbientIntensityLoc, ambientIntensity);

	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.MultiplyNoRotate()));
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

	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.MultiplyNoRotate()));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

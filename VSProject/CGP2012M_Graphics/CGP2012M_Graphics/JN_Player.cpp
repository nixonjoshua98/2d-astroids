#include "JN_Player.h"



JN_Player::JN_Player()
{
}


JN_Player::~JN_Player()
{
}


void JN_Player::Init()
{
	triangle.Init(
		"..//..//Assets//Textures//United_Kingdom.png",
		"..//..//Assets//Shaders//shader_vColour_Projection.vert",
		"..//..//Assets//Shaders//shader_vColour_Projection.frag"
	);

	transform.translate = glm::translate(transform.translate, glm::vec3(2.0f, 1.5f, 0.0f));
	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f, 0.2f, 0.0f));

	auto uModelLoc = glGetUniformLocation(triangle.GetShaderProgram(), "uModel");

	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.rotate * transform.scale));
}


void JN_Player::Input(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			transform.translate = glm::translate(transform.translate, glm::vec3((float)cos(transform.angle)*0.02f, (float)sin(transform.angle)*0.02f, 0.0f));
			break;

		case SDLK_a:
			transform.angle += glm::radians(10.0f);
			transform.rotate = glm::rotate(transform.rotate, glm::radians(10.0f), glm::vec3(0, 0, 1));
			break;

		case SDLK_d:
			transform.angle -= glm::radians(10.0f);
			transform.rotate = glm::rotate(transform.rotate, glm::radians(-10.0f), glm::vec3(0, 0, 1));
			break;
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			break;

		case SDLK_a:
			break;

		case SDLK_d:
			break;
		}
		break;
	}
}


void JN_Player::Update()
{

}


void JN_Player::SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	auto shaderProgram = triangle.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");
	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");

	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.rotate * transform.scale));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}


void JN_Player::Render()
{
	triangle.Render();
}
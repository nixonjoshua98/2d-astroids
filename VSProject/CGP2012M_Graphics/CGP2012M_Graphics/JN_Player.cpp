#include "JN_Player.h"
#include "JN_Logging.h"

#include <iostream>

JN_Player::JN_Player()
{
	JN_AppendLog("Player created");

	triangle.Init(
		"..//..//Assets//Textures//Arrow.png",
		"..//..//Assets//Shaders//shader_vColour_Projection.vert",
		"..//..//Assets//Shaders//shader_vColour_Projection.frag"
	);

	projectile = JN_Projectile();
	projectile.Init();

	transform.Translate(glm::vec3(2.0f, 1.5f, 0.0f));
	transform.Scale(glm::vec3(0.2f, 0.2f, 0.0f));
}


JN_Player::~JN_Player()
{
	JN_AppendLog("Player destroyed");
}


void JN_Player::Input(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			isMovingForward = true;
			break;

		case SDLK_a:
			transform.UpdateAngle(glm::radians(5.0f));
			transform.Rotate(glm::radians(5.0f), glm::vec3(0, 0, 1));
			break;

		case SDLK_d:
			transform.UpdateAngle(glm::radians(-5.0f));
			transform.Rotate(glm::radians(-5.0f), glm::vec3(0, 0, 1));
			break;

		case SDLK_SPACE:
			Fire();
			break;

		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			isMovingForward = false;
			break;

		case SDLK_a:
			break;

		case SDLK_d:
			break;
		}
		break;
	}
}


void JN_Player::Update(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	Move();
	if (isShooting && !IsDead())
		projectile.Update();

	SetUniforms(projectionMatrix, viewMatrix);
}


void JN_Player::SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	auto shaderProgram = triangle.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");
	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");

	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.Multiply()));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	projectile.SetUniforms(projectionMatrix, viewMatrix);
}


void JN_Player::Render()
{
	if (isShooting)
		projectile.Render();
	
	triangle.Render();
}


void JN_Player::Move()
{
	if (!isMovingForward) return;

	float angle = transform.GetAngle();
	
	transform.Translate(glm::vec3((float)cos(angle) * 0.017f, (float)sin(angle) * 0.017f, 0.0f));
}


void JN_Player::Fire()
{
	isShooting = true;

	projectile.SetDirection(transform);
}
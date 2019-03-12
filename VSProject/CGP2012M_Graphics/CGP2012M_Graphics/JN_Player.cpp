#include "JN_Player.h"
#include "JN_Logging.h"

#include <iostream>

JN_Player::JN_Player()
{
	JN_AppendLog("Player created");
}


JN_Player::~JN_Player()
{
	JN_AppendLog("Player destroyed");
}


void JN_Player::Init()
{
	triangle.Init(
		"..//..//Assets//Textures//Arrow.png",
		"..//..//Assets//Shaders//shader_vColour_Projection.vert",
		"..//..//Assets//Shaders//shader_vColour_Projection.frag"
	);

	projectile = JN_Projectile();
	projectile.Init();

	transform.translate = glm::translate(transform.translate, glm::vec3(2.0f, 1.5f, 0.0f)); // Centre points
	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f, 0.2f, 0.0f));
}


void JN_Player::Input(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			movingForward = true;
			break;

		case SDLK_a:
			transform.angle += glm::radians(10.0f);
			transform.rotate = glm::rotate(transform.rotate, glm::radians(10.0f), glm::vec3(0, 0, 1));
			break;

		case SDLK_d:
			transform.angle -= glm::radians(10.0f);
			transform.rotate = glm::rotate(transform.rotate, glm::radians(-10.0f), glm::vec3(0, 0, 1));
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
			movingForward = false;
			break;

		case SDLK_a:
			break;

		case SDLK_d:
			break;
		}
		break;
	}
}


void JN_Player::Update(std::vector<JN_Bubble*> bubbles)
{

	if (movingForward)
		transform.translate = glm::translate(transform.translate, glm::vec3((float)cos(transform.angle) * 0.0003f, (float)sin(transform.angle) * 0.0003f, 0.0f));

	if (bubbles.size() > 0)
	{
		if (abs(transform.GetMagnitude() - bubbles[0]->transform.GetMagnitude()) <= 0.01f)
		{
			//std::cout << "Player Mag: " << transform.GetMagnitude() << " Bubble Mag: " << bubbles[0]->transform.GetMagnitude() << std::endl;
		}
	}

	if (projectileInPlay)
		projectile.Update();
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

	if (projectileInPlay)
		projectile.SetUniforms(projectionMatrix, viewMatrix);
}


void JN_Player::Render()
{
	if (projectileInPlay)
		projectile.Render();
	
	triangle.Render();
}


void JN_Player::Fire()
{
	if (!canShoot) return;

	projectileInPlay = true;
	//canShoot = false;

	projectile.SetDirection(transform);
}
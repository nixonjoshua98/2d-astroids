

#include "JN_Player.h"
#include "JN_Logging.h"

#include <SDL.h>
#include <iostream>



JN_Player::JN_Player()
{
	JN_AppendLog("Player created");

	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f * 0.75f, 0.2f, 1.0f));
}




JN_Player::~JN_Player()
{
	JN_AppendLog("Player destroyed");
}



void JN_Player::Init()
{
	circle.Init("CarbonFibre.jpg");
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
			rotDir = RotationDirection::LEFT;
			break;

		case SDLK_d:
			rotDir = RotationDirection::RIGHT;
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
			rotDir = (rotDir == RotationDirection::LEFT) ? RotationDirection::NONE : rotDir;
			break;

		case SDLK_d:
			rotDir = (rotDir == RotationDirection::RIGHT) ? RotationDirection::NONE : rotDir;
			break;
		}
		break;
	}
}



void JN_Player::Update()
{
	
	if (rotDir == RotationDirection::LEFT)
	{
		transform.angle += glm::radians(3.0f);
		transform.rotate = glm::rotate(transform.rotate, glm::radians(3.0f), glm::vec3(0, 0, 1));
	}


	if (rotDir == RotationDirection::RIGHT)
	{
		transform.angle -= glm::radians(3.0f);
		transform.rotate = glm::rotate(transform.rotate, glm::radians(-3.0f), glm::vec3(0, 0, 1));
	}


	if (movingForward)
	{
		transform.Translate(glm::vec3((float)cos(transform.angle) * 0.01f, (float)sin(transform.angle) * 0.01f, 0.0f));
	}
}


void JN_Player::Render()
{
	circle.Render(glm::value_ptr(transform.Multiply()));
}

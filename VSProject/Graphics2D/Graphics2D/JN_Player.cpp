

#include "JN_Player.h"
#include "JN_Logging.h"
#include "JN_Shader.h"

#include <SDL.h>
#include <iostream>



JN_Player::JN_Player()
{
	JN_AppendLog("Player created");

	transform.Scale(0.05f * 0.75f, 0.05f, 1.0f);
}




JN_Player::~JN_Player()
{
	JN_AppendLog("Player destroyed");
}



void JN_Player::Init()
{
	sprite.Init("Shuriken.png");

	LoadShaders();
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
		transform.SetAngle(transform.GetAngle() + glm::radians(3.0f));
	}


	if (rotDir == RotationDirection::RIGHT)
	{
		transform.SetAngle(transform.GetAngle() - glm::radians(3.0f));
	}


	if (movingForward)
	{
		transform.Translate(glm::vec3((float)cos(transform.GetAngle()) * 0.01f, (float)sin(transform.GetAngle()) * 0.01f, 0.0f));
	}

	transform.Rotate(3.0f);
}


void JN_Player::Render()
{
	//sprite.Render(shaderProgram, glm::value_ptr(transform.Multiply()));
}


void JN_Player::LoadShaders()
{
	shaderProgram = glCreateProgram();

	JN_Shader frag = JN_Shader(JN_Shader::ShaderType::Fragment, "Shader.frag");
	JN_Shader vert = JN_Shader(JN_Shader::ShaderType::Vertex, "Shader.vert");

	glAttachShader(shaderProgram, frag.GetShaderID());
	glAttachShader(shaderProgram, vert.GetShaderID());

	glLinkProgram(shaderProgram);
}



#include "JN_Player.h"
#include "JN_Logging.h"
#include "JN_Shader.h"

#include <SDL.h>
#include <iostream>



JN_Player::JN_Player()
{
	JN_AppendLog("Player created");

	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f, 0.2f, 1.0f));
}




JN_Player::~JN_Player()
{
	JN_AppendLog("Player destroyed");
}



void JN_Player::Init()
{
	program = glCreateProgram();

	Shader frag = Shader(Shader::ShaderType::Fragment, "PlayerShader.frag");
	Shader vert = Shader(Shader::ShaderType::Vertex, "PlayerShader.vert");

	glAttachShader(program, frag.GetShaderID());
	glAttachShader(program, vert.GetShaderID());

	glLinkProgram(program);

	tri.Init(vertices, "CarbonFibre.jpg");
}


void JN_Player::Input(SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			std::cout << "[W] down\n";
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

		}

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			std::cout << "[W] up\n";
			movingForward = false;
			break;
		}
	}
}



void JN_Player::Update()
{
	if (movingForward)
	{
		transform.translate = glm::translate(transform.translate, glm::vec3((float)cos(transform.angle) * 0.01f, (float)sin(transform.angle) * 0.01f, 0.0f));
	}

	GLuint t = glGetUniformLocation(program, "uTransform");
	glUniformMatrix4fv(t, 1, GL_FALSE, glm::value_ptr(transform.Multiply()));
}


void JN_Player::Render()
{
	glUseProgram(program);

	tri.Render();
}

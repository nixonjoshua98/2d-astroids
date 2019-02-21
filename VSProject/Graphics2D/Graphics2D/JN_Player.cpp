

#include "JN_Player.h"
#include "JN_Logging.h"
#include "JN_Shader.h"

#include <SDL.h>
#include <iostream>



JN_Player::JN_Player()
{
	JN_AppendLog("Player created");

	scale = glm::scale(scale, glm::vec3(0.2f, 0.2f, 1.0f));
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
			translate = glm::translate(translate, glm::vec3((float)cos(angle) * 0.01f, (float)sin(angle) * 0.01f, 0.0f));
			break;
		}

		break;

	default:
		break;
	}
}



void JN_Player::Update()
{
	GLuint transform = glGetUniformLocation(program, "uTransform");
	glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(translate * rotate * scale));
}


void JN_Player::Render()
{
	glUseProgram(program);

	tri.Render();
}

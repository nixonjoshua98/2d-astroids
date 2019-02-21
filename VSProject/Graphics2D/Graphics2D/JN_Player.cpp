

#include "JN_Player.h"
#include "JN_Logging.h"
#include "JN_Shader.h"

#include <SDL.h>
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
	program = glCreateProgram();

	Shader frag = Shader(Shader::ShaderType::Fragment, "PlayerShader.frag");
	Shader vert = Shader(Shader::ShaderType::Vertex, "PlayerShader.vert");

	glAttachShader(program, frag.GetShaderID());
	glAttachShader(program, vert.GetShaderID());

	glLinkProgram(program);

	tri.Init(vertices, "UnitedKingdom.png");
}


void JN_Player::Update()
{
	GLuint offsetVar = glGetUniformLocation(program, "offset");

	glProgramUniform1f(program, offsetVar, 4.0f);
}


void JN_Player::Render()
{
	glUseProgram(program);

	tri.Render();
}

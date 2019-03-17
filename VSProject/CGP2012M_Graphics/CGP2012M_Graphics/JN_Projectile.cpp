#include "JN_Projectile.h"

#include <iostream>


JN_Projectile::JN_Projectile()
{
}


JN_Projectile::~JN_Projectile()
{
}

void JN_Projectile::Init()
{
	triangle.Init(
		"..//..//Assets//Textures//Projectile.png",
		"..//..//Assets//Shaders//shader_vColour_Projection.vert",
		"..//..//Assets//Shaders//shader_vColour_Projection.frag"
	);

	transform.Translate(glm::vec3(2.0f, 1.5f, 0.0f));
	transform.Scale(glm::vec3(0.1f, 0.1f, 0.0f));
}



void JN_Projectile::Update()
{
	transform.MoveForward2D(0.05f);
}



void JN_Projectile::SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	auto shaderProgram = triangle.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto uProjectionLoc = glGetUniformLocation(shaderProgram, "uProjection");
	auto uModelLoc = glGetUniformLocation(shaderProgram, "uModel");
	auto uViewLoc = glGetUniformLocation(shaderProgram, "uView");

	glUniformMatrix4fv(uProjectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uModelLoc, 1, GL_FALSE, glm::value_ptr(transform.Multiply()));
	glUniformMatrix4fv(uViewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}


void JN_Projectile::SetDirection(JN_Transform trans)
{
	transform.angle = trans.angle;
	transform.translate = trans.translate;
	transform.rotate = trans.rotate;
}


void JN_Projectile::Render()
{
	triangle.Render();
}
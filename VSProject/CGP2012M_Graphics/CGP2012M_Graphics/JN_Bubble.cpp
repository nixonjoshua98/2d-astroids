#include "JN_Bubble.h"

#include <iostream>



JN_Bubble::JN_Bubble()
{
}


JN_Bubble::~JN_Bubble()
{
}


void JN_Bubble::Init(float radius, float offsetX, float offsetY, JN_ScreenBoundaries boundaries)
{
	this->offset = glm::vec2(offsetX, offsetY);
	this->speed = -0.001f;
	this->boundaries = boundaries;

	circle.Init(radius, offsetX, offsetY);

	float angle = glm::radians((float)(rand() % 360));

	transform.SetDirection((float)cos(angle), (float)sin(angle), 0.0f);

	transform.translate = glm::translate(transform.translate, glm::vec3(boundaries.cX, boundaries.cY, 0.0f));
	transform.scale = glm::scale(transform.scale, glm::vec3(1, 1, 0));
}


void JN_Bubble::Render()
{
	circle.Render();
}


void JN_Bubble::Update()
{
	auto pos = transform.GetPosition();

	bool hitRight = pos.x > (5.1f - 0.35f);
	bool hitLeft = pos.x < (boundaries.l + (circle.radius) + 0.35f);
	bool hitTop = pos.y > (boundaries.t - (circle.radius) - 0.25f);
	bool hitBottom = pos.y < (boundaries.b + (circle.radius) + 0.25f);


	if (hitLeft)
		transform.direction.x *= -1.0f;

	else if (hitRight)
		transform.direction.x *= -1.0f;

	else if (hitTop)
		transform.direction.y *= -1.0f;

	else if (hitBottom)
		transform.direction.y *= -1.0f;


	transform.translate = glm::translate(transform.translate, transform.direction * 0.001f);
}


void JN_Bubble::SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	auto shaderProgram = circle.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto projectionLocation = glGetUniformLocation(shaderProgram, "uProjection");
	auto modelLocation = glGetUniformLocation(shaderProgram, "uModel");
	auto viewLocation = glGetUniformLocation(shaderProgram, "uView");

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.rotate * transform.scale));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

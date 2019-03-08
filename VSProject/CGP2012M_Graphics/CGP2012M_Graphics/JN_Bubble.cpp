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
	this->speed = -0.001f;
	this->boundaries = boundaries;
	this->vector.x = boundaries.cX;
	this->vector.y = boundaries.cY;

	circle.Init(radius, offsetX, offsetY);

	transform.translate = glm::translate(transform.translate, glm::vec3(boundaries.cX, boundaries.cY, 0.0f));
	transform.scale = glm::scale(transform.scale, glm::vec3(2.0f, 2.0f, 0.0f));
}


void JN_Bubble::Render()
{
	circle.Render();
}


void JN_Bubble::Update()
{
	bool hitRight = vector.x > (boundaries.r - (circle.radius * 2)) & (speed > 0);
	bool hitLeft = vector.x < (boundaries.l + (circle.radius * 2)) & (speed < 0);

	if (hitRight || hitLeft)
		speed *= -1.0f;

	transform.translate = glm::translate(transform.translate, glm::vec3(speed, 0.0f, 0.0f));
	transform.rotate += glm::radians(1.0f);
	vector.x += speed;
}


void JN_Bubble::SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	auto shaderProgram = circle.GetShaderProgram();

	glUseProgram(shaderProgram);

	auto projectionLocation = glGetUniformLocation(shaderProgram, "uProjection");
	auto modelLocation = glGetUniformLocation(shaderProgram, "uModel");
	auto viewLocation = glGetUniformLocation(shaderProgram, "uView");

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(transform.translate * transform.scale));
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

#include "JN_Bubble.h"
#include "JN_Logging.h"

#include <iostream>


void JN_Bubble::Init()
{
	this->sprite.Init("Bubble.png");

	float angle = glm::radians((float)(rand() % 360));

	transform.SetDirection((float)cos(angle), (float)sin(angle), 0.0f);
	transform.Scale(0.2f * 0.75f, 0.2f, 1.0f);
	transform.Rotate(angle);
}



void JN_Bubble::Update()
{
	glm::vec3 pos = transform.GetPosition();

	// LEFT, RIGHT
	if (pos.x < -1.14f || pos.x > 1.14f)
	{
		transform.FlipDirectionX();
	}

	// UP, DOWN
	if (pos.y <= (-0.8f) || pos.y >= 0.8f)
	{
		transform.FlipDirectionY();
	}

	transform.Rotate(1.0f);

	transform.Translate(transform.GetDirection() * 0.005f);
}



void JN_Bubble::Render(GLuint shaderProgram)
{
	const float* uTransformVal = glm::value_ptr(transform.Multiply());

	sprite.Render(shaderProgram, uTransformVal);
}
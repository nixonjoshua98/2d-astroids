#include "JN_Bubble.h"
#include "JN_Logging.h"



void JN_Bubble::Init()
{
	this->sprite.Init("CirclePattern.png");

	float angle = glm::radians((float)(rand() % 360));

	transform.SetDirection((float)cos(angle), (float)sin(angle), 0.0f);
	transform.Scale(0.05f * 0.75f, 0.05f, 1.0f);
	transform.Rotate(angle);
}



void JN_Bubble::Update()
{
	glm::vec3 pos = transform.GetPosition();

	// LEFT, RIGHT
	if (pos.x < -1.2f || pos.x > 1.2f)
		transform.FlipDirectionX();

	// UP, DOWN
	if (pos.y <= (-0.8f) || pos.y >= 0.8f)
		transform.FlipDirectionY();

	transform.Rotate(1.0f);

	transform.Translate(transform.GetDirection() * 0.01f);
}



void JN_Bubble::Render(GLuint shaderProgram, const float* uViewVal, const float* uProjectionVal)
{
	const float* uModelVal = glm::value_ptr(transform.Multiply());

	sprite.Render(shaderProgram, uModelVal, uViewVal, uProjectionVal);
}
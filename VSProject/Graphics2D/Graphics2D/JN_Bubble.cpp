#include "JN_Bubble.h"
#include "JN_Logging.h"

#include <iostream>


JN_Bubble::~JN_Bubble()
{
	JN_AppendLog("Bubble destroyed");
}



JN_Bubble::JN_Bubble()
{
	JN_AppendLog("Bubble created");
}



void JN_Bubble::Init()
{

	circle.Init("CirclePattern.png");

	float angle = 90.0f;//glm::radians((float)(rand() % 360));

	transform.angle = 0.0F;
	transform.direction = glm::vec3((float)cos(angle), (float)sin(angle), 0.0f);
	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f * 0.75f, 0.2f, 1.0f));
	transform.rotate = glm::rotate(transform.rotate, glm::radians(angle), glm::vec3(0, 0, 1));
}




void JN_Bubble::Update(float aspectRatio)
{
	glm::vec3 pos = transform.Position();

	std::cout << aspectRatio << ", " << pos.x << std::endl;

	// X
	if (pos.x < -1.2f || pos.x > 1.2f)
	{
		transform.direction.x = -transform.direction.x;
	}

	// Y
	if (pos.y >= 0.8f || pos.y <= (-0.8f))
	{
		transform.direction.y = -transform.direction.y;
	}

	transform.rotate = glm::rotate(transform.rotate, glm::radians(1.0f), glm::vec3(0, 0, 1));

	transform.Translate(transform.direction * 0.01f);
}




void JN_Bubble::Render()
{
	circle.Render(glm::value_ptr(transform.Multiply()));
}

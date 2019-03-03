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

	circle.Init();

	float x = glm::radians((float)(rand() % 360));

	transform.angle = 0.0F;
	transform.direction = glm::vec3((float)cos(x), (float)sin(x), 0.0f);
	transform.scale = glm::scale(transform.scale, glm::vec3(0.2f * 0.75f, 0.2f, 1.0f));
	transform.rotate = glm::rotate(transform.rotate, glm::radians(x), glm::vec3(0, 0, 1));
}




void JN_Bubble::Update()
{
	glm::vec3 pos = transform.Position();

	// X
	if (pos.x >= ((float)800 / 600) - 0.1f || pos.x <= -((float)800 / 600) + 0.1f)
	{
		transform.direction.x = -transform.direction.x;
	}

	// Y
	if (pos.y >= 1.0f - 0.1f || pos.y <= -1.0f + 0.1f)
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

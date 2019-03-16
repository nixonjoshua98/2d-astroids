#include "JN_BubbleController.h"
#include "JN_Logging.h"

#include <iostream>
#include <random>


JN_BubbleController::JN_BubbleController()
{
	JN_AppendLog("Bubble controller created");
}


JN_BubbleController::~JN_BubbleController()
{
	JN_AppendLog("Bubble controller destroyed");

	for (auto b : bubbles)
	{
		if (b)
			delete b;
	}
	bubbles.clear();
}

void JN_BubbleController::Init(JN_ScreenBoundaries boundaries, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	this->boundaries = boundaries;
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;
}


void JN_BubbleController::AddBubble(int i)
{
	JN_Bubble* b;

	float pairs[4][2] = { {-0.65, 0.5f}, {0.65f, 0.5f}, {0.65f, -0.5f}, {-0.65f, -0.5f} };
	
	int index = rand() % 4;

	for (int j = 0; j < i; j++)
	{
		b = new JN_Bubble();
		//b->Init(0.2f, pairs[index][0], pairs[index][1], boundaries);
		b->Init(0.2f, 0.0f, 0.0f, boundaries);
		bubbles.push_back(b);
	}
}


int JN_BubbleController::Update(glm::vec3 plr)
{
	int collisions = 0;

	for (int i = 0; i < bubbles.size(); )
	{
		if (bubbles[i]->transform.DistanceBetween(plr) <= 0.2f) // 0.2f = Radius
		{
			collisions++;
			bubbles.erase(bubbles.begin() + i);
			continue;
		}

		if (bubbles[i])
		{
			bubbles[i]->Update();
			bubbles[i++]->SetUniforms(projectionMatrix, viewMatrix);
		}
	}

	return collisions;
}


void JN_BubbleController::Render()
{
	for (int i = 0 ; i < bubbles.size(); )
	{
		if (bubbles[i])
		{
			bubbles[i++]->Render();
		}
	}
}

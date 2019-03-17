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

	textures["green"].Load("..//..//Assets//Textures//Circle.png");
	textures["red"].Load("..//..//Assets//Textures//RedCircle.png");
}


void JN_BubbleController::AddBubble(int i)
{
	for (int j = 0; j < i; j++)
	{
		JN_Bubble* b = new JN_Bubble();
		b->Init(0.2f, 0.0f, 0.0f, boundaries);
		bubbles.push_back(b);
	}
}


int JN_BubbleController::Update(glm::vec3 plr, glm::vec3 plrProjectile)
{
	int collisions = 0;

	for (int i = 0; i < bubbles.size();)
	{
		if (bubbles[i]->destroyTimer == 0)
		{
			bubbles.erase(bubbles.begin() + i);
			continue;
		}
		i++;
	}

	for (int i = 0; i < bubbles.size(); i++)
	{
		if ((bubbles[i]->transform.DistanceBetween(plr) <= 0.25f) && !bubbles[i]->damaged)
		{
			collisions++;
			bubbles[i]->damaged = true;
		}

		else if (bubbles[i]->transform.DistanceBetween(plrProjectile) <= 0.25f)
			bubbles[i]->damaged = true;

		bubbles[i]->Update();
		bubbles[i]->SetUniforms(projectionMatrix, viewMatrix);
	}

	return collisions;
}


void JN_BubbleController::Render()
{
	for (int i = 0 ; i < bubbles.size(); )
	{
		if (bubbles[i])
		{
			bubbles[i]->Render(bubbles[i]->damaged ? textures["red"] : textures["green"]);
			i++;
		}
	}
}

#include "JN_BubbleController.h"
#include "JN_Logging.h"



JN_BubbleController::JN_BubbleController()
{
	JN_AppendLog("BubbleController created");
}



JN_BubbleController::~JN_BubbleController()
{
	JN_AppendLog("BubbleController destroyed");

	DeleteAllBubbles();
}



void JN_BubbleController::Init(float aspectRatio)
{
	this->aspectRatio = aspectRatio;
}



void JN_BubbleController::Update()
{
	for (auto b : bubbles)
		b->Update(aspectRatio);
}



void JN_BubbleController::Render()
{
	for (auto b : bubbles)
		b->Render();
}


void JN_BubbleController::AddBubble()
{
	bubbles.push_back(new JN_Bubble());
	bubbles.back()->Init();
}


void JN_BubbleController::DeleteAllBubbles()
{
	for (auto b : bubbles)
		delete b;
	bubbles.clear();
}

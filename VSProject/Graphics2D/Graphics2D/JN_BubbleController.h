#ifndef JN_BUBBLE_CONTROLLER_H
#define JN_BUBBLE_CONTROLLER_H

#include "JN_Bubble.h"

#include <vector>

class JN_BubbleController
{
public:
	JN_BubbleController();
	~JN_BubbleController();

	void Init(float aspectRatio);
	void Update();
	void Render();
	void AddBubble();

private:
	std::vector<JN_Bubble*> bubbles;

	float aspectRatio;

	void DeleteAllBubbles();
};

#endif // !JN_BUBBLE_CONTROLLER_H

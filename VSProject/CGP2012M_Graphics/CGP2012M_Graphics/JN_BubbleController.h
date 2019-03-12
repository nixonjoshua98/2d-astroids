#ifndef JN_BUBBLE_CONTROLLER_H
#define JN_BUBBLE_CONTROLLER_H

#include <vector>
#include <memory>

#include "JN_Bubble.h"
#include "JN_ScreenBoundaries.h"

class JN_BubbleController
{
public:
	JN_BubbleController();
	~JN_BubbleController();

	void Init(JN_ScreenBoundaries boundaries, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
	void AddBubble(int i = 1);
	void Update();
	void Render();

private:
	std::vector<JN_Bubble*> bubbles;

	JN_ScreenBoundaries boundaries;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
};

#endif // !JN_BUBBLE_CONTROLLER_H
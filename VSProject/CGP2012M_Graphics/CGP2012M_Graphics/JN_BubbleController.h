#ifndef JN_BUBBLE_CONTROLLER_H
#define JN_BUBBLE_CONTROLLER_H

#include <vector>
#include <memory>

#include "JN_Bubble.h"
#include "JN_Player.h"
#include "JN_ScreenBoundaries.h"

class JN_BubbleController
{
public:
	JN_BubbleController();
	~JN_BubbleController();

	void Init(JN_ScreenBoundaries boundaries, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
	void AddBubble(int i = 1);
	int Update(glm::vec3 plr);
	void Render();

	int GetTotalBubbles() { return (int)bubbles.size(); }

	std::vector<JN_Bubble*> GetBubbles() { return bubbles; }

private:
	std::vector<JN_Bubble*> bubbles;

	JN_ScreenBoundaries boundaries;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
};

#endif // !JN_BUBBLE_CONTROLLER_H
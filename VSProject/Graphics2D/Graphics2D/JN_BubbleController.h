#ifndef JN_BUBBLE_CONTROLLER_H
#define JN_BUBBLE_CONTROLLER_H

#include "JN_Bubble.h"

#include <vector>
#include <GL/glew.h>

class JN_BubbleController
{
public:
	JN_BubbleController(glm::mat4& _projectionMatrix, glm::mat4& _viewMatrix);
	~JN_BubbleController();

	void Init();
	void Update();
	void Render();
	void AddBubble(int amount = 1);

private:
	std::vector<JN_Bubble*> bubbles;

	// GL stuff
	GLuint shaderProgram;

	glm::mat4& projectionMatrix;
	glm::mat4& viewMatrix;

	void LoadShaders();
	void DeleteAllBubbles();
};

#endif // !JN_BUBBLE_CONTROLLER_H

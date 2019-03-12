#ifndef JN_PLAYER_H
#define JN_PLAYER_H

#include "JN_Triangle.h"
#include "JN_Transform.h"

class JN_Player
{
public:
	JN_Player();
	~JN_Player();

	void Init();
	void Input(SDL_Event e);
	void Update();
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void Render();

private:
	bool movingForward = false;

	JN_Triangle triangle;
	JN_Transform transform;
};

#endif // !JN_PLAYER_H
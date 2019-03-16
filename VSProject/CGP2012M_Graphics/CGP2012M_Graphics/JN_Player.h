#ifndef JN_PLAYER_H
#define JN_PLAYER_H

#include "JN_Triangle.h"
#include "JN_Transform.h"
#include "JN_ImageDisplay.h"
#include "JN_Projectile.h"

#include <vector>
#include <SDL.h>
#include <memory>

class JN_Player
{
public:
	JN_Player();
	~JN_Player();

	int livesRemaining = 3;

	void Init();
	void Input(SDL_Event e);
	void Update();
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void Render();

	JN_Transform transform;

private:
	bool movingForward = false;
	bool projectileInPlay = false;

	std::unique_ptr<JN_ImageDisplay> deathDisplay = std::make_unique<JN_ImageDisplay>();

	JN_Triangle triangle;
	JN_Projectile projectile;

	void Fire();
};

#endif // !JN_PLAYER_H
#ifndef JN_PLAYER_H
#define JN_PLAYER_H

#include "JN_Triangle.h"
#include "JN_Transform.h"
#include "JN_Bubble.h"
#include "JN_Projectile.h"

#include <vector>

class JN_Player
{
public:
	JN_Player();
	~JN_Player();

	void Init();
	void Input(SDL_Event e);
	void Update(std::vector<JN_Bubble*> bubbles);
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void Render();

private:
	bool movingForward = false;
	bool canShoot = true;
	bool projectileInPlay = false;

	int livesRemaining = 3;

	JN_Triangle triangle;
	JN_Projectile projectile;
	JN_Transform transform;

	void Fire();
};

#endif // !JN_PLAYER_H
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

	void Input(SDL_Event e);
	void Update(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void Render();


	/* - - - - GETS - - - - */
	glm::vec3 GetPosition() { return transform.GetPosition(); }
	glm::vec3 GetProjectilePosition() { return projectile.GetPosition(); }
	bool IsDead() { return livesRemaining < 0; }
	int& GetLivesRemaining() { return livesRemaining; }

private:
	/* - - - - REFERENCES - - - - */


	/* - - - -  FLAGS - - - - */
	bool isMovingForward = false;
	bool isShooting = false;


	/* - - - - STATS - - - - */
	int livesRemaining = 3;


	/* - - - - RENDERING - - - - */
	JN_Projectile projectile;
	JN_Transform transform;
	JN_Triangle triangle;


	/* - - - - OPENGL - - - - */
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);


	/* - - - - ACTIONS - - - - */
	void Move();
	void Fire();
};

#endif // !JN_PLAYER_H
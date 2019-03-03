#ifndef JN_PLAYER_H
#define JN_PLAYER_h

#define GLM_FORCE_RADIANS

#include "JN_Circle.h"
#include "JN_Transform.h"

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class JN_Player
{
public:
	JN_Player();
	~JN_Player();

	enum class RotationDirection {NONE, LEFT, RIGHT};

	void Init();
	void Input(SDL_Event e);
	void Update();
	void Render();

private:
	JN_Transform transform;
	JN_Circle circle;

	/* - - - - DIRECTION FLAGS - - - - */
	bool movingForward = false;
	RotationDirection rotDir = RotationDirection::NONE;

	GLfloat vertices[24] = {
		//  X,		 Y,		 Z,		 R,		 G,	 	 B,		Tx,		Ty,
		-0.5f,    0.5f,   0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   1.0f,
		-0.5f,   -0.5f,   0.0f,   1.0f,   1.0f,   0.0f,   0.0f,   0.0f,
		 0.5f,    0.0f,   0.0f,   1.0f,   0.0f,   0.0f,   1.0f,   0.5f,
	};
};


#endif // !JN_PLAYER_H

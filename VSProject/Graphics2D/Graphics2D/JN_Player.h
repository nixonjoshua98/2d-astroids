#ifndef JN_PLAYER_H
#define JN_PLAYER_h

#include "JN_Gameobject.h"


class JN_Player : public JN_Gameobject
{
public:
	JN_Player();
	~JN_Player();

	enum class RotationDirection {NONE, LEFT, RIGHT};

	void Init() override;
	void Input(SDL_Event e);
	void Update() override;
	void Render();

	void LoadShaders();

private:
	/* - - - - DIRECTION FLAGS - - - - */
	bool movingForward = false;
	RotationDirection rotDir = RotationDirection::NONE;

	/* - - - - GL STUFF - - - -*/
	GLuint shaderProgram;

	GLfloat vertices[24] = {
		//  X,		 Y,		 Z,		 R,		 G,	 	 B,		Tx,		Ty,
		-0.5f,    0.5f,   0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   1.0f,
		-0.5f,   -0.5f,   0.0f,   1.0f,   1.0f,   0.0f,   0.0f,   0.0f,
		 0.5f,    0.0f,   0.0f,   1.0f,   0.0f,   0.0f,   1.0f,   0.5f,
	};
};


#endif // !JN_PLAYER_H

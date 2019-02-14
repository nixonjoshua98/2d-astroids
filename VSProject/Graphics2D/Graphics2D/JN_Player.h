#ifndef JN_PLAYER_H
#define JN_PLAYER_h

#include "JN_Triangle.h"

#include <GL/glew.h>

class JN_Player
{
public:
	JN_Player();
	~JN_Player();

	void Init();
	void Render();

private:
	JN_Triangle tri;

	GLuint program;			// Stores the shaders

	GLfloat vertices[18] = {
		//  X,		Y,		Z,		R,		G,		B,
	   -0.05f, -0.05f,	 0.0f,   1.0f,   0.0f,   0.0f,
		0.05f, -0.05f,   0.0f,	 0.0f,   1.0f,   0.0f,
		 0.0f,  0.10f,   0.0f,   0.0f,   0.0f,   1.0f,
	};
};


#endif // !JN_PLAYER_H

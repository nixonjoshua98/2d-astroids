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
	void Update();
	void Render();

private:
	JN_Triangle tri;

	GLuint program;			// Stores the shaders etc.

	GLfloat vertices[24] = {
		//  X,		 Y,		 Z,		 R,		 G,	 	 B,		Tx,		Ty,
		 0.0f,	  0.05f,   0.0f,  1.0f,   0.0f,   0.0f,	  1.0f,	  0.5f,
	   0.025f,  -0.025f,   0.0f,  0.0f,   0.0f,   1.0f,	  0.5f,   0.0f,
	  -0.025f,  -0.025f,   0.0f,  0.0f,   1.0f,   0.0f,   0.7f,   0.5f,
	};
};


#endif // !JN_PLAYER_H

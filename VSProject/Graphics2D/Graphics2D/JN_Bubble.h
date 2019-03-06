#ifndef JN_BUBBLE_H
#define JN_BUBBLE_H

#include "JN_Gameobject.h"

class JN_Bubble : public JN_Gameobject
{
public:
	void Init() override;
	void Update() override;
	void Render(GLuint shaderProgram, const float* uViewVal, const float* uModelVal);
};


#endif // !JN_BUBBLE_H

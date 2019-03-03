#ifndef JN_BUBBLE_H
#define JN_BUBBLE_H

#define GLM_FORCE_RADIANS

#include "JN_Circle.h"
#include "JN_Transform.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class JN_Bubble
{
public:
	JN_Bubble();
	~JN_Bubble();

	void Init();
	void Update();
	void Render();

private:
	JN_Transform transform;
	JN_Circle circle;
};

#endif // !JN_BUBBLE_H
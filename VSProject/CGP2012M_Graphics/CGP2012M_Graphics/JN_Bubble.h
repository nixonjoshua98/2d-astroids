#ifndef JN_BUBBLE_H
#define JN_BUBBLE_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "JN_Circle.h"
#include "JN_ScreenBoundaries.h"
#include "JN_Transform.h"

class JN_Bubble
{
public:
	JN_Bubble();
	~JN_Bubble();

	void Init(float radius, float offsetX, float offsetY, JN_ScreenBoundaries boundaries);
	void Render();
	void Update();
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

	JN_Transform transform;

private:
	glm::vec2 offset;

	float speed;

	JN_ScreenBoundaries boundaries;
	JN_Circle circle;
	//JN_Transform transform;
};

#endif // !JN_BUBBLE_H
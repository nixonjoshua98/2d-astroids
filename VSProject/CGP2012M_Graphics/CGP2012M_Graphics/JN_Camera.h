#ifndef JN_CAMERA_H
#define JN_CAMERA_H

#define GLM_FORCE_RADIANS


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "JN_ScreenBoundaries.h"


class JN_Camera
{
public:
	JN_Camera();
	~JN_Camera();

	void Init(float aspectRatio, JN_ScreenBoundaries boundaries);

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	float aspectRatio;

	JN_ScreenBoundaries boundaries;
};

#endif // !JN_CAMERA_H
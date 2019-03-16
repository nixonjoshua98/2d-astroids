#ifndef JN_TRANSFORM_H
#define JN_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>

struct JN_Transform
{
public:
	float angle = 0.0f;

	glm::vec3 direction;

	glm::mat4 translate = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	/* GETS */
	glm::vec3 GetDirection() { return direction; }
	glm::vec3 GetPosition() { return glm::vec3(translate[3][0] * ((float)800 / 600), translate[3][1], translate[3][2]); }

	float GetMagnitude()
	{
		auto pos = GetPosition();

		return sqrtf((float)pow(pos.x, 2) + (float)pow(pos.y, 2));
	}

	float DistanceBetween(glm::vec3 collider)
	{
		auto pos = GetPosition();

		return sqrtf(pow(pos.x - collider.x, 2) + pow(pos.y - collider.y, 2));
	}

	/* SETS */
	void SetDirection(float x, float y, float z) { direction = glm::vec3(x, y, z); }

};

#endif // !JN_TRANSFORM_HW

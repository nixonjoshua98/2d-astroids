#ifndef JN_TRANSFORM_H
#define JN_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct JN_Transform
{
public:
	float angle = 0.0f;

	glm::vec3 direction;

	glm::mat4 translate = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);
};

#endif // !JN_TRANSFORM_H

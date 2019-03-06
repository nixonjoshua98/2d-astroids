#include "JN_Transform.h"


glm::mat4 JN_Transform::Multiply()
{
	return translate * scale * rotate;
}


// Switches to radians
void JN_Transform::Rotate(float angle)
{
	rotate = glm::rotate(rotate, glm::radians(angle), glm::vec3(0, 0, 1));
}


void JN_Transform::Scale(float x, float y, float z)
{
	scale = glm::scale(scale, glm::vec3(x, y, z));
}


void JN_Transform::Translate(glm::vec3 vec)
{
	vec.x *= 0.75f;

	translate = glm::translate(translate, vec);
}
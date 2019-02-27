#include "JN_Transform.h"

glm::mat4 JN_Transform::Multiply()
{
	return translate * rotate * scale;
}
#include "JN_Transform.h"

#include <algorithm>


glm::mat4 JN_Transform::Multiply()
{
	return translate * scale * rotate;
}



glm::vec3 JN_Transform::Position()
{
	return glm::vec3(translate[3][0] * ((float)800 / 600), translate[3][1], translate[3][2]);
}



void JN_Transform::Translate(glm::vec3 vec)
{
	vec.x *= 0.75f;

	translate = glm::translate(translate, vec);
}



// Magic stuff happening here (Don't use anymore)
float JN_Transform::Direction2Angle(glm::vec2 from, glm::vec2 to)
{
	float fromMag = (float)pow(from.x, 2) + (float)pow(from.y, 2);
	float toMag = (float)pow(to.x, 2) + (float)pow(to.y, 2);

	float denom = std::sqrt(fromMag * toMag);

	float dot = (from.x * to.x) + (from.y * to.y);
	float dot2 = std::max(-1.0f, std::min(dot / denom, 1.0f));

	return glm::degrees(std::acos(dot2));
}
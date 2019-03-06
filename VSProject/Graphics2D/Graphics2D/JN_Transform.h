#ifndef JN_TRANSFORM_H
#define JN_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct JN_Transform
{
public:
	glm::mat4 Multiply();
	
	///<summary>NOTE: Switchs to radians</summary>
	void Rotate(float angle);

	void Scale(float x, float y, float z);

	///<summary>NOTE: Multiplies .x by 0.75</summary>
	void Translate(glm::vec3 vec);


	/* - - - - FLIPS - - - -*/
	void FlipDirectionX() { direction.x = (-direction.x); }
	void FlipDirectionY() { direction.y = (-direction.y); }


	/* - - - - GETS - - - -*/
	glm::vec3 GetDirection() { return direction; }
	float GetAngle() { return angle; }
	glm::vec3 GetPosition() { return glm::vec3(translate[3][0] * ((float)800 / 600), translate[3][1], translate[3][2]); }


	/* - - - - SETS - - - -*/
	void SetAngle(float x) { angle = x; }
	void SetDirection(float x, float y, float z) { direction = glm::vec3(x, y, z); }


private:
	float angle = 0.0f;

	glm::vec3 direction;

	glm::mat4 translate = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);
};

#endif // !JN_TRANSFORM_H

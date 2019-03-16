#ifndef JN_IMAGE_DISPLAY_H
#define JN_IMAGE_DISPLAY_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "JN_Square.h"
#include "JN_Transform.h"

class JN_ImageDisplay
{
public:
	JN_ImageDisplay();
	~JN_ImageDisplay();

	int currentIndex = 0;

	void Init(std::string textureFiles[], int argc, glm::vec3 pos);
	void SetUniforms(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
	void Render();

private:
	JN_Transform transform;

	std::vector<JN_Square> squares;
};


#endif // !JN_IMAGE_DISPLAY_H
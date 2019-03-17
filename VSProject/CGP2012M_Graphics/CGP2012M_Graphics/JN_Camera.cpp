#include "JN_Camera.h"
#include "JN_Logging.h"



JN_Camera::JN_Camera()
{
	JN_AppendLog("Camera created");
}


JN_Camera::~JN_Camera()
{
}

void JN_Camera::Init(float aspectRatio, JN_ScreenBoundaries boundaries)
{
	// Defines
	this->boundaries = boundaries;
	this->aspectRatio = aspectRatio;
	this->projectionMatrix = glm::ortho(0.0f, 4.0f, 0.0f, 3.0f, -1.0f, 100.0f);
	this->viewMatrix = glm::mat4(1.0f);
}

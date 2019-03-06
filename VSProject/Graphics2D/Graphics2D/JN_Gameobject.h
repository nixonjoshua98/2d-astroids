#ifndef JN_GAMEOBJECT_H
#define JN_GAMEOBJECT_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "JN_Transform.h"
#include "JN_Circle.h"

class JN_Gameobject
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	//virtual void Render() = 0;

protected:
	JN_Transform transform;
	JN_Circle sprite;
};

#endif // !JN_GAMEOBJECT_H

#ifndef JN_PROJECTILE_H
#define JN_PROJECTILe

#include "JN_Triangle.h"
#include "JN_Transform.h"

class JN_Projectile
{
public:
	JN_Projectile();
	~JN_Projectile();

	void Init();
	void Update();
	void SetUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);
	void SetDirection(JN_Transform trans);
	void Render();

private:
	JN_Triangle triangle;
	JN_Transform transform;
};

#endif // !JN_PROJECTILE_H
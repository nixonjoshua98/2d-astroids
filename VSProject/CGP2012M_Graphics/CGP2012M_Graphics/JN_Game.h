#ifndef JN_GAME
#define JN_GAME

#define GLM_FORCE_RADIANS

#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "JN_Application.h"
#include "JN_Player.h"
#include "JN_Bubble.h"
#include "JN_Background.h"

class JN_Game
{
public:
	JN_Game();
	~JN_Game();

	bool Init(std::shared_ptr<JN_Application> app);
	void Run();

private:
	bool gameRunning = true;

	glm::mat4 viewMatrix = glm::mat4(1.0f);
	glm::mat4 projectionMatrix = glm::ortho(0.0f, 4.0f, 0.0f, 3.0f, -1.0f, 100.0f);

	std::shared_ptr<JN_Application> app;
	std::unique_ptr<JN_Player> player;
	std::unique_ptr<JN_Background> background;

	JN_Bubble* bubble;

	void Input();
	void Update();
	void Render();
};

#endif // !JN_GAME
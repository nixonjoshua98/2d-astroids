#ifndef JN_GAME
#define JN_GAME

#define GLM_FORCE_RADIANS

#include <memory>
#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "JN_Application.h"
#include "JN_Player.h"
#include "JN_BubbleController.h"
#include "JN_ImageDisplay.h"
#include "JN_Camera.h"
#include "JN_Background.h"

class JN_Game
{
public:
	JN_Game();
	~JN_Game();

	bool Init(std::shared_ptr<JN_Application> app);
	void Run();

	unsigned long int spawnTimer = 0;

private:
	/* - - - - FILES - - - - */
	std::string numbers[4] = { "Zero.png", "One.png", "Two.png", "Three.png" };
	std::string gameoverImage[1] = { "Gameover.png" };


	/* - - - - FLAGS - - - - */
	bool gameRunning = true;


	// Smarts
	std::shared_ptr<JN_Application> app;
	std::unique_ptr<JN_Camera> camera;
	std::unique_ptr<JN_Player> player;
	std::unique_ptr<JN_BubbleController> bubbles;
	std::unique_ptr<JN_Background> background;
	std::unique_ptr<JN_ImageDisplay> playerHealthDisplay;
	std::unique_ptr<JN_ImageDisplay> gameoverDisplay;


	void Input();
	void Update();
	void Render();
};

#endif // !JN_GAME
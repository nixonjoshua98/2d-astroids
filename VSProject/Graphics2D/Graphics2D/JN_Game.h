#ifndef JN_GAME_H
#define JN_GAME_H

#include "JN_Application.h"
#include "JN_BubbleController.h"
#include "JN_Player.h"
#include "JN_Bubble.h"

#include <memory>
#include <vector>

class JN_Game
{
public:
	JN_Game();	// Constructor
	~JN_Game();	// Deconstructor

	/* - - - -  CONSTANTS - - - - */
	const int FRAMES_PER_SECOND = 60;


	bool Init(std::shared_ptr<JN_Application> app);	// Init objects etc.
	void Run();										// Game loop

private:
	int currentFps = 0;				// Stores the current FPS, got from the framelock
	bool gameRunning = true;		// Bool flag to run the game loop

	// GL stuff
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;


	/* - - - -  POINTERS - - - - */
	std::unique_ptr<JN_BubbleController> bubbles = NULL;	// Bubble manager
	std::shared_ptr<JN_Application> app = NULL;	// Application, stores the window, renderer etc.
	std::shared_ptr<JN_Player> player = NULL;	// Player object

	void Input();	// Input check
	void Update();	// Update each object
	void Render();	// Render objects and flip buffer
};

#endif // !JN_GAME_H

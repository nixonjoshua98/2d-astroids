#ifndef JN_GAME_H
#define JN_GAME_H

#include "JN_Application.h"
#include "JN_Triangle.h"
#include "JN_Shader.h"

#include <memory>

class JN_Game
{
public:
	JN_Game();	// Constructor
	~JN_Game();	// Deconstructor

	bool Init(std::shared_ptr<JN_Application> app);	// Init objects etc.
	void Run();										// Game loop

	/* - - - -  CONSTANTS - - - - */
	const int FRAMES_PER_SECOND = 60;

private:
	int currentFps = 0;				// Stores the current FPS, got from the framelock
	bool gameRunning = true;		// Bool flag to run the game loop
	GLuint defaultShaderProgram;	// ...

	std::shared_ptr<JN_Application> app = NULL;	// Application, stores the window, renderer etc.

	JN_Triangle tri;

	void Input();	// Input check
	void Render();	// Render objects and flip buffer
};

#endif // !JN_GAME_H

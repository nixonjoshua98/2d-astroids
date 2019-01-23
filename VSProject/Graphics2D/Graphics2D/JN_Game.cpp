
#include <iostream>

#include "JN_Game.h"
#include "JN_Logging.h"
#include "JN_FrameLock.h"


bool JN_Game::Init(std::shared_ptr<JN_Application> app)
{
	this->app = app;


	return true;
}


// Constructor
JN_Game::JN_Game()
{
	JN_AppendLog("Game created");
}


// Deconstructor
JN_Game::~JN_Game()
{
	JN_AppendLog("Game destroyed");
}


// Game loop
void JN_Game::Run()
{
	while (gameRunning)
	{
		auto frameLock = JN_FrameLock(FRAMES_PER_SECOND, currentFps);

		Input();
		Render();

		std::cout << "FPS: " << currentFps << std::endl;
	}
}


// Input check
void JN_Game::Input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:	// Window has been closed
			gameRunning = false;
			break;

		default:
			break;
		}
	}
}


// Render objects to buffer
void JN_Game::Render()
{
	app->ClearContext();


	SDL_GL_SwapWindow(app->GetWindow());	// Flip the buffer()
}

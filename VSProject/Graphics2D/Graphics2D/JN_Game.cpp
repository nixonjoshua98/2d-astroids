
#include <iostream>

#include "JN_Game.h"
#include "JN_Logging.h"
#include "JN_FrameLock.h"

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


bool JN_Game::Init(std::shared_ptr<JN_Application> app)
{
	this->app = app;
	this->player = std::make_shared<JN_Player>();

	this->player->Init();

	return true;
}


// Game loop
void JN_Game::Run()
{
	while (gameRunning)
	{
		auto frameLock = JN_FrameLock(FRAMES_PER_SECOND, currentFps);

		Input();
		Update();
		Render();
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
			player->Input(e);
			break;
		}
	}
}



void JN_Game::Update()
{
	player->Update();
}



// Render objects to buffer
void JN_Game::Render()
{
	app->ClearContext(0.0f, 0.0f, 0.0f);

	// ... Render stuff here
	player->Render();

	SDL_GL_SwapWindow(app->GetWindow());	// Flip the buffer()
}
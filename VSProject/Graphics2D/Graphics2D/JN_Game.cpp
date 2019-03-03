
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

	for (int i = 0; i < 50; i++)
	{
		bubbles.push_back(new JN_Bubble());
	}

	return true;
}


// Game loop
void JN_Game::Run()
{
	while (gameRunning)
	{
		auto frameLock = JN_FrameLock(60, currentFps);

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
			// Window has been closed
		case SDL_QUIT:
			gameRunning = false;
			break;

			// Key has been pressed
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_F11:
				app->ToggleFullScreen();
				break;

			default:
				player->Input(e);
				break;
			}

			// Key has been released
		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
			default:
				player->Input(e);
				break;
			}
		}
	}
}



void JN_Game::Update()
{
	player->Update();

	for (auto b : bubbles)
		b->Update();
}



// Render objects to buffer
void JN_Game::Render()
{
	app->ClearContext(0.0f, 0.0f, 0.0f);

	// ... Render stuff here
	player->Render();

	for (auto b : bubbles)
		b->Render();

	SDL_GL_SwapWindow(app->GetWindow());	// Flip the buffer
}
#include "JN_Game.h"



JN_Game::JN_Game()
{
}


JN_Game::~JN_Game()
{
}

bool JN_Game::Init(std::shared_ptr<JN_Application> app)
{
	this->app = app;

	player = std::make_unique<JN_Player>();
	background = std::make_unique<JN_Background>();

	player->Init();
	background->Init();

	bubble = new JN_Bubble();

	bubble->Init(0.2f, 0.0f, 0.0f, app->boundaries);

	return true;

}

void JN_Game::Run()
{
	while (gameRunning)
	{
		Input();
		Update();
		Render();
	}
}

void JN_Game::Input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;

		case SDL_WINDOWEVENT:
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				app->WindowResized();
				break;
			}
			break;

		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_F10:
				app->ToggleFullScreen();
				break;

			default:
				player->Input(e);
			}

		default:
			player->Input(e);
			break;
		}
	}
}

void JN_Game::Update()
{
	bubble->Update();

	background->SetUniforms(viewMatrix, projectionMatrix);
	player->SetUniforms(projectionMatrix, viewMatrix);
	bubble->SetUniforms(projectionMatrix, viewMatrix);
}

void JN_Game::Render()
{
	app->ClearContext(1, 1, 1);

	background->Render();
	player->Render();
	bubble->Render();

	SDL_GL_SwapWindow(app->GetWindow());

}

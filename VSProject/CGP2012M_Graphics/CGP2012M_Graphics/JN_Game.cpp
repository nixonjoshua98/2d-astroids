#include "JN_Game.h"
#include "JN_FrameLock.h"


JN_Game::JN_Game()
{
}


JN_Game::~JN_Game()
{
}

bool JN_Game::Init(std::shared_ptr<JN_Application> app)
{
	// Params
	this->app = app;

	// Smarts
	player = std::make_unique<JN_Player>();
	background = std::make_unique<JN_Background>();
	bubbles = std::make_unique<JN_BubbleController>();

	// Constructs
	text = Text("..//..//assets//fonts//cour.ttf");

	// Inits
	player->Init();
	background->Init();
	bubbles->Init(app->boundaries, viewMatrix, projectionMatrix);

	return true;
}

void JN_Game::Run()
{
	int f;
	while (gameRunning)
	{
		auto lock = JN_FrameLock(1000, f); // Lol

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
	if (_++ == 3000)
	{
		bubbles->AddBubble();
	}


	bubbles->Update();
	player->Update(bubbles->GetBubbles());

	background->SetUniforms(viewMatrix, projectionMatrix);
	player->SetUniforms(projectionMatrix, viewMatrix);

	//text.setText("Text", 255, 255, 255);
}

void JN_Game::Render()
{
	app->ClearContext(1, 1, 1);

	background->Render();
	player->Render();
	bubbles->Render();

	//text.render();

	SDL_GL_SwapWindow(app->GetWindow());
}

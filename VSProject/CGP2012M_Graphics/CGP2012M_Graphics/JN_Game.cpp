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
	player = std::make_shared<JN_Player>();
	background = std::make_unique<JN_Background>();
	bubbles = std::make_unique<JN_BubbleController>();
	playerHealthDisplay = std::make_unique<JN_ImageDisplay>();


	// Inits
	std::string files[] = { "Zero.png", "One.png", "Two.png", "Three.png" };

	playerHealthDisplay->Init(files, 4, glm::vec3(0.5f, 2.5f, 0.0f));
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
		auto lock = JN_FrameLock(60, f); // Lol

		//std::cout << f << std::endl;

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
	_++;
	if (_ == 120 && player->livesRemaining >= 0)
	{
		_ = 0;
		bubbles->AddBubble();
	}


	if (player->livesRemaining >= 0)
	{
		int livesLost = bubbles->Update(player->transform.GetPosition(), player->projectile.transform.GetPosition());
		player->Update();

		player->livesRemaining -= livesLost;
	}

	playerHealthDisplay->SetUniforms(viewMatrix, projectionMatrix);
	background->SetUniforms(viewMatrix, projectionMatrix);
	player->SetUniforms(projectionMatrix, viewMatrix);

	playerHealthDisplay->currentIndex = (int)fmaxf(player->livesRemaining, 0.0f);
}

void JN_Game::Render()
{
	app->ClearContext(1, 1, 1);

	background->Render();
	player->Render();
	bubbles->Render();
	playerHealthDisplay->Render();

	SDL_GL_SwapWindow(app->GetWindow());
}

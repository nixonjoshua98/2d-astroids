
#define LOG(x) std::cout << x << std::endl;

#include "JN_Game.h"
#include "JN_FrameLock.h"
#include "JN_Logging.h"


JN_Game::JN_Game()
{
	JN_AppendLog("Game created");
}


JN_Game::~JN_Game()
{
	JN_AppendLog("Game destroyed");
}


bool JN_Game::Init(std::shared_ptr<JN_Application> app)
{
	// Params
	this->app = app;


	// Smarts
	camera = std::make_unique<JN_Camera>();
	player = std::make_unique<JN_Player>();
	background = std::make_unique<JN_Background>();
	bubbles = std::make_unique<JN_BubbleController>();
	playerHealthDisplay = std::make_unique<JN_ImageDisplay>();
	gameoverDisplay = std::make_unique<JN_ImageDisplay>();


	// Inits
	camera->Init(app->aspectRatio, app->boundaries);
	playerHealthDisplay->Init(numbers, 4, glm::vec3(0.5f, 2.5f, 0.0f));
	gameoverDisplay->Init(gameoverImage, 1, glm::vec3(2.0f, 1.5f, 0.0f));
	bubbles->Init(app->boundaries, camera->viewMatrix, camera->projectionMatrix);

	return true;
}

void JN_Game::Run()
{
	int f;
	while (gameRunning)
	{
		auto lock = JN_FrameLock(60, f);

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
				if (!player->IsDead())
					player->Input(e);
			}

		default:
			if (!player->IsDead())
				player->Input(e);
			break;
		}
	}
}


void JN_Game::Update()
{
	if (!player->IsDead())
	{
		if (spawnTimer++ == 120)
		{
			spawnTimer = 0;
			bubbles->AddBubble();
		}

		bubbles->Update(player->GetPosition(), player->GetProjectilePosition(), player->GetLivesRemaining());
		player->Update(camera->projectionMatrix, camera->viewMatrix);
	}

	gameoverDisplay->SetUniforms(camera->viewMatrix, camera->projectionMatrix);
	playerHealthDisplay->SetUniforms(camera->viewMatrix, camera->projectionMatrix);
	background->SetUniforms(camera->viewMatrix, camera->projectionMatrix);

	playerHealthDisplay->SetCurrentIndex((int)fmaxf(player->GetLivesRemaining(), 0.0f));
}

void JN_Game::Render()
{
	app->ClearContext(1, 1, 1);

	background->Render();
	player->Render();
	bubbles->Render();

	if (player->IsDead())
		gameoverDisplay->Render();
	else
		playerHealthDisplay->Render();

	SDL_GL_SwapWindow(app->GetWindow());
}
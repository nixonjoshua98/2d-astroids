
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

	defaultShaderProgram = glCreateProgram();

	Shader frag = Shader(Shader::ShaderType::Fragment, "Shader.frag");
	Shader vert = Shader(Shader::ShaderType::Vertex, "Shader.vert");

	glAttachShader(defaultShaderProgram, frag.GetShaderID());
	glAttachShader(defaultShaderProgram, vert.GetShaderID());

	glLinkProgram(defaultShaderProgram);

	return true;
}


// Game loop
void JN_Game::Run()
{
	tri = JN_Triangle();
	tri.Init();
	

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
	app->ClearContext(0.0f, 0.0f, 0.0f);

	glUseProgram(defaultShaderProgram);

	tri.Render();

	SDL_GL_SwapWindow(app->GetWindow());	// Flip the buffer()
}
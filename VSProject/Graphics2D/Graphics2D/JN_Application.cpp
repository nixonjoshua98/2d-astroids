

#include <iostream>

#include "JN_Logging.h"
#include "JN_Application.h" 

#include <cstdio>
#include <cstdlib>
#include <iostream>




// Default constructor
JN_Application::JN_Application()
{
	JN_AppendLog("Application created");
}


// Deconstructor
JN_Application::~JN_Application()
{
	JN_AppendLog("Application destroyed");

	// Destroys the widgets
	SDL_DestroyWindow(window);
	SDL_GL_DeleteContext(context);

	// Removes nullptrs
	window, context = NULL, NULL;

	SDL_Quit();	// Closes all SDL sub systems
}


// Init the relevant sub-systems and create the initial widgets
bool JN_Application::Init()
{
	// SDL MUST be init first
	return InitSDL() && InitGL();
}


// Init SDl sub-systems
bool JN_Application::InitSDL()
{
	bool isSDL = SDL_Init(SDL_INIT_EVERYTHING) == 0;	// Init SDL

	if (isSDL)
	{
		window = SDL_CreateWindow(
			WINDOW_TITLE,		// Window title
			0, 0,				// Initial position of the window (x, y)
			0, 0,				// Width & height of the window
			SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE	// Window flags
		);

		if (window)
			SDL_SetWindowMinimumSize(window, STARTING_WIDTH, STARTING_HEIGHT);
	}

	SetWindowPosition();

	return isSDL;
}


// Init OpenGL systems
bool JN_Application::InitGL()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GL_MAJOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GL_MINOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	context = SDL_GL_CreateContext(window);

	//SDL_GL_SetSwapInterval(1);	// This stops the render delay

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
		return false;	

	return true;
}


// Clears the context
void JN_Application::ClearContext(float r, float g, float b)
{
	glClearColor(r, g, b, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
}


// Returns the private attribute <window>
SDL_Window* JN_Application::GetWindow()
{
	return window;
}


// NOTE: This only works if screen was full-screen
void JN_Application::SetWindowPosition()
{
	int w, h;

	SDL_GetWindowSize(window, &w, &h);	// Get current width, height

	// Half the geometry (CRG objective)
	STARTING_WIDTH = w / 2;
	STARTING_HEIGHT = h / 2;

	SDL_SetWindowSize(window, STARTING_WIDTH, STARTING_HEIGHT);					// Set the new geometry
	SDL_SetWindowFullscreen(window, 0);											// Disable full screen
	SDL_SetWindowPosition(window, STARTING_WIDTH / 2, STARTING_HEIGHT / 2);		// Center the window
};
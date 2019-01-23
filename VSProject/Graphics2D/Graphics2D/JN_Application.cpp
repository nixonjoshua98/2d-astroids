

#include <GL/glew.h>
#include <iostream>

#include "JN_Logging.h"
#include "JN_Application.h" 

// Default constructor
JN_Application::JN_Application()
{
	JN_AppendLog("Application constructed");
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
	return InitSDL();
}


// Init SDl sub-systems
bool JN_Application::InitSDL()
{
	bool isSDL = SDL_Init(SDL_INIT_EVERYTHING) == 0;	// Init SDL

	if (isSDL)
	{
		window = SDL_CreateWindow(
			WINDOW_TITLE, // Window title
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,	// Initial position of the window (x, y)
			STARTING_WIDTH, STARTING_HEIGHT,					// Width & height of the window
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE			// Window flags
		);

		if (window)
			SDL_SetWindowMinimumSize(window, STARTING_WIDTH, STARTING_HEIGHT);
	}

	return isSDL;
}


// Init OpenGL systems
bool JN_Application::InitGL()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GL_MAJOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GL_MINOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_PROFILE_CORE);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glewExperimental = GL_TRUE;

	return glewInit() == GLEW_OK;

}


// Returns the private attribute <window>
SDL_Window* JN_Application::GetWindow()
{
	return window;
}

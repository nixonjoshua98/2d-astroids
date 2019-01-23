#define SDL_MAIN_HANDLED

#include "JN_Application.h"
#include "JN_Logging.h"
#include "JN_Game.h"

#include <SDL.h>
#include <memory>

int main(int argc, char *argv[])
{
	JN_ClearLog();

	// Smart pointers...
	std::shared_ptr<JN_Application> app = std::make_shared<JN_Application>();
	std::shared_ptr<JN_Game> game = std::make_shared<JN_Game>();

	if (app->Init()) // Init sub-systems
	{
		JN_AppendLog("Application init OK");

		if (game->Init(app))	// Init and setup a game instance
		{
			JN_AppendLog("Game init OK");

			game->Run();
		}

	}


	return 0;
}
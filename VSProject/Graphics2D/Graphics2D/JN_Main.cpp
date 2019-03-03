#define SDL_MAIN_HANDLED

#include "JN_Application.h"
#include "JN_Logging.h"
#include "JN_Game.h"

#include <SDL.h>
#include <memory>


/*
	Window
		Pass:		Window with name, module, number									COMPLETE
		2.2:		Window move + resize												COMPLETE
		2.1:		Fullscreen															COMPLETE
		1st:		Aspect ratio
		1st+:		Half size of desktop and centered on startup						COMPLETE

	2D Geometry
		Pass:		Visible geometry for the player and bubbles
		2.2:		Correct size background
		2.1:		Geometry for world boundaries
		1st:		Player fires a projectile
		1st+:		Bubbles 'animate' when hit

	Playable Game:
		Pass:		Player can move/rotate and bubles can move							
		2.2:		Bubbles are constrained within playable area
		2.1:		Bubbles destroyed when hit
		1st:		Player has 3 lives which are shown onscreen
		1st+:		Player 'catches' the projectile or another gameplay mechanic

	Colours and Textures:
		Pass:		Geometry isn't all the same colour
		2.2:		Player is textured
		2.1:		Bubbles and background are textured
		1st:		Transparency
		1st+:		Bubbles/player show Textured destruction

	Shaders:
		Pass:		Vertex and fragment shader are present								
		2.2:		Shaders are in own file												
		2.1:		Variable data is passed as uniform to manipulate textures/geometry	
		1st:		Random colors for the bubbles created via shaders
		1st+:		Textures/geometry manipulated by shaders
*/

int main(int argc, char *argv[])
{
	JN_ClearLog();

	srand((int)time(NULL));

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
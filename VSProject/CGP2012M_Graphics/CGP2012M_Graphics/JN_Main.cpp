#include <memory>
#include <ctime>

#include "JN_Application.h"
#include "JN_Logging.h"
#include "JN_Game.h"

/*
Window
Pass:		Window with name, module, number									COMPLETE
2.2:		Window move + resize												COMPLETE
2.1:		Fullscreen															COMPLETE
1st:		Aspect ratio														COMPLETE
1st+:		Half size of desktop and centered on startup						COMPLETE

2D Geometry
Pass:		Visible geometry for the player and bubbles							COMPLETE
2.2:		Correct size background												COMPLETE
2.1:		Geometry for world boundaries										COMPLETE
1st:		Player fires a projectile											COMPLETE
1st+:		Bubbles 'animate' when hit											COMPLETE

Playable Game:
Pass:		Player can move/rotate and bubbles can move							COMPLETE			
2.2:		Bubbles are constrained within playable area						COMPLETE
2.1:		Bubbles destroyed when hit											COMPLETE
1st:		Player has 3 lives which are shown onscreen							COMPLETE
1st+:		Player 'catches' the projectile or another gameplay mechanic		COMPLETE

Colours and Textures:
Pass:		Geometry isn't all the same colour									COMPLETE
2.2:		Player is textured													COMPLETE
2.1:		Bubbles and background are textured									COMPLETE
1st:		Transparency														COMPLETE
1st+:		Bubbles/player show Textured destruction							COMPLETE

Shaders:
Pass:		Vertex and fragment shader are present								COMPLETE
2.2:		Shaders are in own file												COMPLETE
2.1:		Variable data is passed as uniform to manipulate textures/geometry	COMPLETE
1st:		Random colors for the bubbles created via shaders
1st+:		Textures/geometry manipulated by shaders							COMPLETE
*/

int main(int argc, char *argv[]) {
	auto app = std::make_shared<JN_Application>();
	auto game = std::make_shared<JN_Game>();

	srand(time(NULL));

	JN_ClearLog();

	if (app->Init())
	{
		if (game->Init(app))
		{
			game->Run();
		}
	}

	return 0;
}
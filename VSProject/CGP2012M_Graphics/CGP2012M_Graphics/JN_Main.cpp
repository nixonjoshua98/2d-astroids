#include <memory>
#include <ctime>

#include "JN_Application.h"
#include "JN_Logging.h"
#include "JN_Game.h"

int main(int argc, char *argv[]) {
	auto app = std::make_shared<JN_Application>();
	auto game = std::make_unique<JN_Game>();

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

#include "JN_Logging.h"

#include <fstream>

// Appends to the log file on a new line
void JN_AppendLog(std::string txt)
{
	std::ofstream f;

	f.open("./Resources/Data/GameLog.Log", std::ios_base::app);

	// If log file can be opened, write text to it
	if (f.good())
		f << txt << "\n";
}


// Opens the log file and closes it to clear it
void JN_ClearLog()
{
	std::ofstream f;

	f.open("./Resources/Data/GameLog.Log", std::ios_base::trunc | std::ios_base::out);
	
	f.close();
}
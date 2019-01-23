
#include "JN_Logging.h"

#include <fstream>


/* - - - -  CONSTANTS - - - - */
extern const char* LogConstants::LOG_FILE = "Data/GameLog.Log";


// Constructor
JN_LogTimeSpan::JN_LogTimeSpan(std::string txt)
{
	start = std::chrono::system_clock::now();
	this->txt = txt;
}


// Deconstructor
JN_LogTimeSpan::~JN_LogTimeSpan()
{
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> span = end - start;
	JN_AppendLog(txt + std::to_string(span.count()) + "ms");
}


// Appends to the log file on a new line
void JN_AppendLog(std::string txt)
{
	std::ofstream f;

	f.open(LogConstants::LOG_FILE, std::ios_base::app);

	// If log file can be opened, write text to it
	if (f.good())
		f << txt << "\n";
}


// Opens the log file and closes it to clear it
void JN_ClearLog()
{
	std::ofstream f;

	f.open(LogConstants::LOG_FILE, std::ios_base::trunc | std::ios_base::out);
	
	f.close();
}
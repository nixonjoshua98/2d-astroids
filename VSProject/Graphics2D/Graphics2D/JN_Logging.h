#ifndef JN_LOGGING_H
#define JN_LOGGING_H

#include <string>
#include <chrono>


namespace LogConstants
{
	extern const std::string LOG_FILE;	// Logging file path
}

struct JN_LogTimeSpan
{
public:
	JN_LogTimeSpan(std::string txt);	// Constructor
	~JN_LogTimeSpan();					// Deconstructor

private:
	std::chrono::system_clock::time_point start;	// Time at init
	std::string txt;								// String to output with the time
};


void JN_AppendLog(std::string txt);	// Append (trunc) to log file with a basic string
void JN_ClearLog();				// Empty the log file by opening it and closing it

#endif // !JN_LOGGING_H

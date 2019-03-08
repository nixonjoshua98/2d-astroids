#ifndef JN_LOGGING_H
#define JN_LOGGING_H

#include <string>

void JN_AppendLog(std::string txt);	// Append to log file with a basic string
void JN_ClearLog();					// Empty the log file by opening it and closing it

#endif // !JN_LOGGING_H

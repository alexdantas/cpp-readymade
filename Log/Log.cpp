#include "Log.hpp"

bool Log::isDebugMode     = false;
bool Log::isVerboseMode   = false;
bool Log::haveEscapeCodes = true;

// Terminal escape codes.
//
// They are commands to the terminal
// (print the following text at color X, clear the screen, etc).
//
// Don't use this on files!

std::string bold_red     = "\e[1;31m";
std::string red          = "\e[0;31m";
std::string bold_green   = "\e[1;32m";
std::string green        = "\e[0;32m";
std::string bold_yellow  = "\e[1;33m";
std::string yellow       = "\e[0;33m";
std::string bold_cyan    = "\e[1;36m";
std::string cyan         = "\e[0;36m";
std::string reset_color  = "\e[0m";
std::string clear_screen = "[H[2J";

// Prefixes
std::string errorPrefix   = "Error:   ";
std::string warningPrefix = "Warning: ";
std::string debugPrefix   = "Debug:   ";
std::string verbosePrefix = "Verbose: ";

void Log::error(std::string msg)
{
    std::cerr << bold_red << errorPrefix << msg << reset_color << std::endl;
}
void Log::warning(std::string msg)
{
    std::cerr << bold_yellow << warningPrefix << msg << reset_color << std::endl;
}
void Log::log(std::string msg)
{
    std::cout << bold_green << msg << reset_color << std::endl;
}
void Log::log_raw(std::string msg)
{
	std::cout << bold_green << msg << reset_color;
}
void Log::debug(std::string msg)
{
    if (isDebugMode)
        std::cerr << bold_cyan << debugPrefix << msg << reset_color << std::endl;
}
void Log::verbose(std::string msg)
{
    if (isVerboseMode)
        std::cerr << cyan << verbosePrefix << msg << reset_color << std::endl;
}
void Log::debugMode(bool option)
{
    if (option == false)
    {
        isDebugMode = false;
    }
    else
    {
	    // Tells we've started
	    Log::debug(">Debug mode activated");
	    isDebugMode = true;
    }
}
void Log::verboseMode(bool option)
{
    if (option == false)
    {
        isVerboseMode = false;
        return;
    }
    else
    {
	    // Tells we've started
	    Log::verbose(">Verbose Mode activated");
	    isVerboseMode = true;
    }
}
void Log::colors(bool option)
{
	if (option)
	{
		bold_red     = "\e[1;31m";
		red          = "\e[0;31m";
		bold_cyan    = "\e[1;36m";
		cyan         = "\e[0;36m";
		bold_green   = "\e[1;32m";
		green        = "\e[0;32m";
		bold_yellow  = "\e[1;33m";
		yellow       = "\e[0;33m";
		reset_color  = "\e[0m";
		clear_screen = "[H[2J";
	}
	else
	{
		bold_red     = "";
		red          = "";
		bold_cyan    = "";
		cyan         = "";
		bold_green   = "";
		green        = "";
		bold_yellow  = "";
		yellow       = "";
		reset_color  = "";
		clear_screen = "";
	}
}


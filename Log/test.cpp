#include "Log.hpp"

int main()
{
	Log::log("Hello, World!");
	Log::error("Something bad happened!");

	Log::debug("This won't be shown");
	Log::verbose("Neither this");

	Log::debugMode(true);
	Log::debug("Some debugging info");

	Log::verboseMode(true);
	Log::verbose("Verbose things");

	Log::colors(false);
	Log::log("So colorless... :(");

	return 0;
}


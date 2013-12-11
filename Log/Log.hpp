#ifndef LOG_H_DEFINED
#define LOG_H_DEFINED

#include <iostream>
#include <fstream>
#include <string>

/// Logs information on standard output streams.
///
/// With this class you can log different levels of information.
/// Currently we have _Error_, _Warning_, _Debug_ and _normal_ logs.
/// Each get printed with it's prefix.
///
/// ## Colors
///
/// By default it logs with terminal escape codes.
/// Basically they allow the output to be colorful at terminals.
///
/// Shit happens when you try logging int ofiles - you'll see
/// strange stuff like `\e[1;31m`.
///
/// To disable this behaviour, call `colors(false)`.
///
/// ## How to use
///
///     // It is a "global" static class.
///     Log::error("Class foo Method bar");
///     Log::warning("You shouldn't do that!");
///
///     Log::debugMode(true);
///     Log::debug("This will only be shown when debugMode(true)");
///
/// ## For developers
///
/// This is a standalone class, can be inserted on any project
/// regardless of library (assuming you have standard C++ I/O
/// classes).
///
/// @todo make method to set output to files, useful for ncurses
///      (like stderr.txt)
class Log
{
public:
    /// Logs *msg* with prefix "Error: " to `stderr`.
    static void error(std::string msg);

    /// Logs *msg* with prefix "Warning: " to `stderr`.
    static void warning(std::string msg);

    /// Logs *msg* to `stdout`.
    static void log(std::string msg);

	/// Logs `msg` without end of line.
	static void log_raw(std::string msg);

    /// Logs *msg* with prefix "Debug: " to `stdout`.
    ///
    /// @note Only gets logged if debug mode is on.
    static void debug(std::string msg);

	/// Logs *msg* with prefix "Verbose: " to `stdout`.
	///
	/// @note Only gets logged if verbose mode is on.
    static void verbose(std::string msg);

    /// Turns debug on/off.
    /// This tells if all debug messages will be ignored.
    ///
    /// @note By default it is turned off.
    static void debugMode(bool option);

    /// Turns verbose on/off.
    /// This tells if all verbose messages will be ignored.
    ///
    /// @note By default it is turned off.
    static void verboseMode(bool option);

    /// Enables/disables colors at output.
    ///
    /// @note By default it is turned on.
    static void colors(bool option);

private:
    static bool isDebugMode;     ///< Tells if we're on debug mode.
    static bool isVerboseMode;   ///< Tells if we're on verbose mode.
};

#endif /* LOG_H_DEFINED */


#include "Wrappers/Format.h"
#include "Core/Debug.h"

void Debug::logInfo(std::string text)
{
	//
	// TODO: Connect to some Log class.
	//
}

void Debug::logWarning(std::string text)
{
	//
	// TODO: Connect to some Log class.
	//
}

void Debug::logError(std::string text)
{
	//
	// TODO: Connect to some Log class.
	//
}

void Debug::onAssertionFailed(const char* eval, const char* file, unsigned int line, bool fatal)
{
	//
	// Spew the debug messages out to whatever listeners we have.
	// This would ideally redirect to some form of Log class which
	// has proper listeners/observers set up.
	//
	std::string message = std::format("{}:{}: Assertion failed: {}\n", file, line, eval);
	if (fatal)
		Debug::logError(message);
	else
		Debug::logWarning(message);

	//
	// Thanks to Valve for this incredible idea, actually.
	// If you're getting spammed with assertions over this, just go ahead and set this
	// value to false until you find the source of your problems. Just make sure to
	// switch it back on eventually because otherwise the whole point of assertions
	// turns kind of useless.
	//
	static constexpr bool shouldBreak = true;
	if (shouldBreak)
		DEBUG_BREAK();

	//
	// Worthwhile to look into the option of TerminateProcess instead of __fastfail.
	// Perhaps we could look into the way ReactOS handles both? Although fastfail
	// seems to be safer seeing how it's all done in the kernel wereas TerminateProcess
	// does still involve some form of usermode operation (haven't really had the chance to
	// thoroughly investigate what it actually does though).
	//
	if (fatal)
		SE_FASTFAIL(0x500);
}

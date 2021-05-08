
#include "Core/Platform.h"
#include "Native/Boot/SharedEntry.h"

#if SE_OS_WINDOWS
#	include "Native/Boot/Windows/WindowsBoot.h"
#endif

int main(int argc, char* argv[])
{
#if SE_OS_WINDOWS
	StormEngine::BootWindows();
#endif

	return 0;
}

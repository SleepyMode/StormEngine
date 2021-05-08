
#pragma once

//
// This stops us from defining UNREFERENCED_PARAMETER again.
// Maybe worthwhile to replace UNREFERENCED_PARAMETER with UNREFERENCED_PARAM
// or something similar to avoid needing to do stuff like this.
//
#define SE_NO_WIN32_DEFINES 1

#include "Core/Platform.h"

//
// Had to define NOGDI because the morons at microsoft defined like a million
// global variables with very common names like IWindow, IGenericWindow, etc.
// Imagine.
//
#if SE_OS_WINDOWS
#	define NOGDI
#	include <windows.h>
#endif

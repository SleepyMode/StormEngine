
#include "Wrappers/Windows.h"
#include "Native/Boot/Windows/WindowsBoot.h"

void StormEngine::BootWindows()
{
	WNDCLASSEXA wndClass{ 0 };
	wndClass.cbSize = sizeof(WNDCLASSEXA);
	RegisterClassExA(&wndClass);
}

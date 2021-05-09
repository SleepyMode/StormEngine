
#include "Wrappers/Windows.h"
#include "Native/Boot/Windows/WindowsBoot.h"

void StormEngine::bootWindows()
{
	WNDCLASSEXA wndClass{ 0 };
	wndClass.cbSize = sizeof(WNDCLASSEXA);
	RegisterClassExA(&wndClass);
}

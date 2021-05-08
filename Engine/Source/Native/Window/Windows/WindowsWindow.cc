
#include <Wrappers/Windows.h>
#include "Native/Window/Windows/WindowsWindow.h"

WindowsWindow::WindowsWindow()
{
	this->handle = nullptr;
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
	this->title = "";
	this->windowMode = WindowMode::Borderless;
}

WindowsWindow::~WindowsWindow()
{
	this->close();
}

bool WindowsWindow::isResizeable()
{
	return false;
}

bool WindowsWindow::hasFocus()
{
	return (GetActiveWindow() == this->handle);
}

void WindowsWindow::create()
{
}

void WindowsWindow::close()
{
	//
	// TODO: Might be worth not to worry about whether the handle is
	// 	   valid or not since Windows definitely checks for it and
	// 	   returns a value, but it avoids a kernel call.
	// 	   Someone should probably profile this.
	//
	if (this->handle != nullptr)
		DestroyWindow(this->handle);
}

void WindowsWindow::flash()
{
	if (this->handle == nullptr)
		return;

	FLASHWINFO flashInfo{ 0 };
	flashInfo.cbSize = sizeof(FLASHWINFO);
	flashInfo.hwnd = this->handle;
	flashInfo.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
	flashInfo.uCount = 0;
	flashInfo.dwTimeout = 1000;
	FlashWindowEx(&flashInfo);
}

void WindowsWindow::focus()
{
	BringWindowToTop(this->handle);
	SetActiveWindow(this->handle);
}

bool WindowsWindow::isMaximized()
{
	return false;
}

void WindowsWindow::maximize()
{
}

bool WindowsWindow::isMinimized()
{
	return false;
}

void WindowsWindow::minimize()
{
}

void WindowsWindow::setTitle(std::string title)
{
	this->title = title;

	if (this->handle != nullptr)
		SetWindowTextA(this->handle, title.c_str());
}

std::string WindowsWindow::getTitle()
{
	return this->title;
}

void WindowsWindow::setSize(std::uint32_t w, std::uint32_t h)
{
	this->w = w;
	this->h = h;
}

std::tuple<std::uint32_t, std::uint32_t> WindowsWindow::getSize()
{
	return std::tie(this->w, this->h);
}

void WindowsWindow::setPosition(std::uint32_t x, std::uint32_t y)
{
	this->x = x;
	this->y = y;
}

std::tuple<std::uint32_t, std::uint32_t> WindowsWindow::getPosition()
{
	if (this->handle != nullptr)
	{
		RECT windowRect{ 0 };
		if (GetWindowRect(this->handle, &windowRect))
		{
			this->x = windowRect.left;
			this->y = windowRect.top;
		}
	}

	return std::tie(this->x, this->y);
}

void WindowsWindow::setWindowMode(WindowMode mode)
{
	this->windowMode = mode;

	if (this->handle != nullptr)
	{
		switch (mode)
		{
			case WindowMode::Fullscreen:
				break;
			case WindowMode::Borderless:
				break;
			case WindowMode::Windowed:
				break;
		}
	}
}

WindowMode WindowsWindow::getWindowMode()
{
	return this->windowMode;
}


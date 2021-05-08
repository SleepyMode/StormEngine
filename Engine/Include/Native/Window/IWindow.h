
#pragma once

#include <cstdint>
#include "Concept/IStringifyable.h"
#include "Native/Window/WindowMode.h"

//
// Highly inspired by other game engines and GLFW, so, genuinely - thank you!
//

//
// Fun fact, this was named IBasicWindow for a while.
// Of course, Windows just HAS to have global variables named
// IWindow, IGenericWindow, etc, right?!
//
INTERFACE IWindow : public IStringifyable
{
public:
	virtual bool isResizeable() = 0;
	virtual bool hasFocus() = 0;
	virtual void create() = 0;
	virtual void close() = 0;
	virtual void flash() = 0;
	virtual void focus() = 0;

	[[deprecated]]
	virtual bool isMaximized() = 0;
	[[deprecated]]
	virtual void maximize() = 0;

	[[deprecated]]
	virtual bool isMinimized() = 0;
	[[deprecated]]
	virtual void minimize() = 0;

	virtual void setTitle(std::string title) = 0;
	virtual std::string getTitle() = 0;

	virtual void setSize(std::uint32_t w, std::uint32_t h) = 0;
	virtual std::tuple<std::uint32_t, std::uint32_t> getSize() = 0;

	virtual void setPosition(std::uint32_t x, std::uint32_t y) = 0;
	virtual std::tuple<std::uint32_t, std::uint32_t> getPosition() = 0;

	virtual void setWindowMode(WindowMode mode) = 0;
	virtual WindowMode getWindowMode() = 0;
};

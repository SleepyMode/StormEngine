
#pragma once

#include "Wrappers/Windows.h"
#include "Native/Window/IWindow.h"

class WindowsWindow : public IWindow
{
public:
	WindowsWindow();
	~WindowsWindow();

	virtual bool isResizeable() override;
	virtual bool hasFocus() override;
	virtual void create() override;
	virtual void close() override;
	virtual void flash() override;
	virtual void focus() override;

	[[deprecated]]
	virtual bool isMaximized() override;
	[[deprecated]]
	virtual void maximize() override;

	[[deprecated]]
	virtual bool isMinimized() override;
	[[deprecated]]
	virtual void minimize() override;

	virtual void setTitle(std::string title) override;
	virtual std::string getTitle() override;

	virtual void setSize(std::uint32_t w, std::uint32_t h) override;
	virtual std::tuple<std::uint32_t, std::uint32_t> getSize() override;

	virtual void setPosition(std::uint32_t x, std::uint32_t y) override;
	virtual std::tuple<std::uint32_t, std::uint32_t> getPosition() override;

	virtual void setWindowMode(WindowMode mode) override;
	virtual WindowMode getWindowMode() override;

private:
	HWND handle;
	std::uint32_t x;
	std::uint32_t y;
	std::uint32_t w;
	std::uint32_t h;
	std::string title;
	WindowMode windowMode;
};

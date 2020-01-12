#pragma once

#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <string>
#include "WindowManager.h"

class WindowsManager final :	 public IUpdatable
{
public:
	WindowsManager() = default;
	WindowsManager(const WindowsManager&) = delete;
	WindowsManager(const WindowsManager&&) = delete;
	~WindowsManager() = default;

	void update() override;
	void createWindow(std::string windowName, const int width, const int height);
	bool haveActiveWindows() const;

private:
	std::vector<boost::shared_ptr<WindowManager>> m_windowsList;

	TextureStorage m_textureStorage;
};


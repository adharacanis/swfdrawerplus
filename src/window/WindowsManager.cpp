#include "WindowsManager.h"

#include <utility>
#include <boost/make_shared.hpp>

void WindowsManager::update()
{
	glfwPollEvents();
	
	for (const auto& window : m_windowsList)
	{
		window->setFocus();

		if (window->isShouldClose())
		{
			//TODO: close window and free memory
			window->destroyWindow();
			m_windowsList.erase(std::remove(m_windowsList.begin(), m_windowsList.end(), window), m_windowsList.end());
		}
		else
		{
			window->update();
		}
	}
}

void WindowsManager::createWindow(std::string windowName, const int width, const int height)
{
	auto window = boost::make_shared<WindowManager>(std::move(windowName), width, height);
	const auto stage = boost::make_shared<Stage>(boost::make_shared<TextureStorage>(m_textureStorage));
	window->attachStage(stage);
	
	window->createWindow();
	
	m_windowsList.push_back(window);
}

bool WindowsManager::haveActiveWindows() const
{
	return !m_windowsList.empty();
}

#include "WindowManager.h"

#include <iostream>
#include <utility>

bool WindowManager::isShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void WindowManager::update()
{
	if (!isShouldClose())
	{
		if (m_stage != nullptr)
		{
			m_stage->update();
		}
		
		glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window);
	}
}

void WindowManager::initialize()
{
}

void WindowManager::createWindow()
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	m_window = glfwCreateWindow(m_width, m_height, m_windowName.data(), nullptr, nullptr);
	if (m_window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
	}

	setFocus();

	glfwSetKeyCallback(m_window, keyCallback);
	
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);

	glViewport(0, 0, width, height);
}

void WindowManager::destroyWindow()
{
	if (m_window != nullptr)
	{
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
}

void WindowManager::setFocus() const
{
	glfwMakeContextCurrent(m_window);
}

void WindowManager::attachStage(boost::shared_ptr<Stage> stage)
{
	m_stage = std::move(stage);
}

void WindowManager::keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

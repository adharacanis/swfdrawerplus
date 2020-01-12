#pragma once

#include "IUpdatable.h"
#include <GLFW/glfw3.h>
#include <boost/shared_ptr.hpp>
#include <string>
#include <utility>
#include <glm/vec3.hpp>
#include "display/Stage.h"

class WindowManager :
	public IUpdatable
{
public:
	WindowManager(std::string windowName, const int width, const int height, const int colorR = 1, const int colorG = 1, const int colorB = 1)
		: m_windowName(std::move(windowName))
		, m_width(width)
		, m_height(height)
		, m_clearColor(colorR, colorG, colorB)
	{}

	bool isShouldClose() const;
	
	virtual void update() override;

	void initialize();
	void createWindow();
	void destroyWindow();
	void setFocus() const;

	void attachStage(boost::shared_ptr<Stage> stage);

	static void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mode);

private:
	boost::shared_ptr<Stage> m_stage;
	
	GLFWwindow* m_window = nullptr;
	std::string m_windowName;
	
	int m_width;
	int m_height;

	glm::vec3 m_clearColor;
};


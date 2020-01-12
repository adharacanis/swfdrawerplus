#include "Main.h"
#include "window/WindowsManager.h"
#include "window/OpenGLInitializer.h"
#include <iostream>

#pragma comment(lib, "opengl32.lib")

int main(int argc, char *argv[])
{
	OpenGLInitializer glInitializer;
	glInitializer.initialize();
	
	WindowsManager windowsManager;
	windowsManager.createWindow("default window", 800 * 2, 600 * 2);
	//windowsManager.createWindow("default window2", 800 * 2, 600 * 2);

	float fps = 60.0f;
	double tickTime = 1.0f / fps;
	double previousTime = 0.0;
	
	while (windowsManager.haveActiveWindows())
	{
		double currentTime = glfwGetTime();
		
		if (currentTime - previousTime >= tickTime)
		{
			if (!glInitializer.isHaveError())
			{
				previousTime = currentTime;
				windowsManager.update();
			}
			else
			{
				glInitializer.terminateWindow();
				return -1;
			}
			//std::cout << "tick" << std::endl;
		}
	}
	
	return 0;
}

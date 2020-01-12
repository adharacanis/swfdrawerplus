#include "OpenGLInitializer.h"

#define GLEW_STATIC
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <cstdio>

void OpenGLInitializer::initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwSetErrorCallback(errorCallback);
}

void OpenGLInitializer::terminateWindow()
{
	glfwTerminate();
}

bool OpenGLInitializer::isHaveError()
{
	return m_isHaveError;
}

Error& OpenGLInitializer::getLastError()
{
	return m_lastError;
}

void OpenGLInitializer::errorCallback(int error, const char* description)
{
	getInstance().m_isHaveError = true;
	getInstance().m_lastError.setTo(error, description);
	fputs(description, stderr);
}

OpenGLInitializer& OpenGLInitializer::getInstance()
{
	static OpenGLInitializer instance;
	return instance;
}

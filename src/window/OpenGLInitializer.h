#pragma once

#include "error/Error.h"

class OpenGLInitializer
{
public:
	void initialize();
	void terminateWindow();

    bool isHaveError();
	Error& getLastError();
	
	static void errorCallback(int error, const char* description);

	static OpenGLInitializer& getInstance();

    OpenGLInitializer() = default;
    OpenGLInitializer(OpenGLInitializer const&) = delete;
    OpenGLInitializer(OpenGLInitializer const&&) = delete;
    void operator=(OpenGLInitializer const&) = delete; 
    void operator=(OpenGLInitializer const&&) = delete;

    ~OpenGLInitializer() = default;

private:
    Error m_lastError;
    bool m_isHaveError = false;
};


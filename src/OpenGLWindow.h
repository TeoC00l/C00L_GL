#pragma once 
#include <string>

class GLFWwindow;

class OpenGLWindow
{
public:
	OpenGLWindow();

	bool createOpenGLWindow(const std::string& windowTitle);
	void runApp();

private:
	GLFWwindow* window;

	void initializeScene();
	void renderScene();
	void updateScene();
};
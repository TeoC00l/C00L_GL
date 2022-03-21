//stl
#include <string>
#include <iostream>
#include <cstdio>
//project
#include "OpenGLWindow.h"
#include "Shader.h"
#include "VertexBufferObject.h"

int main()
{
	std::cout<<"started application"<<std::endl;

	OpenGLWindow* window = new OpenGLWindow();
	const std::string& windowTitle = "C00lGrid";
	window->createOpenGLWindow(windowTitle);
	window->runApp();

	std::getchar();

	std::cout<<"ended application"<<std::endl;

	return 0;
}
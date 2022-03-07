#include <string>
#include "OpenGLWindow.h"
#include "Shader.h"
#include "VertexBufferObject.h"

int main()
{
	OpenGLWindow* window = new OpenGLWindow();
	const std::string& windowTitle = "C00lGrid";
	window->createOpenGLWindow(windowTitle);
	window->runApp();

	return 0;
}
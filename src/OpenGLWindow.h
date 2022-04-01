#pragma once
//ogl
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
//stl
#include <string>
//glm
#include "glm/gtc/matrix_transform.hpp"

class OpenGLWindow
{
public:
	OpenGLWindow();

	bool createOpenGLWindow(const std::string& windowTitle);
	void runApp();

	bool keyPressed(int keyCode) const;

private:
	GLFWwindow* window;
	glm::mat4 projectionMatrix;
	glm::mat4 orthoMatrix;

	float time = 0.0f;
	float timeDelta = 0.0f;
	float rotationAngleRad = 0.0f;

	void initializeScene();
	void renderScene();
	void updateScene();

	void recalculateProjectionMatrix();

	void renderTestHouseColumn(float xCoordinate, int noOfHouses);
	void renderSpinningTest(glm::vec3 position);
};
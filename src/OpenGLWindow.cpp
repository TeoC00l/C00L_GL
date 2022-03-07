#include "OpenGLWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShaderProgram.h"
#include "VertexBufferObject.h"
#include "glm/glm.hpp"
#include <iostream>

Shader vertexShader, fragmentShader;
ShaderProgram shaderProgram;
VertexBufferObject shapesVBO;
GLuint mainVAOhandle;

OpenGLWindow::OpenGLWindow()
{

}

void OpenGLWindow::initializeScene()
{
	glClearColor(0.00000f, 0.27843f, 0.19216f, 1.0f);

	vertexShader.loadShaderFromFile("src/Shaders/tut02.vert", GL_VERTEX_SHADER);
	fragmentShader.loadShaderFromFile("src/Shaders/tut02.frag", GL_FRAGMENT_SHADER);

	if(!vertexShader.getCompilationStatus() || !fragmentShader.getCompilationStatus())
	{
		glfwWindowShouldClose(window);
		return;
	}

	shaderProgram.createProgram();
	shaderProgram.addShaderToProgram(vertexShader);
	shaderProgram.addShaderToProgram(fragmentShader);

	if(!shaderProgram.linkProgram())
	{
		glfwWindowShouldClose(window);
		return;
	}

	glGenVertexArrays(1, &mainVAOhandle); //creates one VAO
	glBindVertexArray(mainVAOhandle);

	glm::vec3 vTraingle[] = { glm::vec3(-0.4, 0.1f, 0.0f), glm::vec3(0.4, 0.1f, 0.0f), glm::vec3(0.0, 0.7f, 0.0f) }; 
	glm::vec3 vQuad[] = { glm::vec3(-0.2f, -0.1f, 0.0f) , glm::vec3(-0.2f, -0.6f, 0.0f) , glm::vec3(0.2f, -0.1f, 0.0f) , glm::vec3(0.2f, -0.6f, 0.0f) };

	shapesVBO.createVBO();
	shapesVBO.bindVBO();
	shapesVBO.addData(vTraingle);
	shapesVBO.addData(vQuad);
	shapesVBO.uploadDataToGPU(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(glm::vec3), 0);
}

void OpenGLWindow::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	shaderProgram.useProgram();
	glBindVertexArray(mainVAOhandle);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLE_STRIP, 3, 4);
}

void OpenGLWindow::updateScene()
{
	
}

bool OpenGLWindow::createOpenGLWindow(const std::string& windowTitle)
{
	glfwInit();

	window = glfwCreateWindow(800.f, 800.f, windowTitle.c_str(), NULL, NULL);

	if(window == nullptr)
	{
		return false;
	}

	glfwMakeContextCurrent(OpenGLWindow::window);
	gladLoadGL();

	return true;
}

void OpenGLWindow::runApp()
{
	initializeScene();

	while(glfwWindowShouldClose(window) == false)
	{
		renderScene();
		glfwSwapBuffers(window);
		glfwPollEvents();
		updateScene();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}
//project
#include "OpenGLWindow.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "VertexBufferObject.h"
#include "StaticGeometry.h"
#include "SimpleWalkingCamera.h"
//glm
#include "glm/gtc/type_ptr.hpp"
//stl
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>

Shader vertexShader, fragmentShader;
ShaderProgram shaderProgram;
VertexBufferObject shapesVBO;
VertexBufferObject colorVBO;
GLuint mainVAOhandle;

float width = 800;
float height = 800;

SimpleWalkingCamera camera(glm::vec3(0.0f, 0.0f, 20.0f), glm::vec3(0.0f, 0.0f, 19.0f), glm::vec3(0.0f, 1.0f, 0.0f));

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

	shapesVBO.createVBO();
	shapesVBO.bindVBO();
	shapesVBO.addData(StaticGeometry::cubeVertices);
	shapesVBO.addData(StaticGeometry::pyramidVertices);
	shapesVBO.uploadDataToGPU(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);

	colorVBO.createVBO();
	colorVBO.bindVBO();
	colorVBO.addData(StaticGeometry::cubeFaceColors, 6);
	colorVBO.addData(StaticGeometry::pyramidFaceColors, 6);

	colorVBO.uploadDataToGPU(GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);

	glEnable(GL_DEPTH_TEST);
}

void OpenGLWindow::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderProgram.useProgram();
	glBindVertexArray(mainVAOhandle);

	//set projection matrix
	recalculateProjectionMatrix();
	shaderProgram.getUniform("projectionMatrix").set4x4Matrix(projectionMatrix);

	// //set view matrix
	// glm::mat4 viewMatrix
	// (
	// 	glm::lookAt
	// 	( 
	// 		glm::vec3(0.0f, 0.0f, 20.0f),
	// 		glm::vec3(0.0f, 0.0f, 0.0f),
	// 		glm::vec3(0.0f, 1.0f, 0.0f) 
	// 	)
	// );

	shaderProgram.getUniform("viewMatrix").set4x4Matrix(camera.getViewMatrix());
	
	//set model matrix for cube
	glm::mat4 modelMatrixCube = glm::mat4(1.0);
	modelMatrixCube = glm::rotate(modelMatrixCube, rotationAngleRad, glm::vec3(1.0f, 0.0f, 0.0f));
	modelMatrixCube = glm::rotate(modelMatrixCube, rotationAngleRad, glm::vec3(0.0f, 1.0f, 0.0f));
	modelMatrixCube = glm::rotate(modelMatrixCube, rotationAngleRad, glm::vec3(0.0f, 0.0f, 1.0f));
	modelMatrixCube = glm::scale(modelMatrixCube, glm::vec3(5.0f, 5.0f, 5.0f));

	//draw cube
	shaderProgram.getUniform("modelMatrix").set4x4Matrix(modelMatrixCube);
	glDrawArrays(GL_TRIANGLES, 0, 36);


	glm::vec3 pyramidTranslationVectors[] =
	{
		glm::vec3(-5.0f, 3.0f, 0.0f),
		glm::vec3(5.0f, 3.0f, 0.0f),
		glm::vec3(5.0f, -3.0f, 0.0f),
		glm::vec3(-5.0f, -3.0f, 0.0f)
	};

	for(glm::vec3 pyramidTranslation : pyramidTranslationVectors)
	{
		glm::mat4 modelMatrixPyramid = glm::mat4(1.0);
		modelMatrixPyramid = glm::translate(modelMatrixPyramid, pyramidTranslation);
		modelMatrixPyramid = glm::rotate(modelMatrixPyramid, rotationAngleRad, glm::vec3(0.0f, 1.0f, 0.0f));
		modelMatrixPyramid = glm::scale(modelMatrixPyramid, glm::vec3(3.0f, 3.0f, 3.0f));

		shaderProgram.getUniform("modelMatrix").set4x4Matrix(modelMatrixPyramid);
		glDrawArrays(GL_TRIANGLES, 36, 12);
	}
}

void OpenGLWindow::updateScene()
{
	timeDelta = glfwGetTime() - time;
	time = glfwGetTime();
	rotationAngleRad += glm::radians(90.f * timeDelta);

	camera.update([this](int keyCode) {return this->keyPressed(keyCode); }, timeDelta);
}

bool OpenGLWindow::createOpenGLWindow(const std::string& windowTitle)
{
	glfwInit();

	window = glfwCreateWindow(width, height, windowTitle.c_str(), NULL, NULL);

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


void OpenGLWindow::recalculateProjectionMatrix()
{
	int iWidth, iHeight;
	glfwGetWindowSize(window, &iWidth, &iHeight);
	projectionMatrix = glm::perspective(glm::radians(57.0f), (float)iWidth / (float)iHeight, 0.5f, 1500.0f);
	orthoMatrix = glm::ortho(0.0f, (float)iWidth, 0.0f, (float)iHeight );
}

bool OpenGLWindow::keyPressed(int keyCode) const
{
	return glfwGetKey(window, keyCode) == GLFW_PRESS;
}
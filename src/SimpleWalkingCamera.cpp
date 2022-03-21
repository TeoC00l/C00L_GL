//ogl
#include <GLAD/glad.h>
//project
#include "SimpleWalkingCamera.h"
//glm
#include "glm/gtc/matrix_transform.hpp"


SimpleWalkingCamera::SimpleWalkingCamera(const glm::vec3& position, const glm::vec3& viewPoint, 
	const glm::vec3& upVector, float moveSpeed, float rotationSpeed)
{
	SimpleWalkingCamera::position = position;
	SimpleWalkingCamera::viewPoint = viewPoint;
	SimpleWalkingCamera::upVector = upVector;
	SimpleWalkingCamera::moveSpeed = moveSpeed;
	SimpleWalkingCamera::rotationSpeed = rotationSpeed;

	setControls(GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D);
}

void SimpleWalkingCamera::setControls(int forwardKeyCode, int backwardKeyCode, int rotateLeftKeyCode, int rotateRightKeyCode)
{
	SimpleWalkingCamera::forwardKeyCode = forwardKeyCode;
	SimpleWalkingCamera::backwardKeyCode = backwardKeyCode;
	SimpleWalkingCamera::rotateLeftKeyCode = rotateLeftKeyCode;
	SimpleWalkingCamera::rotateRightKeyCode = rotateRightKeyCode;
}

glm::vec3 SimpleWalkingCamera::getNormalizedViewVector() const
{
	return glm::normalize(viewPoint - position);
}

void SimpleWalkingCamera::move(float distance)
{
	glm::vec3 offset = getNormalizedViewVector();
	offset *= distance;
	position += offset;
	viewPoint += offset;
}

void SimpleWalkingCamera::rotate(float angleInDeg)
{
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0), glm::radians(angleInDeg), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::vec4 rotatedViewVector = rotationMatrix * glm::vec4(getNormalizedViewVector(), 0.0f);
	viewPoint = position + glm::vec3(rotatedViewVector.x, rotatedViewVector.y, rotatedViewVector.z);
}

void SimpleWalkingCamera::update(const std::function<bool(int)>& keyInputFunc, float deltaTime)
{
	if(keyInputFunc(forwardKeyCode))
	{
		move(moveSpeed * deltaTime);
	}

	if(keyInputFunc(backwardKeyCode))
	{
		move(-moveSpeed * deltaTime);
	}

	if(keyInputFunc(rotateLeftKeyCode))
	{
		rotate(rotationSpeed * deltaTime);
	}

	if(keyInputFunc(rotateRightKeyCode))
	{
		rotate(-rotationSpeed * deltaTime);
	}
}

glm::mat4 SimpleWalkingCamera::getViewMatrix() const
{
	return glm::lookAt(position, viewPoint, upVector);
}


#pragma once
//ogl
#include <GLFW/glfw3.h>
//stl
#include <functional>
//glm
#include "glm/glm.hpp"

class SimpleWalkingCamera
{

public:
	SimpleWalkingCamera(const glm::vec3& position, const glm::vec3& viewPoint, 
		const glm::vec3& upVector, float moveSpeed = 10.0f, float rotationSpeed = 135.0f);

	glm::mat4 getViewMatrix() const;

	void setControls(int forwardKeyCode, int backwardKeyCode, int rotateLeftKeyCode, int rotateRightKeyCode);
	void update(const std::function<bool(int)>& keyInputFunc, float deltaTime);
private:
	glm::vec3 position;
	glm::vec3 viewPoint;
	glm::vec3 upVector;

	float moveSpeed;
	float rotationSpeed;
	int forwardKeyCode;
	int backwardKeyCode;
	int rotateLeftKeyCode;
	int rotateRightKeyCode;

	void move(float distance);
	void rotate(float angleInDeg);

	glm::vec3 getNormalizedViewVector() const;
};
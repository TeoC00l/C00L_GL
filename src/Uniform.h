#pragma once
//ogl
#include <GLAD/glad.h>
//glm
#include "glm/gtc/matrix_transform.hpp"
//stl
#include <string>

class ShaderProgram;

class Uniform
{

public:
	Uniform();
	Uniform(const std::string& name, ShaderProgram* shaderProgram);

	void set4x4Matrix(glm::mat4 matrix) const;

private:
	std::string name = "";
	GLint location = -1;
	ShaderProgram* shaderProgram = nullptr;
};
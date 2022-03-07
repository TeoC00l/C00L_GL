#pragma once

#include <GLAD/glad.h>
#include "Shader.h"

class ShaderProgram
{

public:
	GLuint shaderProgramID = 0;

	void createProgram();
	bool addShaderToProgram(const Shader& shader) const;
	bool linkProgram();
	void useProgram();

private:
	bool isLinked = false;

};
#pragma once

#include <map>
#include <string>
#include "Uniform.h"
#include <GLAD/glad.h>
#include "Shader.h"
#include "glm/glm.hpp"

class ShaderProgram
{

public:
	GLuint shaderProgramID = 0;

	void createProgram();
	bool addShaderToProgram(const Shader& shader) const;
	bool linkProgram();
	void useProgram();

	GLuint getShaderProgramID();
	Uniform& getUniform(std::string name);

private:
	bool isLinked = false;
	std::map<std::string, Uniform> uniforms;
};
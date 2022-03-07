#include "ShaderProgram.h"
#include <iostream>

void ShaderProgram::createProgram()
{
	shaderProgramID = glCreateProgram();
}

bool ShaderProgram::addShaderToProgram(const Shader& shader) const
{
	if(!shader.getCompilationStatus())
		return false;

	glAttachShader(shaderProgramID, shader.getShaderID());

	return true;
}

bool ShaderProgram::linkProgram()
{
	if(isLinked)
		return true;

	glLinkProgram(shaderProgramID);
	GLint linkStatus;
	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &linkStatus);
	isLinked = linkStatus == GL_TRUE;

	if(!isLinked)
		std::cerr <<"ERROR! Shader program wasn't linked!" <<std::endl;
	else
		std::cout<<"Program Linked sucessfully" << std::endl;
	
	return isLinked;
}

void ShaderProgram::useProgram()
{
	if(isLinked)
		glUseProgram(shaderProgramID);
}
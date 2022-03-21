//C00l
#include "Uniform.h"
#include "ShaderProgram.h"
//stl
#include <iostream>
//glm
#include "glm/gtc/type_ptr.hpp"

Uniform::Uniform()
{

}

Uniform::Uniform(const std::string& name, ShaderProgram* shaderProgram)
{
	Uniform::name = name;
	Uniform::shaderProgram = shaderProgram;
	location = glGetUniformLocation(shaderProgram->getShaderProgramID(), name.c_str());
	
	if(location == -1)
		std::cout<<"Warning: uniform with name ' " << name << "' does not exist, fail" << std::endl;
}

void Uniform::set4x4Matrix(glm::mat4 matrix) const
{
	glUniformMatrix4fv(location, 1, false, glm::value_ptr(matrix));
}
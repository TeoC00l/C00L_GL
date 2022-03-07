#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

class Shader
{
public:
	bool loadShaderFromFile(const char* path, GLenum shaderType);
	bool getCompilationStatus() const;
	GLuint getShaderID() const;

private:
	bool isCompiled = false;
	GLuint shaderID = 0;
	char* getLinesFromFile(const char* path, GLint &fileSize);
};
#include "Shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

bool Shader::loadShaderFromFile(const char* path, GLenum shaderType)
{
	GLint fileSize = 0;
	char* fileLines = getLinesFromFile(path, fileSize);

	shaderID = glCreateShader(shaderType);

	glShaderSource(shaderID, 1, &fileLines, &fileSize);
	glCompileShader(shaderID);

	delete[] fileLines;

	GLint compileStatus;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);

	if(!compileStatus)
	{
		char infoBuffer[1024];
        glGetShaderInfoLog(shaderID, 1024, NULL, infoBuffer);
        printf("COMPILE ERROR :O :\n%s\n", infoBuffer);
        return false;
	}

	isCompiled = true;
	return true;
}

char* Shader::getLinesFromFile(const char* path, GLint &fileSize)
{
	FILE* filePtr = NULL;
	fopen_s(&filePtr, path, "rb");
	if(!filePtr)
	{
		printf("Failed to load shader %s\n", path);
		return nullptr;
	}

	fseek(filePtr, 0, SEEK_END);
	fileSize = ftell(filePtr);
	fseek(filePtr, 0, SEEK_SET);

	char* fileBuffer = (char*)malloc(fileSize);
	fread(fileBuffer, 1, fileSize, filePtr);

	fclose(filePtr);

	return fileBuffer;
}

bool Shader::getCompilationStatus() const
{
	return isCompiled;
}

GLuint Shader::getShaderID() const
{
	return shaderID;
}

#pragma once

#include <GLAD/glad.h>
#include <vector>

class VertexBufferObject
{

public:
	void createVBO(uint32_t reserveSizebytes = 0);
	void bindVBO(GLenum bufferType = GL_ARRAY_BUFFER);
	void addRawData(const void* ptrData, uint32_t dataSizeBytes, size_t repeat);
	void uploadDataToGPU(GLenum usageHint);

	template<typename T>
	void addData(const T& ptrObj, size_t repeat = 1)
	{
		addRawData(&ptrObj, static_cast<size_t>(sizeof(T)), repeat);
	}

private:
	GLuint bufferID = 0;
	GLenum bufferType = GL_ARRAY_BUFFER;
	size_t bytesAdded = 0;
	std::vector<unsigned char> rawData;

	bool isBufferCreated();

};
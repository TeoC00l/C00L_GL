#include "VertexBufferObject.h"
#include <iostream>

void VertexBufferObject::createVBO(uint32_t reserveSizeBytes)
{
	if(isBufferCreated())
	{
		std::cerr<<"this buffer is already created!"<<std::endl;
		return;
	}

	glGenBuffers(1, &bufferID);
	rawData.reserve(reserveSizeBytes > 0 ? reserveSizeBytes : 1024);
	std::cout << "Created vertex buffer object with ID " << bufferID << " and size " << rawData.capacity() << std::endl;
}

void VertexBufferObject::bindVBO(GLenum bufferType)
{
	if(!isBufferCreated())
	{
		std::cerr << "Buffer not created yet, can't bind it " << std::endl;
		return;
	}

	VertexBufferObject::bufferType = bufferType;
	glBindBuffer(bufferType, bufferID);
}

bool VertexBufferObject::isBufferCreated()
{
	return (bufferID != 0);
}

void VertexBufferObject::addRawData(const void* ptrData, uint32_t dataSizeBytes, size_t repeat)
{
	const size_t bytesToAdd = dataSizeBytes * repeat;
	const size_t requiredCapacity = bytesAdded + bytesToAdd;

	//Expand rawData to accomodate new capacity
	if(requiredCapacity > rawData.capacity())
	{
		size_t newCapacity = rawData.capacity() * 2;

		while(newCapacity < requiredCapacity)
			newCapacity *= 2;

		std::vector<unsigned char> newRawData;
		newRawData.reserve(newCapacity);
		memcpy(newRawData.data(), rawData.data(), bytesAdded);
		rawData = std::move(newRawData);
	}

	//add new data to rawData
	for(size_t i = 0; i < repeat; i++)
	{
		memcpy(rawData.data() + bytesAdded, ptrData, dataSizeBytes);
		bytesAdded += dataSizeBytes;
	}
}

void VertexBufferObject::uploadDataToGPU(GLenum usageHint)
{
	if(!isBufferCreated())
	{
		std::cerr << "Buffer not created yet, can't upload data to gpu " << std::endl;
		return;
	}

	glBufferData(bufferType, bytesAdded, rawData.data(), usageHint);
	bytesAdded = 0;
}
#version 330 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

smooth out vec3 ioVertexColor;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1.0);
	ioVertexColor = vertexColor;
}
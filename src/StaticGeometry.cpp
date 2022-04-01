
//project
#include "StaticGeometry.h"

namespace StaticGeometry
{
	glm::vec3 cubeVertices[36] =
    {
        // Front face
        glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-0.5f, 0.5f, 0.5f),
        // Back face
        glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.5f, 0.5f, -0.5f),
        // Left face
        glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, 0.5f, -0.5f),
        // Right face
        glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f),
        // Top face
        glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-0.5f, 0.5f, -0.5f),
        // Bottom face
        glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, 0.5f),
    };

    glm::vec3 cubeFaceColors[6] =
    {
    	glm::vec3(0.0, 0.5, 0.3), glm::vec3(0.0, 0.3, 0.3), glm::vec3(0.0, 0.5, 0.3),
        glm::vec3(0.0, 0.5, 0.3), glm::vec3(0.0, 0.3, 0.3), glm::vec3(0.0, 0.5, 0.3)
    };

    glm::vec3 pyramidVertices[12] =
    {
        // Front face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f),
        // Back face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, -0.5f),
        // Left face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-0.5f, -0.5f, 0.5f),
        // Right face
        glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, -0.5f)
    };

    glm::vec3 pyramidFaceColors[3] =
    {
		glm::vec3(0.0, 0.5, 0.3), glm::vec3(0.0, 0.3, 0.3), glm::vec3(0.0, 0.5, 0.3)
    };

    glm::vec3 groundRectangleVertices[4]
    {
        glm::vec3(-200.0f, 0.0f, -200.0f), // Left-back point
        glm::vec3(-200.0f, 0.0f, 200.0f), // Left-front point
        glm::vec3(200.0f, 0.0f, -200.0f), // Right-back point
        glm::vec3(200.0f, 0.0f, 200.0f) // Right-front point
    };

    glm::vec3 groundRectangleColors[4]
    {
        glm::vec3(0.0f, 0.3f, 0.1f),
        glm::vec3(0.0f, 0.55f, 0.0f),
        glm::vec3(0.0f, 0.15f, 0.15f),
        glm::vec3(0.0f, 0.5f, 0.2f)
    };
}
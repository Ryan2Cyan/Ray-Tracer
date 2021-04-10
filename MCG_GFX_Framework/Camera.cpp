#include "Camera.h"
#include "Utility.h"

// Constructors:
Camera::Camera() 
{
	// Create an inverted ModelViewProjection matrix on init:
	CreateInvertedMVP();
}
Camera::Camera(float fovs, glm::vec2 screenResolution) : m_fovs(fovs), m_AspectRatio((float)m_ScreenResolution.x / (float)m_ScreenResolution.y), m_ScreenResolution(screenResolution), Entity()
{
	// Create an inverted ModelViewProjection matrix on init:
	CreateInvertedMVP();
}
// Destructor
Camera::~Camera() {}

// This function takes in a pair of coordinates and returns a Ray:
Ray Camera::GenerateSingleRay(glm::vec2 pixelCoordinates)
{
	// Convert pixels range to be between -1 and 1 (near and far planes)
	float NDCX = MapCoordinate(pixelCoordinates.x, 0.f, m_ScreenResolution.x, -1.f, 1.f);
	float NDCY = MapCoordinate(pixelCoordinates.y, 0.f, m_ScreenResolution.y, -1.f, 1.f);
	
	// Express the coordinates as the near and far planes:
	// The 'w' components need to be '1', as they are positions in space:
	glm::vec4 nearPlane{ NDCX, NDCY, 0, 1 }; // z is 0 as this is closer to origin.
	glm::vec4 farPlane{ NDCX, NDCY, 1, 1 }; // z is 1 as this is farther from origin (3D objects go between near and far).

	// Multiply the near and far planes by the MVP matrix:
	// This sets up z-axis in the frustum, creating perspective:
	nearPlane = m_MVPMatrix * nearPlane;
	farPlane = m_MVPMatrix * farPlane;

	// Normalise the w coordinate, just-in-case it deviates from 1:
	nearPlane.w /= nearPlane.w;
	farPlane.w /= farPlane.w;

	// Create the ray object:
	// Assign the Position of the Ray to be the near plane (where it starts):
	// Assign the Direction of the Ray to be near plane - far plane (where the ray is heading):
	Ray newRay(nearPlane, (nearPlane - farPlane));
	
	// Return the ray:
	return newRay;
}

glm::mat4 Camera::CreateInvertedMVP()
{
	// Create Projection Matrix:
	glm::mat4 projectionMat = glm::perspective(glm::radians(m_fovs), m_AspectRatio, 0.1f, 100.f);

	// Invert projection mat:
	glm::mat4 inverseProjMat = glm::inverse(projectionMat);

	// View Matrix:
	glm::mat4 viewMat = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3) in world space
		glm::vec3(0, 0, 0), // Camera looks at the origin.
		glm::vec3(0, 1, 0) // Camera is head-up (0,-1,0) would be upside down.
		);

	// Model Matrix (an identity mat) - model will be at the origin:
	glm::mat4 modelMat(1.0f);

	// MVP (ModelViewProjection Matrix):
	glm::mat4 MVPMatrix = inverseProjMat * viewMat * modelMat;

	return MVPMatrix;
}
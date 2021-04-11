#include "RayTracer.h"

Light directionalLight;

// Constructor
RayTracer::RayTracer() {}
// Destructor
RayTracer::~RayTracer() {}


glm::vec3 RayTracer::GenerateColor(Ray ray, Sphere sphere)
{
	// Find out whether the ray has intersected with the sphere:
	hitInformation hitInfo = sphere.IsIntersection(ray);
	
	// Create the colour modifier for directional light:
	float coeff = -glm::dot(directionalLight.lightDirection, hitInfo.hitNormal);
	// If the ray hit the sphere, calculate sphere colour:
	glm::vec3 newColor{ 0.7f, 0.2f, 0.1f };
	newColor *= coeff;
	if (hitInfo.hasHit)
	{
		return newColor;
	}
	// If the ray didn't hit the sphere, return the background colour:
	newColor = { 0.f, 0.f, 0.f };
	return newColor;
}
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
	
	// If the ray hit the sphere, calculate sphere colour:
	glm::vec3 newColor = sphere.GetColor();

	if (hitInfo.hasHit)
	{
		// Create the colour modifier for directional light:
		float coeff = glm::dot(directionalLight.lightDirection, hitInfo.hitNormal);
		newColor *= coeff;
		return newColor;
	}
	// If the ray didn't hit the sphere, return the background colour:
	newColor = { 0.1f, 0.1f, 0.2f };
	return newColor;
}
#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"
#include "Ray.h"
#include "Entity.h"

struct hitInformation
{
	bool hasHit;
	glm::vec3 hitPosition;
	glm::vec3 hitNormal;
};
class Sphere : public Entity
{
private:
	float m_Radius;
	glm::vec3 m_Color;
public:
	// Constructors:
	Sphere();
	Sphere(float radius);

	// Getters:
	float GetRadius();
	glm::vec3 GetColor();
	// Setters:
	void SetRadius(float radius);
	// Initialise Function 
	void Init();

	// Function to detect if a ray intersects with the sphere:
	hitInformation Sphere::IsIntersection(Ray newRay);
};
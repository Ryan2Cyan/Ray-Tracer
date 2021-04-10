#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"
#include "Ray.h"
#include "Entity.h"

class Sphere : public Entity
{
private:
	float m_Radius;
public:
	// Constructors:
	Sphere();
	Sphere(float radius);

	// Getters:
	float GetRadius();
	// Setters:
	void SetRadius(float radius);
	// Initialise Function 
	void Init();

	// Function to detect if a ray intersects with the sphere:
	bool Sphere::IsIntersection(Ray newRay);
};
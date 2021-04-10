#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"
#include "Ray.h"

class RayTracer
{
private:
public:

	// Constructor:
	RayTracer();
	// Destructor
	~RayTracer();

	// This function takes in a Ray and returns a color:
	glm::vec3 GenerateColor(Ray ray);
};
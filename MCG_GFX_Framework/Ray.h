#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"

class Ray {
private:
	glm::vec3 m_Position; // Position of the ray on the near plane (where it starts).
	glm::vec3 m_Direction; // Position of the ray on the far plane (where it is going).
public:
	// Constructors:
	Ray();
	Ray(const glm::vec3& position, const glm::vec3& direction);

	// Getters:
	glm::vec3 GetPosition();
	glm::vec3 GetDirection();

	// Setters:
	void SetPosition(glm::vec3 position);
	void SetDirection(glm::vec3 direction);
};
#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"
#include "Ray.h"

// This is the Base class for most classes within the program,
// contains basic components (e.g. Position, Rotation, and Scale):
class Entity
{
protected:
	glm::vec3 m_Position; // Where the object is located in world space.
	glm::vec3 m_Rotation; // Rotation of the object in world space.
	glm::vec3 m_Scale; // Size of object.

public:
	// Constructors:
	Entity();
	Entity( glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	// Destructor:
	~Entity();

	// Getters:
	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	// Setters:
	void SetPosition(glm::vec3 position);
	void SetRotation(glm::vec3 rotation);
	void SetScale(glm::vec3 scale);
};

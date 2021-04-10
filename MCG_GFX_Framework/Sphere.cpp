#include "Sphere.h"

// Constructors:
Sphere::Sphere() : m_Radius(5), Entity() 
{
	Init();
}

Sphere::Sphere(float radius) : m_Radius(radius), Entity()
{
	Init();
}

// Getters:
float Sphere::GetRadius() { return m_Radius; }
// Setters:
void Sphere::SetRadius(float radius)
{
	m_Radius = radius;
}
// Initialise Function 
void Sphere::Init()
{
	glm::vec3 spherePos{ 10,20,0.4 };
	this->SetPosition(spherePos);
	glm::vec3 sphereRot{ 0,0,0 };
	this->SetRotation(sphereRot);
	glm::vec3 sphereScale{ 0,0,0 };
	this->SetScale(sphereScale);
}

// This function checks whether a ray has intersected with the sphere:
// if intersected, return true, otherwise return false:
bool Sphere::IsIntersection(Ray newRay)
{
	// Part 1: Find the value of t_ca:
	glm::vec3 L = this->GetPosition() - newRay.GetPosition();
	float t_ca = glm::dot(L, newRay.GetDirection());
	if (t_ca < 0) { return false; }

	// Part 2: Find the value of 'd':
	float d = glm::length(L - (t_ca * newRay.GetDirection()));

	if (d < 0 || d > this->GetRadius())
	{
		return false;
	}
	// Part 3: Find the value of 't_hc':
	float t_hc = glm::sqrt((m_Radius * m_Radius) - (d * d));

	// Part 4: Find the points of intersection:
	glm::vec3 intersectionPoint = ((newRay.GetPosition() + (t_ca - t_hc)) * newRay.GetDirection());

	// Part 5: Return the findings:
	return true;
}
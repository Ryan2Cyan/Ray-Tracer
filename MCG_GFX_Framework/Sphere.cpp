#include "Sphere.h"

// Constructors:
Sphere::Sphere() : m_Radius(1.f), m_Color({ 0.3f, 0.1f, 0.4f }), Entity()
{
	Init();
}

Sphere::Sphere(float radius) : m_Radius(radius), Entity()
{
	Init();
}

// Getters:
float Sphere::GetRadius() { return m_Radius; }
glm::vec3 Sphere::GetColor() { return m_Color; }
// Setters:
void Sphere::SetRadius(float radius)
{
	m_Radius = radius;
}
// Initialise Function 
void Sphere::Init()
{
	glm::vec3 spherePos{ 0, 0, -5 };
	this->SetPosition(spherePos);
	/*glm::vec3 sphereRot{ 0,0,0 };
	this->SetRotation(sphereRot);
	glm::vec3 sphereScale{ 0,3,3 };
	this->SetScale(sphereScale);*/
}

// This function checks whether a ray has intersected with the sphere:
// if intersected, return true, otherwise return false:
hitInformation Sphere::IsIntersection(Ray newRay)
{
	hitInformation newHitInfo
	{
		false,
		{0, 0, 0},
		{0, 0, 0}
	};

	// Part 1: Find the value of t_ca:
	glm::vec3 L = this->GetPosition() - newRay.GetPosition();
	float t_ca = glm::dot(L, newRay.GetDirection());
	if (t_ca < 0) { return newHitInfo; }

	// Part 2: Find the value of 'd':
	float d = glm::length(L - (t_ca * newRay.GetDirection()));

	if (d > this->GetRadius())
	{
		return newHitInfo;
	}
	

	// Part 3: Find the value of 't_hc':
	float t_hc = glm::sqrt((m_Radius * m_Radius) - (d * d));

	// Part 4: Find the points of intersection:
	glm::vec3 intersectionPoint = ((newRay.GetPosition() + (t_ca - t_hc)) * newRay.GetDirection());
	glm::vec3 intersectionPoint2 = ((newRay.GetPosition() + (t_ca + t_hc)) * newRay.GetDirection());
	newHitInfo.hitPosition = intersectionPoint;

	// Part 5: Find the surface normal:
	glm::vec3 surfaceNormal = glm::normalize(intersectionPoint - this->GetPosition());
	newHitInfo.hitNormal = surfaceNormal;

	// Part 6: Return the findings:
	newHitInfo.hasHit = true;
	return newHitInfo;
}
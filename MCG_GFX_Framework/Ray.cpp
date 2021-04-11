#include "Ray.h"


// Constructors:
Ray::Ray() {}
Ray::Ray(const glm::vec3& position, const glm::vec3& direction) : m_Position(position), m_Direction(direction) {}

// Getters:
glm::vec3 Ray::GetPosition() { return m_Position; }
glm::vec3 Ray::GetDirection() { return m_Direction; }

// Setters:
void Ray::SetPosition(glm::vec3 position) { m_Position = position; }
void Ray::SetDirection(glm::vec3 direction) { m_Direction = direction; };
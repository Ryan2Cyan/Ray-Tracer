#include "Entity.h"

// Constructors:
Entity::Entity() {}
Entity::Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale): m_Position(position), m_Rotation(rotation), m_Scale(scale) {}

// Destructor:
Entity::~Entity() {}

// Getters:
glm::vec3 Entity::GetPosition() { return m_Position; }
glm::vec3 Entity::GetRotation() { return m_Rotation; }
glm::vec3 Entity::GetScale() { return m_Scale; }

// Setters:
void Entity::SetPosition(glm::vec3 position) { m_Position = position; }
void Entity::SetRotation(glm::vec3 rotation) { m_Rotation = rotation; }
void Entity::SetScale(glm::vec3 scale) { m_Scale = scale; }
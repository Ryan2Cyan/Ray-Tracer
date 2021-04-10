#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"
#include "Ray.h"
#include "Entity.h"

class Camera : public Entity
{
private:
	float m_fovs; // This is the angle of view the camera will see, 90(degrees) usually normal.
	float m_AspectRatio; // (ScreenResolutionWidth / ScreenResolutionHeight).
	glm::vec2 m_ScreenResolution; // Width and Height of window (resolution).
	glm::mat4 m_MVPMatrix; // The ModelViewProjection matrix - Projection * View * Model.
	

public:
	
	// Constructor:
	Camera();
	Camera(float fovs, glm::vec2 screenResolution);
	// Destructor
	~Camera();

	// This function takes in a pair of coordinates and returns a Ray:
	Ray GenerateSingleRay(glm::vec2 pixelCoordinates);

	// This function creates an inverted modelviewprojection matrix on initialisation
	glm::mat4 CreateInvertedMVP();
};
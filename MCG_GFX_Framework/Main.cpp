
#include <cmath>
#include <iostream>
#include "Ray.h"
#include "Camera.h"
#include "RayTracer.h"
#include "Entity.h"
#include "Sphere.h"
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"


int main( int argc, char *argv[] )
{
	// Initialises SDL, Window, and Renderer - Returns true is successful.
	const glm::ivec2 screenResolution(640, 480);
	if( !MCG::Init(screenResolution) )
	{
		// Return false is unsuccessful.
		return -1;
	}
	
	// Init camera object:
	Camera camera(90.f, screenResolution);

	// Init Ray Tracer:
	RayTracer rayTracer;

	// Init Sphere 3D object:
	Sphere sphere;

	// Sets background to black:
	MCG::SetBackground(glm::vec3(0, 0, 0));

	float posX = 0; // x pixel coordinate.
	float posY = 0; // y pixel coordinate.

	// Loop through all pixels to get the x-position:
	for (float x = 0.f; x <= screenResolution.x - 1.f; x++)
	{
		posX = x;
		// Loop through all pixels again to get y-position:
		for (float y = 0.f; y <= screenResolution.y - 1.f; y++)
		{
			posY = y;
			glm::ivec2 pixelPosition{ posX, posY };
			// Generate a ray based on the pixel coordinates:
			Ray newRay = camera.GenerateSingleRay(pixelPosition);
			bool hasHit = sphere.IsIntersection(newRay);
			glm::vec3 red { 1,0,0 };
			if (hasHit)
			{
				// Draw pixel to the screen:
				MCG::DrawPixel(pixelPosition, red);
			}
			// Generate colour based on the ray:
			//glm::vec3 newColor = rayTracer.GenerateColor(newRay);
			//// Draw pixel to the screen:
			//MCG::DrawPixel(pixelPosition, newColor);
		}
	}



	
	
    
	



	// Draws a single pixel at the specified coordinates in the specified colour!
	/*MCG::DrawPixel( pixelPosition, pixelColour );*/

	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return MCG::ShowAndHold();


	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:
	/*
	
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		MCG::SetBackground( glm::vec3(0,0,0) );

		// Change our pixel's X coordinate according to time
		pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;
	*/

}

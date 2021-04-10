#include "Utility.h"

// This function normalises coordinates [0:1]:
float MapCoordinate(float input, float i_str, float i_end, float o_str, float o_end)
{
	// Minus the input's lower boundary:
	float e = input - i_str;
	// Convert the ranges
	float f = (o_end - o_str) / (i_end - i_str);
	// Multiply the input by the new range converter:
	float output = ((e * f) + o_str);

	return output;
}
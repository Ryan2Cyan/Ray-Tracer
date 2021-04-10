#pragma once
#include <iostream>
#include "SDL/SDL.h"
#include "MCG_GFX_Lib.h"

// Normalise the coordinates:
// This function normalises coordinates [0:1]:
float MapCoordinate(float input, float i_str, float i_end, float o_str, float o_end);
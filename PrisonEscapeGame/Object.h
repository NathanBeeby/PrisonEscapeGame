#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Object
{
private:

public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	Object() {}
	virtual ~Object() {}
#pragma endregion

#pragma region Public Variables
	// Public Variables
	std::stringstream ss;
	std::string s;
	float sizeX, sizeY, rot, x, y;
#pragma endregion

};
#endif

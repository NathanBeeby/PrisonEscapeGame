#pragma once
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
	// Constructor / Destructor
	Object();
	virtual ~Object();

	// Public Variables
	std::stringstream ss;
	std::string s;
	float sizeX, sizeY, rot, x, y;


};


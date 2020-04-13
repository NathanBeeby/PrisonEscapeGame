#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class MenuManager
{
private:


public:
	// Constructor / Destructor
	MenuManager();
	virtual ~MenuManager();

	// Public Variables
	sf::Font font;
	int selectedItemIndex;
	float height, width;

	// public functions
	virtual void Up() = 0;
	virtual void Down() = 0;

	// Accessors
	int GetPressedItem() { return selectedItemIndex; }
};


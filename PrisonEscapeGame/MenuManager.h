#pragma once
#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class MenuManager
{
private:


public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	MenuManager();
	virtual ~MenuManager();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	sf::Font font;
	int selectedItemIndex;
	float height, width;
#pragma endregion

#pragma region Public Functions
	// public functions
	virtual void Up() = 0;
	virtual void Down() = 0;
	int GetPressedItem() { return selectedItemIndex; }
#pragma endregion
};

#endif

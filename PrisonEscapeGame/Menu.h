#pragma once
#ifndef MENU_H
#define MENU_H
#include "MenuManager.h"
#define item_Number 3

class Menu : virtual public MenuManager
{
private:
#pragma region Private Variables
	// Private Variables
	sf::RectangleShape background, background2;
	sf::Texture backgroundTexture, backgroundTexture2;
	sf::Text MenuText[item_Number];
	int selectedItemIndex;
	float height, width;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
	void initFont();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor 
	Menu();
	virtual ~Menu();
#pragma endregion

#pragma region Public Variables
	// Public variables
	bool playPressed, optionsPressed, exitPressed;

	// Public Functions
	int GetPressedItem() { return selectedItemIndex; }
	void Up();
	void Down();
	void MouseHandler(sf::RenderWindow &window);
	void KeyHandler(sf::Keyboard::Key key);
	void render(sf::RenderTarget &target);
#pragma endregion
};

#endif
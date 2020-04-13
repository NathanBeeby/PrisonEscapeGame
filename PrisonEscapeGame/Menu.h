#pragma once
#include "MenuManager.h"
#define item_Number 3

class Menu
{
private:
	// Variables
	sf::Font font;
	sf::RectangleShape background, background2;
	sf::Texture backgroundTexture, backgroundTexture2;
	sf::Text MenuText[item_Number];
	int selectedItemIndex;
	float height, width;

	// Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
	void initFont();
public:
	// Constructor / Destructor 
	Menu();
	virtual ~Menu();

	// Accessors
	int GetPressedItem() { return selectedItemIndex; }

	// Public variables
	bool playPressed, optionsPressed, exitPressed;

	// Public Functions
	void Up();
	void Down();
	void MouseHandler(sf::RenderTarget &target);
	void KeyHandler(sf::Keyboard::Key key);
	void render(sf::RenderTarget &target);

};


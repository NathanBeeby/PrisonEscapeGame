#pragma once
#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H
#include "MenuManager.h"
#define Options_item_Number 4


class OptionsMenu : virtual public MenuManager
{
private:
#pragma region Private Variables
	// Private Variables
	sf::RectangleShape emptyMusic, emptySound, MusicBar, SoundBar, optionsBackground;
	sf::Texture optionsBackgroundTexture;
	sf::Text OptionsMenuText[Options_item_Number];

	int selectedItemIndex;
	float height, width;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initFont();
	void initText();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	OptionsMenu();
	virtual ~OptionsMenu();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	bool instrucPress, backPress;
	float Music, Sound;
#pragma endregion

#pragma region Public Functions
	// Public Functions
	int GetPressedItem() { return selectedItemIndex; }
	void Up();
	void Down();
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void instructionsPressed();
	void backPressed();
	void drawBars(sf::RenderTarget &target);
	void render(sf::RenderTarget &target);
#pragma endregion
};


#endif

#pragma once
#include "MenuManager.h"
#define Options_item_Number 4


class OptionsMenu : virtual public MenuManager
{
private:
	// Variables
	sf::RectangleShape emptyMusic, emptySound, MusicBar, SoundBar, optionsBackground;
	sf::Texture optionsBackgroundTexture;
	sf::Text OptionsMenuText[Options_item_Number];

	int selectedItemIndex;
	float height, width;

	// Initialization
	void initVariables();
	void initFont();
public:
	// Constructor / Destructor
	OptionsMenu();
	virtual ~OptionsMenu();

	// Public Variables
	bool instrucPress, backPress;
	float Music, Sound;

	void Up();
	void Down();

	// Accessors
	int GetPressedItem() { return selectedItemIndex; }

	// Public Functions
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void instructionsPressed();
	void backPressed();
	void drawBars(sf::RenderTarget &target);
	void render(sf::RenderTarget &target);
};



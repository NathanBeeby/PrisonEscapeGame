#pragma once
#include "MenuManager.h"
#define GameOver_Number 2
class GameOver : virtual public MenuManager // implementing this as a menu instead of an interface as I may want to add an SFML plug in for animation for the end game and parts of the game
{
private:
	// Variables
	sf::RectangleShape BackgroundShape;
	sf::Text ExitMenuText[GameOver_Number];
	sf::Text gameOverMessage;
	sf::Texture GameOverBackground;

	int selectedItemIndex;

	// Initialization 
	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
	void initFont();
public:
	// Constructor / Destructor
	GameOver();
	virtual ~GameOver();

	// Accessors
	int GetPressedItem() { return selectedItemIndex; }

	// Public Functions
	void Up();
	void Down();
	void MouseHandler(sf::RenderWindow &window);
	void KeyHandler(sf::Keyboard::Key key);
	void render(sf::RenderTarget &target, sf::View &view);
};







#pragma once
#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "MenuManager.h"
#define GameOver_Number 2
class GameOver : virtual public MenuManager // implementing this as a menu instead of an interface as I may want to add an SFML plug in for animation for the end game and parts of the game
{
private:
#pragma region Private Variables
	// Private Variables
	sf::RectangleShape BackgroundShape;
	sf::Text ExitMenuText[GameOver_Number];
	sf::Text gameOverMessage;
	sf::Texture GameOverBackground;

	int selectedItemIndex;
#pragma endregion

#pragma region Initialization
	// Initialization 
	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
	void initFont();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	GameOver();
	virtual ~GameOver();
#pragma endregion

#pragma region Public Functions
	// Public Functions
	int GetPressedItem() { return selectedItemIndex; }
	void Up();
	void Down();
	void MouseHandler(sf::RenderWindow &window);
	void KeyHandler(sf::Keyboard::Key key);
	void render(sf::RenderTarget &target, sf::View &view);
#pragma endregion
};
#endif

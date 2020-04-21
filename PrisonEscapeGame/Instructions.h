#pragma once
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "MenuManager.h"
#define Instructions_item_Number 6
enum InstructionsState { noState, keysState, craftState, skillState, routineState };
class Instructions : virtual public MenuManager
{
private:
#pragma region Private Varuables
	// Private Variables 
	sf::Font keyFont;
	sf::Text InstructionsMenuText[Instructions_item_Number];
	sf::Texture keysTexture, rotuineTexture, instructionsBackgroundTexture;
	sf::RectangleShape keyBox, routinesBox, instructionsBackground;
	std::vector<sf::Text> KeyInstruction;
	std::vector<sf::Text> first3Keys;
	std::vector<sf::Text> skillsInstruction;
	std::vector<sf::Text> skillsTitle;
	std::vector<sf::Text> routineInstruction;
	std::vector<sf::Text> routineSubText;
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
	Instructions();
	virtual ~Instructions();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	bool backPress, nextPress;
	InstructionsState state;
#pragma endregion

#pragma region Public Functions
	// Public Functions
	int GetPressedItem() { return selectedItemIndex; }
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);

	void backPressed();
	void Up();
	void Down();
	void KeysSubMenu(sf::RenderTarget &target);
	void CraftingSubMenu(sf::RenderTarget &target);
	void SkillsSubMenu(sf::RenderTarget &target);
	void RoutineSubMenu(sf::RenderTarget &target);
	void render(sf::RenderTarget &target);
#pragma endregion
};

#endif
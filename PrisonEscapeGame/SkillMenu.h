#pragma once
#ifndef SKILLMENU_H
#define SKILLMENU_H
#include "MenuManager.h"
#define skill_item_Number 7

class SkillMenu : virtual public MenuManager
{
private:
#pragma region Private Variables
	// Private Variables
	sf::Text SpendPoints;
	sf::RectangleShape StrBar, StaBar, EnduranceBar, ChaBar, KnoBar, skillsBackground;
	sf::RectangleShape Str, Sta, Endurance, Cha, Kno;
	sf::Texture skillsBackgroundTexture;

	int selectedItemIndex;
	float height, width;
	int startSkillPoints;

	sf::Text SkillMenuText[skill_item_Number];

	Player player;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initFont();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	SkillMenu();
	virtual ~SkillMenu();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	bool exitPress;
	bool gamePress;
#pragma endregion

#pragma region Public Functions
	//Public functions
	int GetPressedItem() { return selectedItemIndex; }
	void drawBars(sf::RenderTarget &target);


	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);

	void gamePressed();
	void exitPressed();

	void Up();
	void Down();

	void render(sf::RenderTarget &target);
#pragma endregion
};

#endif

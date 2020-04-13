#pragma once

#include "MenuManager.h"
#define skill_item_Number 7

class SkillMenu
{
private:
	sf::Font font;
	sf::Text SpendPoints;
	sf::RectangleShape StrBar, StaBar, EnduranceBar, ChaBar, KnoBar, skillsBackground;
	sf::RectangleShape Str, Sta, Endurance, Cha, Kno;
	sf::Texture skillsBackgroundTexture;

	int selectedItemIndex;
	float height, width;
	int startSkillPoints;


	sf::Text SkillMenuText[skill_item_Number];

	Player player;

	void initVariables();
	void initFont();

public:
	SkillMenu();
	virtual ~SkillMenu();

	bool exitPress;
	bool gamePress;

	// Accessors
	int GetPressedItem() { return selectedItemIndex; }

	//Public functions
	void drawBars(sf::RenderTarget &target);


	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);

	void gamePressed();
	void exitPressed();

	void Up();
	void Down();

	void render(sf::RenderTarget &target);
};


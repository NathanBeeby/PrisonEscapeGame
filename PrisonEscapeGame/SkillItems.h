#pragma once
#ifndef SKILLITEM_H
#define SKILLITEM_H
#include "Object.h"
#include "Player.h"

class SkillItems : virtual public Object
{
private:
#pragma region Private Variables
	//Private Variables
	Player player;

	sf::RectangleShape bikeWindow, strengthWindow, knowledgeWindow;
	std::vector<sf::Texture>  SkillItemTexture;
	std::string skillItemPath;
	std::string bikeStr;
	std::string weightsStr;
	std::string skillsfilename;
	std::string skillsFile;
	std::ifstream myInputFile;

	int skillItemNumber;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initSkills();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	SkillItems();
	virtual ~SkillItems();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	std::vector<sf::RectangleShape>  skillItems;
#pragma endregion

#pragma region Accessors
	// Accessors
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public fuctions
	void knowledgeIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);
	void strengthIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);
	void staminaIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion
};

#endif
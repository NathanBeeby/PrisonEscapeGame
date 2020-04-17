#pragma once
#include "Object.h"
#include "Player.h"


class SkillItems : virtual public Object
{
private:
	// Variables
	Player player;

	sf::RectangleShape bikeWindow, strengthWindow, knowledgeWindow;
	std::vector<sf::Texture>  SkillItemTexture;
	std::stringstream Sss;
	std::string Ss;
	std::string skillItemPath;
	std::string bikeStr;
	std::string weightsStr;
	std::string skillsfilename;
	std::string skillsFile;
	std::ifstream myInputFile;

	int skillItemNumber;
	float skillItemX, skillItemY; // position X and Y

								  // Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initSkills();
public:
	//Constructor / Destructor
	SkillItems();
	virtual ~SkillItems();

	// Public Variables
	std::vector<sf::RectangleShape>  skillItems;

	// Accessors
	const sf::FloatRect getBounds() const;

	//Public fuctions
	void knowledgeIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);
	void strengthIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);
	void staminaIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key);


	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


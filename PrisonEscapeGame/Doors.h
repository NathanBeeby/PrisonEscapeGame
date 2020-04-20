#pragma once
#include "Object.h"

class Doors : virtual public Object
{
private:
	// Variables
	std::vector<sf::Texture>  DoorTexture;
	std::string doorFile;
	std::string doorsPath;
	std::string doorsfilename;
	std::ifstream myInputFile;

	int doorsNumber;

	void initVariables();
	void initDoors();
public:
	//Constructor / Destructor
	Doors();
	virtual ~Doors();

	// Public Variables
	std::vector<sf::RectangleShape>  doors;

	//Accessor
	const sf::FloatRect getBounds() const;

	//Public functions
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


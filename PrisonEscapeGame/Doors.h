#pragma once
#ifndef DOOR_H
#define DOOR_H
#include "Object.h"

class Doors : virtual public Object
{
private:
#pragma region Private Variables
	// Private Variables
	std::vector<sf::Texture>  DoorTexture;
	std::string doorFile;
	std::string doorsPath;
	std::string doorsfilename;
	std::ifstream myInputFile;

	int doorsNumber;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initDoors();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	Doors();
	virtual ~Doors();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	std::vector<sf::RectangleShape>  doors;
#pragma endregion

#pragma region Accessors
	//Accessor
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public functions
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion
};

#endif

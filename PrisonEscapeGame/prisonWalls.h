#pragma once
#ifndef PRISONWALL_H
#define PRISONWALL_H
#include "Object.h"

class prisonWalls : virtual public Object
{
private:
#pragma region Private Variables
	//Private Variables
	std::ifstream myInputFile;
	std::string filename;
	std::string wallFile;
	sf::RectangleShape wallBlock;
	sf::Texture wallTexture;
	sf::Vector2i pos;

	int numWallsToRead;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initTextures();
	void initVariables();
	void initWalls();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor 
	prisonWalls();
	virtual ~prisonWalls();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	std::vector<sf::RectangleShape>  Walls;
#pragma endregion

#pragma region Accessors
	//Accessors
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public functions
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion

};
#endif


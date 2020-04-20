#pragma once
#include "Object.h"

class prisonWalls : virtual public Object
{
private:
	//Variables
	std::ifstream myInputFile;
	std::string filename;
	std::string wallFile;
	sf::RectangleShape wallBlock;
	sf::Texture wallTexture;
	sf::Vector2i pos;

	int numWallsToRead;

	// Initialization
	void initTextures();
	void initVariables();
	void initWalls();
public:
	//Constructor / Destructor 
	prisonWalls();
	virtual ~prisonWalls();

	// Public Variables
	std::vector<sf::RectangleShape>  Walls;

	//Accessors
	const sf::FloatRect getBounds() const;

	//Public functions
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);

};


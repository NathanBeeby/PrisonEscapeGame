#pragma once
#ifndef FURNITURE_H
#define FURNITURE_H
#include "Object.h"

// 1 x 1 Objects - Sink and toilet, office chair, locker, shower head
// 1 x 5 Objects - Caffeteria Bench, 
// 2 x 1 Objects - Office Desk, Cell Block TV, Sofa, Footlocker, prison bed
// 2 x 2 Objects - Medical Bed
// 2 x 5 Objects - Serving Table, Cafeteria Table
class Furniture : virtual public Object
{
private:
#pragma region Private Variables
	// Private Variables
	std::vector<sf::Texture> FurnitureTexture;
	std::ifstream myInputFile;
	std::string furniturefilename;
	std::string furniturePath;
	std::string furnitureFile;

	int  furnitureNumber;
#pragma endregion
	
#pragma region Initialization
	// Initialization
	void initVariables();
	void initFurniture();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	Furniture();
	virtual ~Furniture();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	std::vector<sf::RectangleShape>  furniture;
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

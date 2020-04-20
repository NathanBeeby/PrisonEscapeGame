#pragma once
#include "Object.h"

// 1 x 1 Objects - Sink and toilet, office chair, locker, shower head
// 1 x 5 Objects - Caffeteria Bench, 
// 2 x 1 Objects - Office Desk, Cell Block TV, Sofa, Footlocker, prison bed
// 2 x 2 Objects - Medical Bed
// 2 x 5 Objects - Serving Table, Cafeteria Table
class Furniture : virtual public Object
{
private:
	// Variables
	std::vector<sf::Texture> FurnitureTexture;
	std::ifstream myInputFile;
	std::string furniturefilename;
	std::string furniturePath;
	std::string furnitureFile;

	int  furnitureNumber;

									  // Initialization
	void initVariables();
	void initFurniture();
public:
	// Constructor / Destructor
	Furniture();
	virtual ~Furniture();

	// Public Variables
	std::vector<sf::RectangleShape>  furniture;

	//Accessor
	const sf::FloatRect getBounds() const;

	//Public functions
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


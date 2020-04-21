#include "Furniture.h"

#pragma region Initialization
// Initialization
void Furniture::initVariables()
{
	this->furnitureFile = "../assets/text_assets/Furniture.txt";
	this->furniturefilename = "file.txt";
	this->x = 0;
	this->y = 0;
}

void Furniture::initFurniture()
{
	this->myInputFile.open(this->furnitureFile, std::ios_base::in);
	if (this->myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(this->myInputFile, s);
		ss.str(s);
		ss.ignore(21);
		ss >> furnitureNumber;

		furniture.resize(furnitureNumber);
		FurnitureTexture.resize(furnitureNumber);

		ss.clear();

		for (int i = 0; i < furnitureNumber; i++)
		{
			//NAME AND NUMBER
			//POSITION
			//SIZE
			//TEXTURE
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> x >> y;
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> sizeX >> sizeY;
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> furniturePath;
			ss.clear();
			ss.str(s);



			sf::Vector2i pos(x, y);

			sf::Vector2f size(sizeX, sizeY);


			if (!FurnitureTexture[i].loadFromFile(furniturePath)) {
				std::cout << "Load fail Error on FurnitureTexture" << std::endl;
				system("pause");
			}

			furniture[i].setPosition(pos.x, pos.y);
			furniture[i].setSize(sf::Vector2f(size.x, size.y));
			furniture[i].setTexture(&FurnitureTexture[i]);
		}
	}
}
#pragma endregion

#pragma region Constructor / Destructor
//Constructor / Destructor
Furniture::Furniture()
{
	this->initVariables();
	this->initFurniture();
}

Furniture::~Furniture()
{

}
#pragma endregion

#pragma region Accessors
// accessors 
const sf::FloatRect Furniture::getBounds() const
{
	for (int i = 0; i < this->furniture.size(); i++) {
		return this->furniture[i].getGlobalBounds();
	}
}
#pragma endregion

#pragma region Public Functions
// Public Functions
void Furniture::update(sf::Time deltaTime)
{

}

void Furniture::render(sf::RenderTarget& target)
{
	for (int i = 0; i < furnitureNumber; i++) {
		target.draw(furniture[i]);
	}
}
#pragma endregion

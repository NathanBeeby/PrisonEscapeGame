#include "Furniture.h"

// Initialization
void Furniture::initVariables()
{
	this->furnitureFile = "../assets/text_assets/Furniture.txt";
	this->furniturefilename = "file.txt";
	this->sizeX = 0;
	this->sizeY = 0;
}

void Furniture::initFurniture()
{
	this->myInputFile.open(this->furnitureFile, std::ios_base::in);
	if (this->myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(this->myInputFile, fs);
		fss.str(fs);
		fss.ignore(21);
		fss >> furnitureNumber;

		furniture.resize(furnitureNumber);
		FurnitureTexture.resize(furnitureNumber);

		fss.clear();

		for (int i = 0; i < furnitureNumber; i++)
		{
			//NAME AND NUMBER
			//POSITION
			//SIZE
			//TEXTURE
			getline(myInputFile, fs);
			fss.clear();
			fss.str(fs);
			getline(myInputFile, fs);
			fss.clear();
			fss.str(fs);
			fss >> furnX >> furnY;
			getline(myInputFile, fs);
			fss.clear();
			fss.str(fs);
			fss >> sizeX >> sizeY;
			getline(myInputFile, fs);
			fss.clear();
			fss.str(fs);
			fss >> furniturePath;
			fss.clear();
			fss.str(fs);



			sf::Vector2i pos(furnX, furnY);

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

//Constructor / Destructor
Furniture::Furniture()
{
	this->initVariables();
	this->initFurniture();
}

Furniture::~Furniture()
{

}

// accessors 
const sf::FloatRect Furniture::getBounds() const
{
	for (int i = 0; i < this->furniture.size(); i++) {
		return this->furniture[i].getGlobalBounds();
	}
}

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


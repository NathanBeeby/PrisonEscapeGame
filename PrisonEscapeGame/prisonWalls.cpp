#include "prisonWalls.h"

// Initialization
void prisonWalls::initTextures()
{
	if (!this->wallTexture.loadFromFile("../assets/image_assets/wall.png")) {
		std::cout << "Load fail Error on wallTexture" << std::endl;
		system("pause");
	}
}

void prisonWalls::initVariables()
{
	this->filename = "file.txt";
	this->wallFile = "../assets/text_assets/Walls.txt";
}

void prisonWalls::initWalls()
{
	//setting texture and size
	myInputFile.open(wallFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, s);
		ss.str(s);
		ss.ignore(17);
		ss >> numWallsToRead;

		Walls.resize(numWallsToRead);


		ss.clear();

		for (int i = 0; i < numWallsToRead; i++)
		{
			getline(myInputFile, s);
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> x >> y;

			sf::Vector2f pos(x, y);
			sf::Vector2f size(64, 64);
			Walls[i].setSize(size);
			Walls[i].setTexture(&wallTexture);
			Walls[i].setPosition(pos.x, pos.y);



		}
	}
}

// Constructor / Destructor
prisonWalls::prisonWalls()
{
	this->initVariables();
	this->initTextures();
	this->initWalls();
}

prisonWalls::~prisonWalls()
{

}

// Accessors
const sf::FloatRect prisonWalls::getBounds() const
{
	for (int i = 0; i < this->Walls.size(); i++) {
		return this->Walls[i].getGlobalBounds();
	}
}

// Public Functions
void prisonWalls::update(sf::Time deltaTime)
{

}

void prisonWalls::render(sf::RenderTarget & target)
{
	for (int i = 0; i < numWallsToRead; i++) {
		target.draw(Walls[i]);
	}
}

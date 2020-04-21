#include "Doors.h"

#pragma region Initialization
// Initialization
void Doors::initVariables()
{
	this->doorsfilename = "file.txt";
	this->doorFile = "../assets/text_assets/Doors.txt";
	this->sizeX = 0;
	this->sizeY = 0;
	this->rot = 0;
}

void Doors::initDoors()
{
	this->myInputFile.open(this->doorFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(this->myInputFile, s);
		this->ss.str(s);
		this->ss.ignore(21);
		this->ss >> doorsNumber;
		this->doors.resize(doorsNumber);
		this->DoorTexture.resize(doorsNumber);

		this->ss.clear();

		for (int i = 0; i < this->doorsNumber; i++)
		{
			//NAME AND NUMBER
			//POSITION
			//SIZE
			//ROTATION
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
			ss >> rot;
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> doorsPath;

			sf::Vector2i pos(x, y);
			sf::Vector2f size(sizeX, sizeY);


			if (!DoorTexture[i].loadFromFile(doorsPath)) {
				std::cout << "Load fail Error on DoorsTexture" << std::endl;
				system("pause");
			}


			doors[i].setPosition(pos.x, pos.y);
			doors[i].setOrigin(size / 2.0f);
			doors[i].setSize(size);
			doors[i].setRotation(rot);
			doors[i].setTexture(&DoorTexture[i]);
		}
	}
}
#pragma endregion

#pragma region Constructor / Destructor
// Constructor / Destructor
Doors::Doors()
{
	this->initVariables();
	this->initDoors();
}

Doors::~Doors()
{

}
#pragma endregion

#pragma region Accessors
// Accessors
const sf::FloatRect Doors::getBounds() const
{
	for (int i = 0; i < this->doors.size(); i++) {
		return this->doors[i].getGlobalBounds();
	}
}
#pragma endregion

#pragma region Public Functions
// Public Functions
void Doors::update(sf::Time deltaTime)
{

}

void Doors::render(sf::RenderTarget & target)
{
	for (int i = 0; i < doors.size(); i++) {
		target.draw(doors[i]);
	}
}
#pragma endregion


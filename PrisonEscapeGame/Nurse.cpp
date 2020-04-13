#include "Nurse.h"

// Initialization
void Nurse::initVariables()
{
	// Integer Variables
	this->moveSpeed = 2;
	this->x = 0;
	this->y = 0;
	this->time = 0;
	this->move = 0;
	this->health = 100;
	this->anim.x = 1;
	this->anim.y = Down;
	this->lastPosition = Down;

	// Float Variables
	this->Speed = 7.5;

	// Boolean Variables
	this->attacked = false;

	// String Variables
	this->spritefilename = "file.txt";
	this->spriteFile = "../assets/text_assets/nurses.txt";
}

void Nurse::initTexture()
{

}

void Nurse::initSprite()
{
	std::ifstream myInputFile;
	myInputFile.open(spriteFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, s);
		ss.str(s);
		ss.ignore(18);
		ss >> number;
		sprites.resize(number);
		spriteTexture.resize(number);

		ss.clear();

		for (int i = 0; i < number; i++)
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
			ss >> this->x >> this->y;
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> this->sizeX >> this->sizeY;
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> path;

			sf::Vector2i pos(this->x, this->y);
			sf::Vector2f size(this->sizeX, this->sizeY);

			if (!spriteTexture[i].loadFromFile(path)) {
				std::cout << "Load fail Error on guardTexture" << std::endl;
				system("pause");
			}

			sprites[i].setPosition(pos.x, pos.y);
			sprites[i].setOrigin(size / 2.0f);
			sprites[i].setSize(size);
			sprites[i].setTexture(&spriteTexture[i]);
		}
	}
}

// Constructor / Destructor
Nurse::Nurse()
{
	this->initVariables();
	this->initSprite();
	this->initTexture();
}

Nurse::~Nurse()
{
}

// Accessors
const sf::Vector2f & Nurse::getPos() const
{
	for (int i = 0; i < sprites.size(); i++) {
		return sprites[i].getPosition();
	}
}

const sf::FloatRect Nurse::getBounds() const
{
	for (int i = 0; i < this->sprites.size(); i++) {
		return this->sprites[i].getGlobalBounds();
	}
}

// Public Functions
void Nurse::drawNurse(sf::RenderTarget& target) {
	NurseState::nurseIDLE;
	vel.x = 0;
	vel.y = 0;

	//std::string SecondsString = std::to_string(nurseTime);
	//sf::Time TimeElapsed = nurseClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	//sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second

	//if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
	//	nurseTime++;
	//	nurseClock.restart();
	//	//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
	//	std::cout << nurseTime << std::endl;
	//}
	/*
	if (NurseState::nurseIDLE) {
	if (nurseTime >= 5) {
	NurseMove = rand() % 6; // a random number generator between 1 and 8
	nurseTime = 0;
	}



	if (NurseMove == 1) {
	if (nurseSprite.getPosition().y > 64) {
	vel.y -= moveSpeed;
	NurseAnim.y = Up;
	lastNursePosition = Up;
	}
	}
	else if (NurseMove == 2) {
	if (nurseSprite.getPosition().x > 64) {
	vel.x -= moveSpeed;
	NurseAnim.y = Left;
	lastNursePosition = Left;
	}
	}
	else if (NurseMove == 3) {
	if (nurseSprite.getPosition().y < 4416) {
	vel.y += moveSpeed;
	NurseAnim.y = Down;
	lastNursePosition = Down;
	}
	}
	else if (NurseMove == 4) {
	if (nurseSprite.getPosition().x < 2752) {
	vel.x += moveSpeed;
	NurseAnim.y = Right;
	lastNursePosition = Right;
	}
	}
	else {
	NurseAnim.y = Idle;
	lastNursePosition = Idle;
	}

	}
	*/

	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].move(vel.x, vel.y);

		anim.x++;
		for (int i = 0; i < spriteTexture.size(); i++) {
			if (anim.x * 32 >= spriteTexture[i].getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
				anim.x = 0;
			}
		}
		sprites[i].setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

		target.draw(sprites[i]);
	}
}

void Nurse::NurseState() {

}

void Nurse::onCollision()
{

}

void Nurse::update(sf::Time deltaTime)
{

}

void Nurse::render(sf::RenderTarget& target)
{
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].move(vel.x, vel.y);
		anim.x++;
		for (int i = 0; i < spriteTexture.size(); i++) {
			if (anim.x * 32 >= spriteTexture[i].getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
				anim.x = 0;
			}
		}

		sprites[i].setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

		target.draw(sprites[i]);
	}
}


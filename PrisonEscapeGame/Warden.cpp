#include "Warden.h"

#pragma region Initialization
// Initialization
void Warden::initVariables()
{
	// String Variables
	this->spritefilename = "file.txt";
	this->spriteFile = "../assets/text_assets/warden.txt";

	// Boolean Variables
	this->attacked = false;

	// Integer Variables
	this->time = 0;
	this->move = 0;
	this->health = 500;
	this->moveSpeed = 2;
	this->anim.x = 1;
	this->anim.y = Down;
	this->lastPosition = Down;
}

void Warden::initSprite()
{
	myInputFile.open(spriteFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, s);
		ss.str(s);
		ss.ignore(18);
		ss >> number;
		sprites.resize(number);
		this->spriteTexture.resize(number);

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

void Warden::initTextures()
{
}
#pragma endregion

#pragma region Constructor / Destructor
// Constructor / Destructor
Warden::Warden()
{
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Warden::~Warden()
{
}
#pragma endregion

#pragma region Accessors
// Accessors
const sf::Vector2f & Warden::getPos() const
{
	for (int i = 0; i < sprites.size(); i++) {
		return sprites[i].getPosition();
	}
}

const sf::FloatRect Warden::getBounds() const
{
	for (int i = 0; i < this->sprites.size(); i++) {
		return this->sprites[i].getGlobalBounds();
	}
}
#pragma endregion

#pragma region Public Functions
// Public Functions
void Warden::updateStateChange(sf::Time deltaTime) {

	wardenState::wardenIDLE; // setting the player defaultly to IDLE
	vel.x = 0;
	vel.y = 0;

	//std::string SecondsString = std::to_string(WardenTime);
	//sf::Time TimeElapsed = WardenClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	//sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	//if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
	//	WardenTime++;
	//	WardenClock.restart();

	//	std::cout << WardenTime << std::endl;
	//}
	/*
	if (wardenState::wardenIDLE) {
	if (WardenTime >= 2) {
	WardenMove = rand() % 6; // a random number generator between 1 and 8
	WardenTime = 0;
	}

	if (WardenMove == 1) {
	if (WardenSprite.getPosition().y < 4352) {
	vel.y -= moveSpeed;
	WardenAnim.y = Up;
	lastWardenPosition = Up;
	}
	}
	else if (WardenMove == 2) {
	if (WardenSprite.getPosition().x > 64) {
	vel.x -= moveSpeed;
	WardenAnim.y = Left;
	lastWardenPosition = Left;
	}
	}
	else if (WardenMove == 3) {
	if (WardenSprite.getPosition().y > 64) {
	vel.y += moveSpeed;
	WardenAnim.y = Down;
	lastWardenPosition = Down;
	}
	}
	else if (WardenMove == 4) { // Right Facing warden
	if (WardenSprite.getPosition().x < 2752) {
	vel.x += moveSpeed;
	WardenAnim.y = Right;
	lastWardenPosition = Right;
	}
	}
	else {
	WardenAnim.y = Idle;
	lastWardenPosition = Idle;
	}
	}*/

}

void Warden::WardenState() {

}

void Warden::onCollision()
{

}

void Warden::update(sf::Time deltaTime)
{

}

void Warden::render(sf::RenderTarget & target)
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
#pragma endregion
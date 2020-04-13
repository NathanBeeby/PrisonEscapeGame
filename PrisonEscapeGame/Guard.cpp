#include "Guard.h"

//Initialization
void Guard::initVariables()
{
	// String Variables
	this->spriteFile = "../assets/text_assets/guards.txt";
	this->spritefilename = "file.txt";

	// Boolean Variables
	this->attacked = false;

	// Integer Variables
	this->time = 0;
	this->health = 200;
	this->number = 0;
	this->x = 0;
	this->y = 0;
	this->moveSpeed = 3;
	this->move = 0;
	this->anim.x = 1;
	this->anim.y = Down;
	this->lastPosition = Down;
}

void Guard::initTextures()
{
	myInputFile.open(this->spriteFile, std::ios_base::in);
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

			if (!this->spriteTexture[i].loadFromFile(path)) {
				std::cout << "Load fail Error on guardTexture" << i << std::endl;
				system("pause");
			}

			sprites[i].setPosition(pos.x, pos.y);
			sprites[i].setOrigin(size / 2.0f);
			sprites[i].setSize(size);
			sprites[i].setTexture(&this->spriteTexture[i]);
		}
	}
}

void Guard::initSprites()
{


}

// Constructor / Destructor
Guard::Guard()
{
	this->initVariables();
	this->initSprites();
	this->initTextures();
}

Guard::~Guard()
{

}

// Accessors
const sf::Vector2f & Guard::getPos() const
{
	for (int i = 0; i < sprites.size(); i++) {
		return sprites[i].getPosition();
	}
}

const sf::FloatRect Guard::getBounds() const
{
	for (int i = 0; i < this->sprites.size(); i++) {
		return this->sprites[i].getGlobalBounds();
	}
}

// Public Functions
void Guard::drawGuard(sf::RenderTarget& target) {
	GState == guardIDLE; // setting the player defaultly to IDLE
	vel.x = 0;
	vel.y = 0;

	//std::string SecondsString = std::to_string(guardTime);
	//sf::Time TimeElapsed = GuardClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	//sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second
	ParticleSystem particles(500);

	//if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
	//	guardTime++;
	//	GuardClock.restart();
	//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
	std::cout << time << std::endl;
	/*}*/
	/*
	if (GState == guardIDLE) {
	if (guardTime >= 2) {
	guardMove = rand() % 6; // a random number generator between 1 and 8
	guardTime = 0;
	}

	if (guardMove == 1) {
	if (guardSprite.getPosition().y < 4352) {
	vel.y -= moveSpeed;
	GuardAnim.y = Up;
	lastGuardPosition = Up;
	}
	}
	else if (guardMove == 2) {
	if (guardSprite.getPosition().x > 64) {
	vel.x -= moveSpeed;
	GuardAnim.y = Left;
	lastGuardPosition = Left;
	}
	}
	else if (guardMove == 3) {
	if (guardSprite.getPosition().y > 64) {
	vel.y += moveSpeed;
	GuardAnim.y = Down;
	lastGuardPosition = Down;
	}
	}
	else if (guardMove == 4) { // Right Facing Prisoner
	if (guardSprite.getPosition().x < 2752) {
	vel.x += moveSpeed;
	GuardAnim.y = Right;
	lastGuardPosition = Right;
	}
	}
	else {
	GuardAnim.y = Idle;
	lastGuardPosition = Idle;
	}
	}
	*/
}

void Guard::guardState() {

}

void Guard::update(sf::Time deltaTime)
{

}

void Guard::render(sf::RenderTarget & target)
{
	for (int i = 0; i < sprites.size(); i++) {
		target.draw(sprites[i]);
	}
}


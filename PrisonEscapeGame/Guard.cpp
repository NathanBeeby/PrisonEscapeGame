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

	// SFML Variables
	this->chowWaypoint = sf::Vector2i(90, 1620);
	this->workWaypoint = sf::Vector2i(1680, 2520);
	this->showerWaypoint = sf::Vector2i(64, 64);
	this->yardWaypoint = sf::Vector2i(90, 2520);
	this->freeWaypoint = sf::Vector2i(1600, 1600);
}

void Guard::initTextures()
{
}

void Guard::initSprites()
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
			guardHealth.push_back(100); // giving each of the enemies 100 health to begin with

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

// Constructor / Destructor
Guard::Guard()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}

Guard::~Guard()
{

}

// Accessors
const sf::Vector2f & Guard::getPos() const
{
	for (int i = 0; i < sprites.size(); i++) {
		return this->sprites[i].getPosition();
	}
}

const sf::FloatRect Guard::getBounds() const
{
	for (int i = 0; i < this->sprites.size(); i++) {
		return this->sprites[i].getGlobalBounds();
	}
}

// Public Functions
void Guard::playerAttacked(GUI & gui, Player & player)
{
	if (player.getBounds().intersects(sprites[guardNumAngry].getGlobalBounds())) {
		if (this->player.getArmour() >= 1) {
			this->player.removeArmour(1);
		}
		if (this->player.getArmour() <= 0) {
			//gui.healthBar -= 5; // losing health from enemy attacking
			this->player.removeHP(5);
		}
		//std::cout << "Prisoner Attacking" << std::endl;
	}
}

void Guard::updateStateChange(sf::Time deltaTime)
{
	if (GState == guardIDLE) { // if the prisoner state is idle, the prisoners will wander by calling the wandering function
		wandering();
		//	std::cout << "Prisoner State == Wandering" << std::endl;
	}
	if (GState == guardAngry) { // if the prisoner state is set to angry, the function will be called to make the prisoner attack
		guardAttacked(player);
		//	std::cout << "Prisoner State == Attacking" << std::endl;
	}
	if (GState == guardPathFollow) { // if the prisoner is not angry or idle, the prisoner should be checking to follow the path
		pathFollowing();
		//	std::cout << "Prisoner State == PathFollowing" << std::endl;
	}

	if (Attacked == true) {
		GState = guardAngry;
	}
}

void Guard::guardState() {

}

void Guard::wandering()
{
	if (time >= 5) { // if the prisonTime exceeds this, move the prisoner, update the random numbers for direction and prisoner selected
		guardRand = rand() % 4 + 1; // choosing a direction, either 1, 2, 3 or 4 to move in 
									 //prisonChoice = rand() % prisoners.size(); // generating a random number, depending on how many prisoners there are, and choosing which prisoner to move
									 //	std::cout << "Random prisoner choice: " << prisonChoice << std::endl;
		time = 0; //setting prison Time back to 0
	}

	if (guardRand == 1) {
		//	std::cout << "Prison Direction choice left(1)" << std::endl;

		this->vel[guardChoice].x = -moveSpeed;
		anim.y = Left;
		lastGuardPosition[guardChoice] = Left;

	}
	if (guardRand == 2) {
		//	std::cout << "Prison Direction choice right(2)" << std::endl;
		vel[guardChoice].x = moveSpeed;
		anim.y = Right;
		lastGuardPosition[guardChoice] = Right;

	}
	if (guardRand == 3) {
		//	std::cout << "Prison Direction choice up(3)" << std::endl;
		vel[guardChoice].y = -moveSpeed;
		anim.y = Up;
		lastGuardPosition[guardChoice] = Up;

	}
	if (guardRand == 4) {
		//	std::cout << "Prison Direction choice down(4)" << std::endl;
		vel[guardChoice].y = moveSpeed;
		anim.y = Down;
		lastGuardPosition[guardChoice] = Down;

	}

	sprites[guardChoice].move(vel[guardChoice].x, vel[guardChoice].y);
	lastVelocity[guardChoice] = sf::Vector2f(-vel[guardChoice].x, -vel[guardChoice].y);



	if (wayPoint.x != 0 && wayPoint.y != 0) { // if the waypoint updates (not bedTime, follow the path)
											  //std::cout << "State change to path following" << std::endl;
		GState = guardPathFollow;
	}
}

void Guard::pathFollowing()
{
	std::cout << "WayPoint, X: " << wayPoint.x << ", Y: " << wayPoint.y << std::endl;

	if (wayPoint.x != 0 || wayPoint.y != 0) {
		for (int i = 0; i < sprites.size(); i++) {
			//std::cout << "Prisoner Position: " << prisoners[i].getPosition().x << ", Y: " << prisoners[i].getPosition().y << std::endl;
			if (sprites[i].getPosition().x < wayPoint.x + (i * 32)) { // if the prisoners x position is less than the waypoints x position, move positively in the X direction
				vel[i].x = moveSpeed;
				anim.y = Right;
				lastGuardPosition[i] = Right;
			}
			if (sprites[i].getPosition().x > wayPoint.x) {
				vel[i].x = -moveSpeed;
				anim.y = Left;
				lastGuardPosition[i] = Left;
			}


			if (sprites[i].getPosition().y > wayPoint.y) { // if the prisoners Y position is less than the waypoints Y position, move positively in the Y direction
				vel[i].y = -moveSpeed;
				anim.y = Up;
				lastGuardPosition[i] = Up;
			}
			if (sprites[i].getPosition().y < wayPoint.y) {
				vel[i].y = moveSpeed;
				anim.y = Down;
				lastGuardPosition[i] = Down;
			}
			if (sprites[i].getPosition().x == wayPoint.x + (i * 32) && sprites[i].getPosition().y == wayPoint.y) {
				GState = guardIDLE;
			}
			sprites[i].move(vel[i].x, vel[i].y);
			lastVelocity[i] = sf::Vector2f(-vel[i].x, -vel[i].y);
		}
	}
}

void Guard::guardAttacked(Player & player)
{
	if (sprites[guardNumAngry].getPosition().x >= player.getPos().x) {
		vel[guardNumAngry].x = -moveSpeed;
		anim.y = Left;
		lastGuardPosition[guardNumAngry] = Left;
	}
	if (sprites[guardNumAngry].getPosition().x <= player.getPos().x + 32) {
		vel[guardNumAngry].x = moveSpeed;
		anim.y = Right;
		lastGuardPosition[guardNumAngry] = Right;
	}
	if (sprites[guardNumAngry].getPosition().y >= player.getPos().y) {
		vel[guardNumAngry].y = -moveSpeed;
		this->anim.y = Up;
		lastGuardPosition[guardNumAngry] = Up;
	}
	if (sprites[guardNumAngry].getPosition().y <= player.getPos().y + 32) {
		vel[guardNumAngry].y = moveSpeed;
		anim.y = Down;
		lastGuardPosition[guardNumAngry] = Down;
	}
	//std::cout << "Prisoner Position X: " << prisoners[PrisonNumAngry].getPosition().x << " , Y: " << prisoners[PrisonNumAngry].getPosition().y << std::endl;
	//std::cout << "Player Position X: " << player.getPosition().x << " , Y: " << player.getPosition().y << std::endl;
	sprites[guardNumAngry].move(vel[guardNumAngry].x, vel[guardNumAngry].y); // making the prisoner follow the player 
	lastVelocity[guardNumAngry] = sf::Vector2f(-vel[guardNumAngry].x, -vel[guardNumAngry].y);




	//If the prisoner is within a 300 pixel range to the player, the prisoner can follow the player, else go back to wandering - add reduction to prisoner rep later
	if (sprites[guardNumAngry].getPosition().x < player.getPos().x - 192 || sprites[guardNumAngry].getPosition().x > player.getPos().x + 192 &&
		sprites[guardNumAngry].getPosition().y < player.getPos().y - 192 || sprites[guardNumAngry].getPosition().y > player.getPos().y + 192) {
		//	std::cout << "Player out of range" << std::endl;
		Attacked = false;
		GState = guardIDLE;
	}

}

void Guard::guardAttackedChoice(int & guard)
{
	guardNumAngry = guard;
}

void Guard::update(sf::Time deltaTime)
{
	this->updateStateChange(deltaTime);
}

void Guard::render(sf::RenderTarget & target)
{
	for (int i = 0; i < sprites.size(); i++) {
		if (guardHealth[i] <= 0) { // each prisoner has a health amount, if it reaches 0 the state should change to a dead state, the players XP should increase and to remove the item from the vector
			std::cout << "Prisoner " << i << " has died" << std::endl;
			GState = guardDead;
			//hud.XPcount += 30;
			guardHealth.erase(guardHealth.begin() + i); // erasing the prisoner from the vector
			sprites.erase(sprites.begin() + i); // removing the prisoner from the vector - Causes error with collision and other implementations as theres 1 less prisoner

		}
		for (int j = 0; j < spriteTexture.size(); j++) {
			anim.x++;
			if (anim.x * 32 >= spriteTexture[j].getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
				anim.x = 0;
			}
		}
		sprites[i].setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

		target.draw(sprites[i]);
	}
}


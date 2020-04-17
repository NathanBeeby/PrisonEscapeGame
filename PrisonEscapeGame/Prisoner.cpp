#include "Prisoner.h"

// Initialization
void Prisoner::initVariables()
{
	// String Variables
	this->spriteFile = "../assets/text_assets/prisoners.txt";
	this->spritefilename = "file.txt";

	// Boolean Variables
	this->prisonerAttacked = false;

	// Integer Variables
	this->move = 0;
	this->time = 0;
	this->health = 100;
	this->prisonChoice = 0;
	this->anim.x = 1;
	this->moveSpeed = 2;
	this->anim.y = Down;
	// Enumeration Variables
	this->PState = IDLE;

	// SFML Variables
	this->chowWaypoint = sf::Vector2i(90, 1620);
	this->workWaypoint = sf::Vector2i(1680, 2520);
	this->showerWaypoint = sf::Vector2i(64, 64);
	this->yardWaypoint = sf::Vector2i(90, 2520);
	this->freeWaypoint = sf::Vector2i(1600, 1600);
}

void Prisoner::initTextures()
{

}

void Prisoner::initSprite()
{
	myInputFile.open(spriteFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, s);
		ss.str(s);
		ss.ignore(21);
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
			prisonerHealth.push_back(100); // giving each of the enemies 100 health to begin with

			if (!spriteTexture[i].loadFromFile(path)) {
				std::cout << "Load fail Error on prisonerTexture" << std::endl;
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
Prisoner::Prisoner()
{
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Prisoner::~Prisoner()
{

}

// Accessors
const sf::Vector2f& Prisoner::getPos() const
{
	for (int i = 0; i < sprites.size(); i++) {
		return this->sprites[i].getPosition();
	}
}

const sf::FloatRect Prisoner::getBounds() const
{
	for (int i = 0; i < this->sprites.size(); i++) {
		return this->sprites[i].getGlobalBounds();
	}
}

// Public Functions
void Prisoner::updateStateChange(sf::Time deltaTime) {

	////PrisonAnim.resize(prisoners.size());
	//lastPrisonerPosition.resize(prisoners.size());
	//vel.resize(prisoners.size());
	//lastVelocity.resize(prisoners.size());

	/*if (gui.yardTime == true) {
	std::cout << "YardTime" << std::endl;
	wayPoint.x = yardWaypoint.x;
	wayPoint.y = yardWaypoint.y;
	}
	if (gui.chowTime == true) {
	std::cout << "chowTime" << std::endl;
	wayPoint.x = chowWaypoint.y;
	wayPoint.y = chowWaypoint.y;
	}
	if (gui.showerTime == true) {
	std::cout << "showerTime" << std::endl;
	wayPoint.x = showerWaypoint.x;
	wayPoint.y = showerWaypoint.y;
	}
	if (gui.workTime == true) {
	std::cout << "workTime" << std::endl;
	wayPoint.x = workWaypoint.x;
	wayPoint.y = workWaypoint.y;
	}
	if (gui.freeTime == true) {
	std::cout << "freeTime" << std::endl;
	wayPoint.x = freeWaypoint.x;
	wayPoint.y = freeWaypoint.y;
	}
	if (gui.bedTime == true) {

	}
	*/
	if (PState == IDLE) { // if the prisoner state is idle, the prisoners will wander by calling the wandering function
		Wandering();
		//	std::cout << "Prisoner State == Wandering" << std::endl;
	}
	if (PState == prisonerAngry) { // if the prisoner state is set to angry, the function will be called to make the prisoner attack
		prisonerAttack(player);
		//	std::cout << "Prisoner State == Attacking" << std::endl;
	}
	if (PState == PathFollow) { // if the prisoner is not angry or idle, the prisoner should be checking to follow the path
		pathFollowing();
		//	std::cout << "Prisoner State == PathFollowing" << std::endl;
	}

	if (prisonerAttacked == true) {
		PState = prisonerAngry;
	}
}

void Prisoner::Wandering() {

	if (time >= 5) { // if the prisonTime exceeds this, move the prisoner, update the random numbers for direction and prisoner selected
		prisonRand = rand() % 4 + 1; // choosing a direction, either 1, 2, 3 or 4 to move in 
									 //prisonChoice = rand() % prisoners.size(); // generating a random number, depending on how many prisoners there are, and choosing which prisoner to move
									 //	std::cout << "Random prisoner choice: " << prisonChoice << std::endl;
		time = 0; //setting prison Time back to 0
	}

	if (prisonRand == 1) {
		//	std::cout << "Prison Direction choice left(1)" << std::endl;

		this->vel[prisonChoice].x = -moveSpeed;
		anim.y = Left;
		lastPrisonerPosition[prisonChoice] = Left;

	}
	if (prisonRand == 2) {
		//	std::cout << "Prison Direction choice right(2)" << std::endl;
		vel[prisonChoice].x = moveSpeed;
		anim.y = Right;
		lastPrisonerPosition[prisonChoice] = Right;

	}
	if (prisonRand == 3) {
		//	std::cout << "Prison Direction choice up(3)" << std::endl;
		vel[prisonChoice].y = -moveSpeed;
		anim.y = Up;
		lastPrisonerPosition[prisonChoice] = Up;

	}
	if (prisonRand == 4) {
		//	std::cout << "Prison Direction choice down(4)" << std::endl;
		vel[prisonChoice].y = moveSpeed;
		anim.y = Down;
		lastPrisonerPosition[prisonChoice] = Down;

	}

	sprites[prisonChoice].move(vel[prisonChoice].x, vel[prisonChoice].y);
	lastVelocity[prisonChoice] = sf::Vector2f(-vel[prisonChoice].x, -vel[prisonChoice].y);



	if (wayPoint.x != 0 && wayPoint.y != 0) { // if the waypoint updates (not bedTime, follow the path)
											  //std::cout << "State change to path following" << std::endl;
		PState = PathFollow;
	}
}

void Prisoner::pathFollowing() {
	std::cout << "WayPoint, X: " << wayPoint.x << ", Y: " << wayPoint.y << std::endl;

	if (wayPoint.x != 0 || wayPoint.y != 0) {
		for (int i = 0; i < sprites.size(); i++) {
			//std::cout << "Prisoner Position: " << prisoners[i].getPosition().x << ", Y: " << prisoners[i].getPosition().y << std::endl;
			if (sprites[i].getPosition().x < wayPoint.x + (i * 32)) { // if the prisoners x position is less than the waypoints x position, move positively in the X direction
				vel[i].x = moveSpeed;
				anim.y = Right;
				lastPrisonerPosition[i] = Right;
			}
			if (sprites[i].getPosition().x > wayPoint.x) {
				vel[i].x = -moveSpeed;
				anim.y = Left;
				lastPrisonerPosition[i] = Left;
			}


			if (sprites[i].getPosition().y > wayPoint.y) { // if the prisoners Y position is less than the waypoints Y position, move positively in the Y direction
				vel[i].y = -moveSpeed;
				anim.y = Up;
				lastPrisonerPosition[i] = Up;
			}
			if (sprites[i].getPosition().y < wayPoint.y) {
				vel[i].y = moveSpeed;
				anim.y = Down;
				lastPrisonerPosition[i] = Down;
			}
			if (sprites[i].getPosition().x == wayPoint.x + (i * 32) && sprites[i].getPosition().y == wayPoint.y) {
				PState = IDLE;
			}
			sprites[i].move(vel[i].x, vel[i].y);
			lastVelocity[i] = sf::Vector2f(-vel[i].x, -vel[i].y);
		}
	}

	/*
	704 192 - prisoner 1
	1024 192 - prisoner 2
	1344 192 - prisoner 3
	1664 192 - prisoner 4
	*/


}

void Prisoner::PrisonerAttackedChoice(int &prisoner) {
	PrisonNumAngry = prisoner;
}

void Prisoner::playerAttacked(GUI &gui, Player &player) {
	if (player.getBounds().intersects(sprites[PrisonNumAngry].getGlobalBounds())) {
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

void Prisoner::prisonerAttack(Player &player) {
	if (sprites[PrisonNumAngry].getPosition().x >= player.getPos().x) {
		vel[PrisonNumAngry].x = -moveSpeed;
		anim.y = Left;
		lastPrisonerPosition[PrisonNumAngry] = Left;
	}
	if (sprites[PrisonNumAngry].getPosition().x <= player.getPos().x + 32) {
		vel[PrisonNumAngry].x = moveSpeed;
		anim.y = Right;
		lastPrisonerPosition[PrisonNumAngry] = Right;
	}
	if (sprites[PrisonNumAngry].getPosition().y >= player.getPos().y) {
		vel[PrisonNumAngry].y = -moveSpeed;
		this->anim.y = Up;
		lastPrisonerPosition[PrisonNumAngry] = Up;
	}
	if (sprites[PrisonNumAngry].getPosition().y <= player.getPos().y + 32) {
		vel[PrisonNumAngry].y = moveSpeed;
		anim.y = Down;
		lastPrisonerPosition[PrisonNumAngry] = Down;
	}
	//std::cout << "Prisoner Position X: " << prisoners[PrisonNumAngry].getPosition().x << " , Y: " << prisoners[PrisonNumAngry].getPosition().y << std::endl;
	//std::cout << "Player Position X: " << player.getPosition().x << " , Y: " << player.getPosition().y << std::endl;
	sprites[PrisonNumAngry].move(vel[PrisonNumAngry].x, vel[PrisonNumAngry].y); // making the prisoner follow the player 
	lastVelocity[PrisonNumAngry] = sf::Vector2f(-vel[PrisonNumAngry].x, -vel[PrisonNumAngry].y);




	//If the prisoner is within a 300 pixel range to the player, the prisoner can follow the player, else go back to wandering - add reduction to prisoner rep later
	if (sprites[PrisonNumAngry].getPosition().x < player.getPos().x - 192 || sprites[PrisonNumAngry].getPosition().x > player.getPos().x + 192 &&
		sprites[PrisonNumAngry].getPosition().y < player.getPos().y - 192 || sprites[PrisonNumAngry].getPosition().y > player.getPos().y + 192) {
		//	std::cout << "Player out of range" << std::endl;
		prisonerAttacked = false;
		PState = IDLE;
	}

}

void Prisoner::prisonerState() {

}

void Prisoner::update(sf::Time deltaTime)
{
	this->updateStateChange(deltaTime);

}

void Prisoner::render(sf::RenderTarget & target)
{
	for (int i = 0; i < sprites.size(); i++) {
		if (prisonerHealth[i] <= 0) { // each prisoner has a health amount, if it reaches 0 the state should change to a dead state, the players XP should increase and to remove the item from the vector
			std::cout << "Prisoner " << i << " has died" << std::endl;
			PState = deadState;
			//hud.XPcount += 30;
			prisonerHealth.erase(prisonerHealth.begin() + i); // erasing the prisoner from the vector
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




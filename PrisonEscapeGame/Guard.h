#pragma once
#include "NPC.h"

class Guard : virtual public NPC
{
private:
	// Variables
	enum guardState { guardIDLE, guardPathFollow, guardAngry, guardDead }; // moving idly, walking to destination, and chasing the player

	sf::Vector2i wayPoint;
	sf::Vector2i chowWaypoint; // chow time
	sf::Vector2i workWaypoint; // work time
	sf::Vector2i showerWaypoint; // shower time
	sf::Vector2i yardWaypoint; // shower time
	sf::Vector2i freeWaypoint; // free time area waypoint

	std::vector<sf::Vector2f> vel;
	std::vector<sf::Vector2f> lastVelocity;
	std::vector<Dir> lastGuardPosition;

	int guardChoice, guardRand, guardNumAngry; // the prisoner thats going to be moved

	Player player;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	//Constructor / Destructor
	Guard();
	virtual ~Guard();

	// Public Variables
	bool Attacked;
	std::vector<float> guardHealth;
	guardState GState;

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	// Public Functions
	void playerAttacked(GUI &gui, Player &player);
	void updateStateChange(sf::Time deltaTime);
	void guardState();
	void wandering();
	void pathFollowing();
	void guardAttacked(Player &player);
	void guardAttackedChoice(int &guard);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


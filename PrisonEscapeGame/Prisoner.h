#pragma once

#include "NPC.h"

#include "Player.h"
#include "GUI.h"

class Prisoner : virtual public NPC
{
private:
	// Variables
	enum prisonerState { IDLE, PathFollow, prisonerAngry, deadState }; // moving idly, walking to destination, and chasing the player
																	   //enum PrisonerDir { Down, Right, Up, Left, Idle };

	sf::Vector2i wayPoint;
	sf::Vector2i chowWaypoint; // chow time
	sf::Vector2i workWaypoint; // work time
	sf::Vector2i showerWaypoint; // shower time
	sf::Vector2i yardWaypoint; // shower time
	sf::Vector2i freeWaypoint; // free time area waypoint

							   //std::stringstream pss;
							   //std::string prisonerFile;
							   //std::string prisonerfilename;
							   //std::string ps;
							   //std::string prisonerPath;
							   //std::ifstream myInputFile;
							   //std::vector<sf::Texture>  spriteTexture;
	std::vector<sf::Vector2f> vel;
	std::vector<sf::Vector2f> lastVelocity;
	std::vector<Dir> lastPrisonerPosition;
	//std::vector<sf::Vector2i> PrisonAnim;

	int prisonChoice, prisonRand, PrisonNumAngry; // the prisoner thats going to be moved

	Player player;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprite();
public:
	//Constructor / Destructor
	Prisoner();
	virtual ~Prisoner();

	// Public Variables
	bool prisonerAttacked;

	//std::vector<sf::RectangleShape> sprites;
	std::vector<float> prisonerHealth;

	prisonerState PState;

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Public functions
	void playerAttacked(GUI &gui, Player &player);
	void updateStateChange(sf::Time deltaTime);
	void prisonerState();
	void Wandering();
	void pathFollowing();
	void prisonerAttack(Player &player);
	void PrisonerAttackedChoice(int &prisoner);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


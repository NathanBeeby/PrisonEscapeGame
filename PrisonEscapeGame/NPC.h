#pragma once

#include "Character.h"
#include "GUI.h"
#include <fstream>
#include <sstream>
#include <string>

class NPC : public Character
{
private:
	// Private Variables
	int spriteMovement;

	// Initialization
	void initVariables();
public:
	// Constructor / Destructor
	NPC();
	virtual ~NPC();

	// Public Variables
	enum Dir { Down, Right, Up, Left, Idle };
	Dir lastPosition;

	bool attacked;
	int time, move, number, health;
	int x, y;
	float Speed;

	sf::Vector2i anim;
	sf::Vector2f lastVelocity;
	sf::Vector2f vel;

	float sizeX, sizeY, moveSpeed;
	std::vector<sf::RectangleShape> sprites;
	std::vector<sf::Texture> spriteTexture;

	std::ifstream myInputFile;
	std::stringstream ss;
	std::string spriteFile;
	std::string spritefilename;
	std::string s;
	std::string path;


	void CollisionResponse();
	void Move(const float dirX, const float dirY);
	void moveIdle(sf::RectangleShape sprite, float speed);
};


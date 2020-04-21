#pragma once
#ifndef NPC_H
#define NPC_H
#include "Character.h"
#include "GUI.h"
#include <fstream>
#include <sstream>
#include <string>

class NPC : public Character
{
private:
#pragma region Private Variables 
	// Private Variables
	int spriteMovement;
#pragma endregion

#pragma region Initialization 
	// Initialization
	void initVariables();
#pragma endregion
public:
#pragma region Constructor / Destructor 
	// Constructor / Destructor
	NPC();
	virtual ~NPC();
#pragma endregion

#pragma region Public Variables
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
#pragma endregion

#pragma region Public Functions
	void CollisionResponse();
	void Move(const float dirX, const float dirY);
	void moveIdle(sf::RectangleShape sprite, float speed);
#pragma endregion
};

#endif
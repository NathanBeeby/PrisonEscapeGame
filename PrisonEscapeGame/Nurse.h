#pragma once
#ifndef NURSE_H
#define NURSE_H
#include "NPC.h"

class Nurse : virtual public NPC
{
private:
#pragma region Private Variables
	// Private Variables
	enum NurseState { nurseIDLE, underAttack, nurseDESTINATION, Run }; // moving idly, under attack, desination, and running away from the player
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSprite();
	void initTexture();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	Nurse();
	virtual ~Nurse();
#pragma endregion

#pragma region Accessors
	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public Functions
	void drawNurse(sf::RenderTarget& target);
	void NurseState();
	void onCollision();

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion
};

#endif
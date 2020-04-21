#pragma once
#ifndef WARDEN_H
#define WARDEN_H
#include "NPC.h"


class Warden : virtual public NPC
{
private:
#pragma region Private Variables
	// Private Variables
	enum wardenState { wardenIDLE, wardenSTOP, wardenDESTINATION }; // moving idly, walking to destination, and chasing the player
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSprite();
	void initTextures();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	Warden();
	virtual ~Warden();
#pragma endregion

#pragma region Accessors
	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public functions
	void updateStateChange(sf::Time deltaTime);
	void WardenState();
	void onCollision();
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion
};

#endif
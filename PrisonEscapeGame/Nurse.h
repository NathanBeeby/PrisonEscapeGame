#pragma once

#include "NPC.h"

class Nurse : virtual public NPC
{
private:
	// Variables
	enum NurseState { nurseIDLE, underAttack, nurseDESTINATION, Run }; // moving idly, under attack, desination, and running away from the player

																	   // Initialization
	void initVariables();
	void initSprite();
	void initTexture();
public:
	//Constructor / Destructor
	Nurse();
	virtual ~Nurse();

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Public functions
	void drawNurse(sf::RenderTarget& target);
	void NurseState();
	void onCollision();

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


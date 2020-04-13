#pragma once
#include "NPC.h"


class Warden : virtual public NPC
{
private:
	// Variables
	enum wardenState { wardenIDLE, wardenSTOP, wardenDESTINATION }; // moving idly, walking to destination, and chasing the player

																	// Initialization
	void initVariables();
	void initSprite();
	void initTextures();
public:
	//Constructor / Destructor
	Warden();
	virtual ~Warden();

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Public functions
	void updateStateChange(sf::Time deltaTime);
	void WardenState();
	void onCollision();
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);

};


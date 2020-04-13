#pragma once
#include "NPC.h"

class Guard : virtual public NPC
{
private:
	// Variables
	enum guardState { guardIDLE, guardStop, guardDESTINATION, guardCHASE }; // moving idly, walking to destination, and chasing the player

																			// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	//Constructor / Destructor
	Guard();
	virtual ~Guard();

	guardState GState;

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	// Public Functions
	void drawGuard(sf::RenderTarget& target);
	void guardState();

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};


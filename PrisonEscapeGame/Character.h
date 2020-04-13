#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticleEmitter.h"

class Character
{
private:

public:
	// Constructor / Destructor
	Character();
	virtual ~Character();

	// Virtual Functions
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderTarget &target) = 0;
};


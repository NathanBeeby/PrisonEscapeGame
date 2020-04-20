#pragma once

#include "Character.h"

class Player : virtual public Character
{
private:
	// Variables
	enum CharMove { Down, Right, Up, Left, AttackRight, AttackLeft, AttackUp, AttackDown };
	CharMove lastPosition;

	sf::Texture spriteTexture;
	sf::Vector2i ScreenSize, CharAnim;
	sf::Vector2f playerSize;
	sf::Vector2f playerPosition;
	sf::Vector2f lastVelocity;
	sf::Vector2f vel;

	int MisOpenCount, InvOpenCount, SkilOpenCount; // way of knowing if the player has hit the key twice
	
	// Initialization
	void initVariables();
	void initSprite();
	void initTextures();
public:
	//Constructor / Destructor
	Player();
	virtual ~Player();

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	const sf::FloatRect getBounds() const;


	//Public functions
	void CollisionResponse();
	void playerKeyboardMovement(sf::Keyboard::Key key, sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};

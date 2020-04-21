#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : virtual public Character
{
private:
#pragma region Private Variables
	// Private Variables
	enum CharMove { Down, Right, Up, Left, AttackRight, AttackLeft, AttackUp, AttackDown };
	CharMove lastPosition;

	sf::Texture spriteTexture;
	sf::Vector2i ScreenSize, CharAnim;
	sf::Vector2f playerSize;
	sf::Vector2f playerPosition;
	sf::Vector2f lastVelocity;
	sf::Vector2f vel;

	int MisOpenCount, InvOpenCount, SkilOpenCount; // way of knowing if the player has hit the key twice
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
	Player();
	virtual ~Player();
#pragma endregion

#pragma region Accessors
	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	const sf::FloatRect getBounds() const;
#pragma endregion

#pragma region Public Functions
	//Public Functions
	void CollisionResponse();
	void playerKeyboardMovement(sf::Keyboard::Key key, sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
#pragma endregion
};
#endif
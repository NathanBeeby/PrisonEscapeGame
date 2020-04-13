#pragma once

#include "Character.h"

class Player : virtual public Character
{
private:
	// Variables
	enum CharMove { Down, Right, Up, Left, AttackRight, AttackLeft, AttackUp, AttackDown };

	sf::Texture spriteTexture;
	sf::Vector2i ScreenSize, CharAnim;
	sf::Vector2f playerSize;
	sf::Vector2f playerPosition;
	sf::Vector2f lastVelocity;
	sf::Vector2f vel;

	int MisOpenCount, InvOpenCount, SkilOpenCount, Health, HealthMax; // way of knowing if the player has hit the key twice
	int playerStrength, playerStamina, playerArmour, playerCharisma, playerKnowledge, playerDamage, playerLevel;
	float moveSpeed;
	CharMove lastPosition;

	// Initialization
	void initVariables();
	void initSprite();
	void initTextures();
public:
	//Constructor / Destructor
	Player();
	virtual ~Player();

	// Public Variables
	sf::RectangleShape sprite;

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	const sf::FloatRect getBounds() const;
	const int& getHealth() const;
	const int getMaxHealth() const;
	const int getStrength() const;
	const int getStamina() const;
	const int getArmour() const;
	const int getCharisma() const;
	const int getKnowledge() const;
	const int getDamage() const;
	const int getLevel() const;

	//Public functions
	void removeHP(const int value);
	void setHP(const int HP);
	void addStrength(const int str);
	void removeStrength(const int str);
	void addStamina(const int sta);
	void removeStamina(const int sta);
	void addArmour(const int arm);
	void removeArmour(const int arm);
	void addCharisma(const int cha);
	void removeCharisma(const int cha);
	void addKnowledge(const int kno);
	void removeKnowledge(const int kno);
	void addDamage(const int dmg);
	void removeDamage(const int dmg);
	void addLevel(const int lvl);
	void setLevel(const int lvl);

	void CollisionResponse();
	void playerKeyboardMovement(sf::Keyboard::Key key, sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);
};

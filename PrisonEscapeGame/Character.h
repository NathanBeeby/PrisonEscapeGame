#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticleEmitter.h"

class Character
{
private:

public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	Character();
	virtual ~Character();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	int strength, stamina, armour, charisma, knowledge, damage, level;
	int Health, HealthMax;
	float moveSpeed;
	sf::RectangleShape sprite;
#pragma endregion

#pragma region Public Functions
	// Public Functions
	int& getHealth();
	int& getMaxHealth();
	int& getStrength();
	int& getStamina();
	int& getArmour();
	int& getCharisma();
	int& getKnowledge();
	int& getDamage();
	int& getLevel();

	void removeHP(int value);
	void setHP(int HP);
	void addStrength(int str);
	void removeStrength(int str);
	void addStamina(int sta);
	void removeStamina(int sta);
	void addArmour(int arm);
	void removeArmour(int arm);
	void addCharisma(int cha);
	void removeCharisma(int cha);
	void addKnowledge(int kno);
	void removeKnowledge(int kno);
	void addDamage(int dmg);
	void removeDamage(int dmg);
	void addLevel(int lvl);
	void setLevel(int lvl);
#pragma endregion

#pragma region Virtual Functions
	// Virtual Functions
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderTarget &target) = 0;
#pragma endregion
};

#endif

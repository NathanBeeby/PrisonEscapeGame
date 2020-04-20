#include "Character.h"


// Constructor / Destructor
Character::Character()
{
}


Character::~Character()
{
}

int & Character::getHealth()
{
	return this->Health;
}

int & Character::getMaxHealth()
{
	return this->HealthMax;
}

int & Character::getStrength()
{
	return this->strength;
}

int & Character::getStamina()
{
	return this->stamina;
}

int & Character::getArmour()
{
	return this->armour;
}

int & Character::getCharisma()
{
	return this->charisma;
}

int & Character::getKnowledge()
{
	return this->knowledge;
}

int & Character::getDamage()
{
	return this->damage;
}

int & Character::getLevel()
{
	return this->level;
}


void Character::removeHP(int value)
{
	this->Health -= value;
}

void Character::setHP(int HP)
{
	this->Health = HP;
}

void Character::addStrength(int str)
{
	this->strength += str;
}

void Character::removeStrength(int str)
{
	this->strength -= str;
}

void Character::addStamina(int sta)
{
	this->stamina += sta;
	std::cout << "player Stamina: " << this->stamina << std::endl;
}

void Character::removeStamina(int sta)
{
	this->stamina -= sta;
}

void Character::addArmour(int arm)
{
	this->armour += arm;
}

void Character::removeArmour(int arm)
{
	this->armour -= arm;
}

void Character::addCharisma(int cha)
{
	this->charisma += cha;
}

void Character::removeCharisma(int cha)
{
	this->charisma -= cha;
}

void Character::addKnowledge(int kno)
{
	this->knowledge += kno;
}

void Character::removeKnowledge(int kno)
{
	this->knowledge -= kno;
}

void Character::addDamage(int dmg)
{
	this->damage += dmg;
}

void Character::removeDamage(int dmg)
{
	this->damage -= dmg;
}

void Character::addLevel(int lvl)
{
	this->level += lvl;
}

void Character::setLevel(int lvl)
{
	this->level = lvl;
}

#include "Player.h"

//Initialization
void Player::initVariables()
{
	// Integer Variables
	this->MisOpenCount = 0;
	this->InvOpenCount = 0;
	this->SkilOpenCount = 0;
	this->moveSpeed = 20;
	this->playerDamage = 5;// making the player damage a third of the hud player strength (?/100) + the initial player damage (1)
	this->CharAnim.x = 1;
	this->Health = 100;
	this->playerSize.x = 32;
	this->playerSize.y = 32;
	this->playerPosition.x = 150;
	this->playerPosition.y = 150;
	this->playerStrength = 0; // the stat number that will affect the skills bar
	this->playerStamina = 0;
	this->playerArmour = 0;
	this->playerCharisma = 0;
	this->playerKnowledge = 0;
	this->playerLevel = 1;
	this->lastPosition = Down;
	this->CharAnim.y = Down;
}

void Player::initSprite()
{
	this->sprite.setSize(sf::Vector2f(playerSize.x, playerSize.y));
	this->sprite.setOrigin(sf::Vector2f(playerSize.x / 2.f, playerSize.y / 2.f));
	this->sprite.setTexture(&spriteTexture);
	this->sprite.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}

void Player::initTextures()
{
	if (!this->spriteTexture.loadFromFile("../assets/image_assets/characters/sprite_images.png"))
		std::cerr << "Error";
}

//Constructor / Destructor
Player::Player() {
	this->initVariables();
	this->initSprite();
	this->initTextures();
}

Player::~Player()
{

}

//Public functions
void Player::playerKeyboardMovement(sf::Keyboard::Key key, sf::Time deltaTime) {
	vel.x = 0;
	vel.y = 0;

	if (key == sf::Keyboard::Up || key == sf::Keyboard::W)
	{
		vel.y -= (moveSpeed + (playerStamina)* deltaTime.asSeconds());
		CharAnim.y = Up;
		lastPosition = Up;

	}
	else if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
	{
		vel.y += (moveSpeed + (playerStamina)* deltaTime.asSeconds());
		CharAnim.y = Down;
		lastPosition = Down;

	}

	if (key == sf::Keyboard::Left || key == sf::Keyboard::A)
	{
		vel.x -= (moveSpeed + (playerStamina)* deltaTime.asSeconds());
		CharAnim.y = Left;
		lastPosition = Left;

	}
	if (key == sf::Keyboard::Right || key == sf::Keyboard::D)
	{
		vel.x += (moveSpeed + (playerStamina)* deltaTime.asSeconds());
		CharAnim.y = Right;
		lastPosition = Right;

	}

	if (key == sf::Keyboard::Space)
	{
		if (lastPosition == Right) {
			CharAnim.y = AttackRight;
			lastPosition = AttackRight;
		}
		if (lastPosition == Left) {
			CharAnim.y = AttackLeft;
			lastPosition = AttackLeft;
		}
		if (lastPosition == Up) {
			CharAnim.y = AttackUp;
			lastPosition = AttackUp;
		}
		if (lastPosition == Down) {
			CharAnim.y = AttackDown;
			lastPosition = AttackDown;
		}

	}

	if (!(key == sf::Keyboard::Down) ||
		key == sf::Keyboard::Up ||
		key == sf::Keyboard::Left ||
		key == sf::Keyboard::Right ||
		key == sf::Keyboard::Space)
	{
		CharAnim = sf::Vector2i(1, lastPosition);
	}

	sprite.move(vel.x, vel.y);
	lastVelocity = sf::Vector2f(-vel.x, -vel.y);

	CharAnim.x += 1; // incrementing the character direction x, to flick through sprite images	
	if (CharAnim.x * 32 >= spriteTexture.getSize().x)
	{// if the texture width is greater than 
		CharAnim.x = 0; // when it reaches the edge, go back to 0
	}
	sprite.setTextureRect(sf::IntRect(CharAnim.x * 32, CharAnim.y * 32, 32, 32)); // drawing the rectangles position, width and height


}

void Player::update(sf::Time deltaTime)
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

const sf::Vector2f & Player::getPos() const
{
	return sprite.getPosition();
}

const sf::Vector2f & Player::getSize() const
{
	return this->playerSize;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHealth() const
{
	return this->Health;
}

const int Player::getMaxHealth() const
{
	return this->HealthMax;
}

const int Player::getStrength() const
{
	return this->playerStrength;
}

const int Player::getStamina() const
{
	std::cout << "player strength is now: " << this->playerStamina << std::endl;
	return this->playerStamina;
}

const int Player::getArmour() const
{
	return this->playerArmour;
}

const int Player::getCharisma() const
{
	return this->playerCharisma;
}

const int Player::getKnowledge() const
{
	return playerKnowledge;
}

const int Player::getDamage() const
{
	return this->playerDamage;
}

const int Player::getLevel() const
{
	return this->playerLevel;
}

void Player::removeHP(const int value)
{
	this->Health -= value;
}

void Player::setHP(const int HP)
{
	this->Health = HP;
}

void Player::addStrength(const int str)
{
	this->playerStrength += str;
}

void Player::removeStrength(const int str)
{
	this->playerStrength -= str;
}

void Player::addStamina(const int sta)
{
	this->playerStamina += sta;
	std::cout << "player Stamina: " << this->playerStamina << std::endl;
}

void Player::removeStamina(const int sta)
{
	this->playerStamina -= sta;
}

void Player::addArmour(const int arm)
{
	this->playerArmour += arm;
}

void Player::removeArmour(const int arm)
{
	this->playerArmour -= arm;
}

void Player::addCharisma(const int cha)
{
	this->playerCharisma += cha;
}

void Player::removeCharisma(const int cha)
{
	this->playerCharisma -= cha;
}

void Player::addKnowledge(const int kno)
{
	this->playerKnowledge += kno;
}

void Player::removeKnowledge(const int kno)
{
	this->playerKnowledge -= kno;
}

void Player::addDamage(const int dmg)
{
	this->playerDamage += dmg;
}

void Player::removeDamage(const int dmg)
{
	this->playerDamage -= dmg;
}

void Player::addLevel(const int lvl)
{
	this->playerLevel += lvl;
}

void Player::setLevel(const int lvl)
{
	this->playerLevel = lvl;
}

void Player::CollisionResponse()
{
	this->sprite.move(this->lastVelocity);
}


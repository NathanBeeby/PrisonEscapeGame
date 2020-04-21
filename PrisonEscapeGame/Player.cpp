#include "Player.h"

#pragma region Initialization
//Initialization
void Player::initVariables()
{
	// Integer Variables
	this->MisOpenCount = 0;
	this->InvOpenCount = 0;
	this->SkilOpenCount = 0;
	this->moveSpeed = 20;
	this->damage = 5;// making the player damage a third of the hud player strength (?/100) + the initial player damage (1)
	this->CharAnim.x = 1;
	this->Health = 100;
	this->playerSize.x = 32;
	this->playerSize.y = 32;
	this->playerPosition.x = 150;
	this->playerPosition.y = 150;
	this->strength = 0; // the stat number that will affect the skills bar
	this->stamina = 0;
	this->armour = 0;
	this->charisma = 0;
	this->knowledge = 0;
	this->level = 1;
	this->lastPosition = Down;
	this->CharAnim.y = Down;
}

void Player::initSprite()
{
	this->sprite.setSize(sf::Vector2f(playerSize.x, playerSize.y));
	this->sprite.setOrigin(sf::Vector2f(playerSize.x / 2.f, playerSize.y / 2.f));
	this->sprite.setTexture(&spriteTexture);
	sprite.setTextureRect(sf::IntRect(CharAnim.x * 32, CharAnim.y * 32, 32, 32)); // drawing the rectangles position, width and height
	this->sprite.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}

void Player::initTextures()
{
	if (!this->spriteTexture.loadFromFile("../assets/image_assets/characters/sprite_images.png"))
		std::cerr << "Error";
}
#pragma endregion

#pragma region Constructor / Destructor
//Constructor / Destructor
Player::Player() {
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Player::~Player()
{

}
#pragma endregion

#pragma region Accessors
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
#pragma endregion

#pragma region Public Functions
//Public Functions
void Player::playerKeyboardMovement(sf::Keyboard::Key key, sf::Time deltaTime) {
	vel.x = 0;
	vel.y = 0;

	if (key == sf::Keyboard::Up)
	{
		vel.y -= (moveSpeed + (this->stamina) * deltaTime.asSeconds());
		CharAnim.y = Up;
		lastPosition = Up;

	}
	else if (key == sf::Keyboard::Down)
	{
		vel.y += (moveSpeed + (this->stamina)* deltaTime.asSeconds());
		CharAnim.y = Down;
		lastPosition = Down;

	}

	if (key == sf::Keyboard::Left)
	{
		vel.x -= (moveSpeed + (this->stamina)* deltaTime.asSeconds());
		CharAnim.y = Left;
		lastPosition = Left;

	}
	if (key == sf::Keyboard::Right)
	{
		vel.x += (moveSpeed + (this->stamina)* deltaTime.asSeconds());
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


void Player::CollisionResponse()
{
	this->sprite.move(this->lastVelocity);
}

#pragma endregion
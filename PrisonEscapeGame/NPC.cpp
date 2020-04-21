#include "NPC.h"

#pragma region Initialization
// Initialization
void NPC::initVariables()
{
	this->spriteMovement = 0;
}
#pragma endregion

#pragma region Constructor / Destructor
// Constructor / Destructor
NPC::NPC()
{
	this->initVariables();
}


NPC::~NPC()
{
}
#pragma endregion

#pragma region Public Functions
void NPC::CollisionResponse()
{
	for (int i = 0; i < sprites.size(); i++) {
		std::cout << "Character Collision: " << i << std::endl;
		sprites[i].move(lastVelocity);
	}
}

void NPC::Move(const float dirX, const float dirY)
{
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].move(vel.x, vel.y);
		lastVelocity = sf::Vector2f(-vel.x, -vel.y);

		anim.x++;
		for (int i = 0; i < spriteTexture.size(); i++) {
			if (anim.x * 32 >= spriteTexture[i].getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
				anim.x = 0;
			}
		}

		sprites[i].setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32)); // cropping the image with the position and size of the image 
	}
}

void NPC::moveIdle(sf::RectangleShape sprite, float speed)
{
	this->spriteMovement = rand() % 4 + 1;

	if (spriteMovement == 1) {
		sprite.move(sf::Vector2f(0, 1 + speed));
	}
	else if (spriteMovement == 2) {
		sprite.move(sf::Vector2f(0, -1 + -speed));
	}
	else if (spriteMovement == 3) {
		sprite.move(sf::Vector2f(1 + speed, 0));
	}
	else {
		sprite.move(sf::Vector2f(-1 + -speed, 0));
	}

}
#pragma endregion

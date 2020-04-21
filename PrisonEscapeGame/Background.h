#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Background 
{
public:
#pragma region Constructor
	Background() {

	}

	Background(std::string image) { // gets the image
		if (!backgroundTexture.loadFromFile(image)) // if the image cannot be loaded
			std::cerr << "Error";
		std::cout << "Couldn't get background texture" << std::endl; // erroring out that the background texture couldn't be loaded in
		backgroundSprite.setTexture(backgroundTexture); // setting the texture to a sprite
	}
#pragma endregion

#pragma region Public Functions
	void drawBackground(sf::RenderWindow &window) { //drawing the background sprite to the window
		window.draw(backgroundSprite);
	}
#pragma endregion

private:
#pragma region Private Variables
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
#pragma endregion
};
#endif
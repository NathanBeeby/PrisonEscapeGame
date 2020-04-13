#include "GameOver.h"

// Initialization 
void GameOver::initVariables()
{
	this->selectedItemIndex = 0;
}

void GameOver::initTextures()
{

}

void GameOver::initSprites()
{
	this->BackgroundShape.setOrigin(400, 300); // Half Extents of swcreen
	this->BackgroundShape.setSize(sf::Vector2f(800, 600));
	this->BackgroundShape.setTexture(&GameOverBackground);
}

void GameOver::initText()
{
	this->ExitMenuText[0].setFont(font);
	this->ExitMenuText[0].setCharacterSize(100);
	this->ExitMenuText[0].setFillColor(sf::Color::Blue);
	this->ExitMenuText[0].setString("Retry");

	this->ExitMenuText[1].setFont(font);
	this->ExitMenuText[1].setCharacterSize(100);
	this->ExitMenuText[1].setFillColor(sf::Color::White);
	this->ExitMenuText[1].setString("Exit");

	this->gameOverMessage.setFont(font);
	this->gameOverMessage.setString("Game Over!");
	this->gameOverMessage.setCharacterSize(100);
	this->gameOverMessage.setFillColor(sf::Color(255, 0, 0));
}

void GameOver::initFont()
{
	if (!this->GameOverBackground.loadFromFile("../assets/image_assets/GameOver.png")) {
		std::cout << "Cannot find gameover texture" << std::endl;
		system("pause");
	}
	if (!this->font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		system("pause");
	}
}

// Constructor / Destructor
GameOver::GameOver()
{
	this->initTextures();
	this->initVariables();
	this->initSprites();
	this->initText();
	this->initFont();
}

GameOver::~GameOver()
{
}

// Public Functions
void GameOver::Up() {
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->ExitMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->ExitMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void GameOver::Down() {
	if (this->selectedItemIndex + 1 < GameOver_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->ExitMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->ExitMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void GameOver::MouseHandler(sf::RenderTarget &target) {
	//ISSUE HERE IS THAT VIEW HAS MOVED
	//sf::Vector2i mousePos = sf::Mouse::getPosition(target); // getting the position of the mouse relative to the window
	//std::cout << "Mouse Pos - X: " << mousePos.x << ", Y: " << mousePos.y << std::endl;
	//std::cout << "ExitMenuText 0 Pos - X: " << ExitMenuText[0].getPosition().x << ", Y: " << ExitMenuText[0].getPosition().y << std::endl;
	//std::cout << "ExitMenuText 1 Pos - X: " << ExitMenuText[1].getPosition().x << ", Y: " << ExitMenuText[1].getPosition().y << std::endl;
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
	//	if (mousePos.x >= ExitMenuText[0].getPosition().x && mousePos.x <= ExitMenuText[0].getPosition().x + 115) { // if the x position is on the first HUD button
	//		if (mousePos.y >= ExitMenuText[0].getPosition().y && mousePos.y <= ExitMenuText[0].getPosition().y + 100) { // if the y position is between the HUD button
	//			std::cout << "rety Button pressed" << std::endl;
	//			

	//		}
	//	}
	//	if (mousePos.x >= ExitMenuText[1].getPosition().x && mousePos.x <= ExitMenuText[1].getPosition().x + 115) { // if the x position is on the first HUD button
	//		if (mousePos.y >= ExitMenuText[1].getPosition().y && mousePos.y <= ExitMenuText[1].getPosition().y + 100) { // if the y position is between the HUD button
	//			std::cout << "exit Button pressed" << std::endl;
	//			exit(0); // exiting out 
	//			system("Exit");

	//		}
	//	}
	//}
}

void GameOver::KeyHandler(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Up || key == sf::Keyboard::W) {
		Up();
		std::cout << "Up pressed" << std::endl;
	}
	if (key == sf::Keyboard::Down || key == sf::Keyboard::S) {
		Down();
		std::cout << "Down pressed" << std::endl;
	}


	if (key == sf::Keyboard::Return) {
		std::cout << "return pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "Retry pressed" << std::endl;
			//retry here - reset the game and replay
			break;
		case 1: std::cout << "Exit pressed" << std::endl;
			exit(0); // exiting out 
			system("Exit");
			break;
		}
	}
}

void GameOver::render(sf::RenderTarget & target, sf::View &view)
{
	BackgroundShape.setPosition(view.getCenter().x, view.getCenter().y); // positioning the shape to the centre of the view
	gameOverMessage.setPosition(view.getCenter().x - 75, view.getCenter().y - 280);
	ExitMenuText[0].setPosition(sf::Vector2f(view.getCenter().x - 30, view.getCenter().y - 150)); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	ExitMenuText[1].setPosition(sf::Vector2f(view.getCenter().x - 30, view.getCenter().y + 25)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	target.draw(BackgroundShape); // drawing the background image
	target.draw(gameOverMessage); // drawing the title
	for (int i = 0; i < GameOver_Number; i++) { // drawing the selectable button
		target.draw(ExitMenuText[i]);
	}
}

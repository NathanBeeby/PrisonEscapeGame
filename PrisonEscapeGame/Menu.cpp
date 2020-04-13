#include "Menu.h"

// Initialization
void Menu::initVariables()
{
	// Integer Variables
	this->selectedItemIndex = 0;
	this->height = 600;
	this->width = 800;

	// Boolean Variables
	this->playPressed = false;
	this->optionsPressed = false;
	this->exitPressed = false;
}

void Menu::initSprites()
{
	this->background.setPosition(0, 0);
	this->background.setTexture(&this->backgroundTexture);
	this->background.setSize(sf::Vector2f(this->width, this->height));

	this->background2.setPosition(0, 0);
	this->background2.setTexture(&this->backgroundTexture2);
	this->background2.setSize(sf::Vector2f(this->width, this->height));
}

void Menu::initText()
{
	this->MenuText[0].setFont(font);
	this->MenuText[0].setCharacterSize(100);
	this->MenuText[0].setFillColor(sf::Color::Blue);
	this->MenuText[0].setString("Play");
	this->MenuText[0].setPosition(sf::Vector2f(this->width / 2.3, this->height / (item_Number + 2) * 1)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->MenuText[1].setFont(font);
	this->MenuText[1].setCharacterSize(100);
	this->MenuText[1].setFillColor(sf::Color::White);
	this->MenuText[1].setString("Options");
	this->MenuText[1].setPosition(sf::Vector2f(this->width / 2.3, this->height / (item_Number + 2) * 2)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->MenuText[2].setFont(font);
	this->MenuText[2].setCharacterSize(100);
	this->MenuText[2].setFillColor(sf::Color::White);
	this->MenuText[2].setString("Exit");
	this->MenuText[2].setPosition(sf::Vector2f(this->width / 2.3, this->height / (item_Number + 2) * 3)); // center item for width, have the amount of string items + 1, so that they're equally spaced out
}

void Menu::initTextures()
{
	if (!this->backgroundTexture.loadFromFile("../assets/image_assets/Background.png")) {
		std::cout << "Error: loading Background.png" << std::endl;
	}
	if (!this->backgroundTexture2.loadFromFile("../assets/image_assets/Background2.png")) {
		std::cout << "Error: loading Background2.png" << std::endl;
	}
}

void Menu::initFont()
{
	if (!this->font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		std::cout << "Error loading file" << std::endl;
		system("pause");
	}
}

// Constructor / Destructor
Menu::Menu()
{
	this->initTextures();
	this->initVariables();
	this->initSprites();
	this->initText();
	this->initFont();
}

Menu::~Menu()
{

}

// Public FUnctions
void Menu::MouseHandler(sf::RenderTarget &target) {
	//sf::Vector2i mousePos = ::sf::Mouse::getPosition(target); // getting the position of the mouse relative to the window
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
	//	if (mousePos.x >= MenuText[0].getPosition().x && mousePos.x <= MenuText[0].getPosition().x + 80) { // if the x position is on the first HUD button
	//		if (mousePos.y >= MenuText[0].getPosition().y && mousePos.y <= MenuText[0].getPosition().y + 100) { // if the y position is between the HUD button
	//			std::cout << "Play Button pressed" << std::endl;
	//			playPressed = true;
	//		}
	//	}
	//	if (mousePos.x >= MenuText[1].getPosition().x && mousePos.x <= MenuText[1].getPosition().x + 130) { // if the x position is on the first HUD button
	//		if (mousePos.y >= MenuText[1].getPosition().y && mousePos.y <= MenuText[1].getPosition().y + 100) { // if the y position is between the HUD button
	//			std::cout << "Options Button pressed" << std::endl;
	//			optionsPressed = true;
	//		}
	//	}
	//	if (mousePos.x >= MenuText[2].getPosition().x && mousePos.x <= MenuText[2].getPosition().x + 100) { // if the x position is on the first HUD button
	//		if (mousePos.y >= MenuText[2].getPosition().y && mousePos.y <= MenuText[2].getPosition().y + 100) { // if the y position is between the HUD button
	//			std::cout << "Exit Button pressed" << std::endl;
	//			exitPressed = true;
	//		}
	//	}
	//}
}

void Menu::KeyHandler(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up) {
		Up();
		std::cout << "Up pressed" << std::endl;
	}
	if (key == sf::Keyboard::S || key == sf::Keyboard::Down) {
		Down();
		std::cout << "Down pressed" << std::endl;
	}


	if (key == sf::Keyboard::Return) {
		std::cout << "return pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "play pressed" << std::endl;
			playPressed = true;
			break;
		case 1: std::cout << "options pressed" << std::endl;
			optionsPressed = true;
			break;
		case 2: std::cout << "exit pressed" << std::endl;
			exitPressed = true;
			break;
		}
	}
}

void Menu::Up() {
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Menu::Down() {
	if (this->selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Menu::render(sf::RenderTarget &target) {
	try {
		int LightFlicker = rand() % 10;
		for (int x = 1; x < 256; x++) {
			int LightFlicker = rand() % 10; // flickering the light only slightly, by having random number generator
		}
		if (LightFlicker == 8) { // if the value is 8, paint the background with the background with no lighting
								 //this->background2.drawBackground(*this->window);
			target.draw(background2);
		}
		else {
			target.draw(background);
			//background.drawBackground(*this->window); // if not paint the light background
		}
	}
	catch (std::exception ex) {
		std::cout << "Error: drawing Start Menu: " << std::endl;
	}
	for (int i = 0; i < item_Number; i++) {
		target.draw(MenuText[i]);
	}
}

#include "OptionsMenu.h"

#pragma region Initialization
void OptionsMenu::initVariables()
{
	this->Music = 50.0f;
	this->Sound = 50.0f;
	this->instrucPress = false;
	this->backPress = false;
	this->height = 600;
	this->width = 800;
	this->optionsBackground.setSize(sf::Vector2f(this->width, this->height));
	this->optionsBackground.setPosition(0, 0);
	if (!this->optionsBackgroundTexture.loadFromFile("../assets/image_assets/OptionsBackground.png")) {
		std::cout << "Error: loading OptionsBackground.png" << std::endl;
	}
	this->optionsBackground.setTexture(&this->optionsBackgroundTexture);
	this->selectedItemIndex = 0;
}

void OptionsMenu::initFont()
{
	if (!font.loadFromFile("../assets/text_assets/Font.ttf"))
	{
		// error...
		std::cout << "Error loading file" << std::endl;
		system("pause");
	}
}

void OptionsMenu::initText()
{
	OptionsMenuText[0].setFont(font);
	OptionsMenuText[0].setCharacterSize(60);
	OptionsMenuText[0].setFillColor(sf::Color::Blue);
	OptionsMenuText[0].setString("Sound");
	OptionsMenuText[0].setPosition(sf::Vector2f(120, 55)); // center item for width, have the amount of string items + 1, so that they're equally spaced out



	OptionsMenuText[1].setFont(font);
	OptionsMenuText[1].setCharacterSize(60);
	OptionsMenuText[1].setFillColor(sf::Color::White);
	OptionsMenuText[1].setString("Music");
	OptionsMenuText[1].setPosition(sf::Vector2f(120, 165)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	OptionsMenuText[2].setFont(font);
	OptionsMenuText[2].setCharacterSize(60);
	OptionsMenuText[2].setFillColor(sf::Color::White);
	OptionsMenuText[2].setString("Instructions");
	OptionsMenuText[2].setPosition(sf::Vector2f(this->width / 2.8, this->height / 1.4)); // center item for width, have the amount of string items + 1, so that they're equally spaced out


	OptionsMenuText[3].setFont(font);
	OptionsMenuText[3].setCharacterSize(60);
	OptionsMenuText[3].setFillColor(sf::Color::White);
	OptionsMenuText[3].setString("Back");
	OptionsMenuText[3].setPosition(sf::Vector2f(40, this->height - 90)); // center item for width, have the amount of string items + 1, so that they're equally spaced out
}

#pragma endregion

#pragma region Constructor / Destructor
OptionsMenu::OptionsMenu()
{
	this->initVariables();
	this->initFont();
	this->initText();
}

OptionsMenu::~OptionsMenu()
{
}
#pragma endregion

#pragma region Public Functions
void OptionsMenu::keyHandler(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Up) {
		Up();
		std::cout << "Up Pressed" << std::endl;
	}
	else if (key == sf::Keyboard::Down) {
		Down();
		std::cout << "Down Pressed" << std::endl;
	}

	if (key == sf::Keyboard::Left) {
		std::cout << "Left Pressed" << std::endl;
		switch (GetPressedItem()) {

		case 0: std::cout << "Sound pressed" << std::endl;
			if (Sound != 0) {
				Sound--;
			}
			break;
		case 1: std::cout << "Music pressed" << std::endl;
			if (Music != 0) {

				Music--;
			}
			break;
		}
	}

	else if (key == sf::Keyboard::Right) {
		std::cout << "Right Pressed" << std::endl;
		switch (GetPressedItem()) {

		case 0: std::cout << "Sound pressed" << std::endl;
			if (Sound <= 99) {
				Sound++;


			}
			break;
		case 1: std::cout << "Music pressed" << std::endl;
			if (Music <= 99) {
				Music++;

			}
			break;
		}
	}
	if (key == sf::Keyboard::Return) {
		std::cout << "Return Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 2: std::cout << "Instructions" << std::endl;
			instructionsPressed();
			break;
		case 3: std::cout << "Back" << std::endl;
			backPressed();
			break;

		}
	}
}
void OptionsMenu::instructionsPressed() {
	instrucPress = true;
}
void OptionsMenu::backPressed() {
	backPress = true;
}

void OptionsMenu::mouseHandler(sf::RenderWindow &window) {
	sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= OptionsMenuText[2].getPosition().x && mousePos.x <= OptionsMenuText[2].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= OptionsMenuText[2].getPosition().y && mousePos.y <= OptionsMenuText[2].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Instructions Button pressed" << std::endl;
				instructionsPressed();
			}
		}
		if (mousePos.x >= OptionsMenuText[3].getPosition().x && mousePos.x <= OptionsMenuText[3].getPosition().x + 100) { // if the x position is on the first HUD button
			if (mousePos.y >= OptionsMenuText[3].getPosition().y && mousePos.y <= OptionsMenuText[3].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Back Button pressed" << std::endl;
				backPressed();
			}
		}
	}
}




void OptionsMenu::render(sf::RenderTarget &target) {
	target.draw(optionsBackground);
	drawBars(target);
	for (int i = 0; i < Options_item_Number; i++) {
		target.draw(OptionsMenuText[i]);
	}



}

void OptionsMenu::drawBars(sf::RenderTarget &target) {
	emptyMusic.setSize(sf::Vector2f(200, 20));
	emptyMusic.setFillColor(sf::Color(255, 0, 0));
	emptyMusic.setOutlineThickness(2);
	emptyMusic.setOutlineColor(sf::Color(0, 0, 0));

	emptySound.setSize(sf::Vector2f(200, 20));
	emptySound.setFillColor(sf::Color(255, 0, 0));
	emptySound.setOutlineThickness(2);
	emptySound.setOutlineColor(sf::Color(0, 0, 0));

	MusicBar.setSize(sf::Vector2f((Music * 2), 20));
	MusicBar.setFillColor(sf::Color(0, 0, 255));
	MusicBar.setOutlineThickness(2);
	MusicBar.setOutlineColor(sf::Color(0, 0, 0));

	SoundBar.setSize(sf::Vector2f((Sound * 2), 20));
	SoundBar.setFillColor(sf::Color(0, 0, 255));
	SoundBar.setOutlineThickness(2);
	SoundBar.setOutlineColor(sf::Color(0, 0, 0));

	emptySound.setPosition(250, 100);
	emptyMusic.setPosition(250, 200);


	SoundBar.setPosition(emptySound.getPosition().x, emptySound.getPosition().y);
	MusicBar.setPosition(emptyMusic.getPosition().x, emptyMusic.getPosition().y);

	target.draw(emptyMusic);
	target.draw(emptySound);
	target.draw(MusicBar);
	target.draw(SoundBar);
}


void OptionsMenu::Up() {
	if (selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		OptionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex--; //decrememnt the index
		OptionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void OptionsMenu::Down() {
	if (selectedItemIndex + 1 < Options_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		OptionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex++; // increment the index
		OptionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}
#pragma endregion
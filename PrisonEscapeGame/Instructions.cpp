#include "Instructions.h"

// Initialization
void Instructions::initVariables()
{
	// Integer Variables
	this->height = 600;
	this->width = 800;
	this->selectedItemIndex = 0;

	// Boolean Variables
	this->backPress = false;
	this->nextPress = false;

	// Enumeration Variables
	this->state = noState;

	// Vectors
	this->KeyInstruction.resize(7);
	this->first3Keys.resize(3);
	this->skillsInstruction.resize(5);
	this->skillsTitle.resize(5);
	this->routineInstruction.resize(5);
	this->routineSubText.resize(6);
}

void Instructions::initSprites()
{
	this->instructionsBackground.setSize(sf::Vector2f(this->width, this->height));
	this->instructionsBackground.setPosition(0, 0);
	this->instructionsBackground.setTexture(&this->instructionsBackgroundTexture);

	this->keyBox.setTexture(&keysTexture);
	this->keyBox.setSize(sf::Vector2f(300, 700));

	this->routinesBox.setTexture(&rotuineTexture);
	this->routinesBox.setSize(sf::Vector2f(300, 500));
}

void Instructions::initText()
{
	this->InstructionsMenuText[0].setFont(font);
	this->InstructionsMenuText[0].setCharacterSize(60);
	this->InstructionsMenuText[0].setFillColor(sf::Color::Blue);
	this->InstructionsMenuText[0].setString("Keys");
	this->InstructionsMenuText[0].setPosition(sf::Vector2f(50, 20)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->InstructionsMenuText[1].setFont(font);
	this->InstructionsMenuText[1].setCharacterSize(60);
	this->InstructionsMenuText[1].setFillColor(sf::Color::White);
	this->InstructionsMenuText[1].setString("Crafting");
	this->InstructionsMenuText[1].setPosition(sf::Vector2f(50, 120)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->InstructionsMenuText[2].setFont(font);
	this->InstructionsMenuText[2].setCharacterSize(60);
	this->InstructionsMenuText[2].setFillColor(sf::Color::White);
	this->InstructionsMenuText[2].setString("Skills");
	this->InstructionsMenuText[2].setPosition(sf::Vector2f(50, 220)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->InstructionsMenuText[3].setFont(font);
	this->InstructionsMenuText[3].setCharacterSize(60);
	this->InstructionsMenuText[3].setFillColor(sf::Color::White);
	this->InstructionsMenuText[3].setString("Routine");
	this->InstructionsMenuText[3].setPosition(sf::Vector2f(50, 320)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->InstructionsMenuText[4].setFont(font);
	this->InstructionsMenuText[4].setCharacterSize(60);
	this->InstructionsMenuText[4].setFillColor(sf::Color::White);
	this->InstructionsMenuText[4].setString("Back");
	this->InstructionsMenuText[4].setPosition(sf::Vector2f(this->width - 160, this->height - 100)); // center item for width, have the amount of string items + 1, so that they're equally spaced out


	// String Variables
	this->first3Keys[0].setString("Movement Keys");
	this->first3Keys[1].setString("Selecting Item in menu");
	this->first3Keys[2].setString("Attack button");

	this->KeyInstruction[0].setString("access skills menu in game");
	this->KeyInstruction[1].setString("access inventory in game");
	this->KeyInstruction[2].setString("If instructions open, open craft menu");
	this->KeyInstruction[3].setString("acess missions menu in game");
	this->KeyInstruction[4].setString("access your reputation with factions");
	this->KeyInstruction[5].setString("action key - used to interact");
	this->KeyInstruction[6].setString("close dialogue key");

	this->skillsTitle[0].setString("Strength");
	this->skillsTitle[1].setString("Stamina");
	this->skillsTitle[2].setString("Endurance");
	this->skillsTitle[3].setString("Charisma");
	this->skillsTitle[4].setString("Knowledge");

	this->skillsInstruction[0].setString("Gained from weights bench");
	this->skillsInstruction[1].setString("Gained From exercise bike");
	this->skillsInstruction[2].setString("Gained by fighting");
	this->skillsInstruction[3].setString("Gained by talking");
	this->skillsInstruction[4].setString("Gained by reading books");

	this->routineInstruction[0].setString("Bed Time");
	this->routineInstruction[1].setString("Chow Time");
	this->routineInstruction[2].setString("Shower Time");
	this->routineInstruction[3].setString("Yard Time");
	this->routineInstruction[4].setString("Work Time");

	for (int i = 0; i < first3Keys.size(); i++) {
		first3Keys[i].setFont(keyFont);
		first3Keys[i].setCharacterSize(20); // setting the character size
		first3Keys[i].setFillColor(sf::Color(0, 0, 0));
	}
	for (int i = 0; i < KeyInstruction.size(); i++) {
		KeyInstruction[i].setFont(keyFont);
		KeyInstruction[i].setCharacterSize(20); // setting the character size
		KeyInstruction[i].setFillColor(sf::Color(0, 0, 0));
	}
	for (int i = 0; i < skillsTitle.size(); i++) {
		skillsTitle[i].setFont(keyFont);
		skillsTitle[i].setCharacterSize(20);
		skillsTitle[i].setFillColor(sf::Color(255, 0, 255));
	}
	for (int i = 0; i < skillsInstruction.size(); i++) {
		skillsInstruction[i].setFont(keyFont);
		skillsInstruction[i].setCharacterSize(20);
		skillsInstruction[i].setFillColor(sf::Color(0, 0, 0));
	}

	for (int i = 0; i < routineInstruction.size(); i++) {
		routineInstruction[i].setFont(keyFont);
		routineInstruction[i].setCharacterSize(20); // setting the character size
		routineInstruction[i].setFillColor(sf::Color(0, 0, 0));
	}
}

void Instructions::initTextures()
{
	if (!this->instructionsBackgroundTexture.loadFromFile("../assets/image_assets/InstructionsBackground.png")) {
		std::cout << "Error: loading SkillsBackground.png" << std::endl;
	}
	if (!this->keysTexture.loadFromFile("../assets/image_assets/KeysMenu.png")) {
		std::cout << "Load fail Error on keysTexture" << std::endl;
		system("pause");
	}
	if (!this->rotuineTexture.loadFromFile("../assets/image_assets/routinesMenu.png")) {
		std::cout << "Load fail Error on routine Texture" << std::endl;
		system("pause");
	}
}

void Instructions::initFont()
{
	if (!this->font.loadFromFile("../assets/text_assets/Font.ttf"))
	{
		// error...
		std::cout << "Error loading file" << std::endl;
		system("pause");
	}
	if (!this->keyFont.loadFromFile("../assets/text_assets/Font.ttf")) {
		std::cout << "Load fail Error on keyFont" << std::endl;
		system("pause");
	}
}

// Constructor / Destructor
Instructions::Instructions()
{
	this->initTextures();
	this->initVariables();
	this->initSprites();
	this->initText();
	this->initFont();
}

Instructions::~Instructions()
{
}

// Public Functions
void Instructions::keyHandler(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Up || key == sf::Keyboard::W) {
		Up();
		std::cout << "Up Pressed" << std::endl;
	}
	if (key == sf::Keyboard::Down || key == sf::Keyboard::S) {
		Down();
		std::cout << "Down Pressed" << std::endl;
	}
	if (key == sf::Keyboard::Return) {
		std::cout << "Return Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "Keys" << std::endl;
			state = keysState;

			break;
		case 1: std::cout << "Crafting" << std::endl;
			state = craftState;
			break;
		case 2: std::cout << "Skills" << std::endl;
			state = skillState;
			break;
		case 3: std::cout << "Routine" << std::endl;
			state = routineState;
			break;
		case 4: std::cout << "Back" << std::endl;
			backPressed();

			break;
		}
	}
}

void Instructions::KeysSubMenu(sf::RenderTarget &target) {
	std::cout << "Keys sub menu in action" << std::endl;

	keyBox.setPosition(target.getSize().x / 2 + 10, 20);

	first3Keys[0].setPosition(target.getSize().x / 2 + 100, 45);
	first3Keys[1].setPosition(target.getSize().x / 2 + 100, 110);
	first3Keys[2].setPosition(target.getSize().x / 2 + 100, 180);

	target.draw(keyBox);

	for (int i = 0; i < first3Keys.size(); i++) {
		target.draw(first3Keys[i]);
	}

	for (int i = 0; i < KeyInstruction.size(); i++) {
		KeyInstruction[i].setPosition(target.getSize().x / 2 + 100, target.getSize().y / 2 - 90 + (i * 40));
		target.draw(KeyInstruction[i]);
	}
}

void Instructions::CraftingSubMenu(sf::RenderTarget &target) {
	std::cout << "Crafting Sub Menu in action" << std::endl;
}

void Instructions::SkillsSubMenu(sf::RenderTarget &target) {
	std::cout << "SKills Sub Menu in action" << std::endl;

	//skillBox.setTexture(&skillTexture);
	//skillBox.setSize(sf::Vector2f(300, 500));
	//skillBox.setPosition(window.getSize().x / 2 + 10, 30);
	//window.draw(skillBox);

	for (int i = 0; i < skillsTitle.size(); i++) {
		skillsTitle[i].setPosition(target.getSize().x / 2 + 130, 30 + (i * 80));
		target.draw(skillsTitle[i]);
	}
	for (int i = 0; i < skillsInstruction.size(); i++) {
		skillsInstruction[i].setPosition(target.getSize().x / 2 + 130, 50 + (i * 80));
		target.draw(skillsInstruction[i]);
	}

}

void Instructions::RoutineSubMenu(sf::RenderTarget &target) {
	std::cout << "Routines Sub menu in action" << std::endl;

	routinesBox.setPosition(target.getSize().x / 2 + 10, 30);
	routineInstruction[0].setPosition(target.getSize().x / 2 + 100, 45);
	routineInstruction[1].setPosition(target.getSize().x / 2 + 130, 125);
	routineInstruction[2].setPosition(target.getSize().x / 2 + 100, 220);
	routineInstruction[3].setPosition(target.getSize().x / 2 + 120, 320);
	routineInstruction[4].setPosition(target.getSize().x / 2 + 130, 400);

	target.draw(routinesBox);
	for (int i = 0; i < routineInstruction.size(); i++) {
		target.draw(routineInstruction[i]);
	}
}

void Instructions::backPressed() {
	this->backPress = true;
}

void Instructions::mouseHandler(sf::RenderWindow &window) {
	sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button

		if (mousePos.x >= InstructionsMenuText[0].getPosition().x && mousePos.x <= InstructionsMenuText[0].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= InstructionsMenuText[0].getPosition().y && mousePos.y <= InstructionsMenuText[0].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Keys" << std::endl;
				state = keysState;
			}
		}

		if (mousePos.x >= InstructionsMenuText[1].getPosition().x && mousePos.x <= InstructionsMenuText[1].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= InstructionsMenuText[1].getPosition().y && mousePos.y <= InstructionsMenuText[1].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Crafting" << std::endl;
				state = craftState;
			}
		}
		if (mousePos.x >= InstructionsMenuText[2].getPosition().x && mousePos.x <= InstructionsMenuText[2].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= InstructionsMenuText[2].getPosition().y && mousePos.y <= InstructionsMenuText[2].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Skills" << std::endl;
				state = skillState;
			}
		}
		if (mousePos.x >= InstructionsMenuText[3].getPosition().x && mousePos.x <= InstructionsMenuText[3].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= InstructionsMenuText[3].getPosition().y && mousePos.y <= InstructionsMenuText[3].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Routine" << std::endl;
				state = routineState;
			}
		}

		if (mousePos.x >= InstructionsMenuText[4].getPosition().x && mousePos.x <= InstructionsMenuText[4].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= InstructionsMenuText[4].getPosition().y && mousePos.y <= InstructionsMenuText[4].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Exit Button pressed" << std::endl;
				backPressed();
			}
		} 
	}
}

void Instructions::Up() {
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Instructions::Down() {
	if (this->selectedItemIndex + 1 < Instructions_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Instructions::render(sf::RenderTarget &target) {
	target.draw(instructionsBackground);

	for (int i = 0; i < Instructions_item_Number; i++) {
		target.draw(InstructionsMenuText[i]);
	}
	if (state == keysState) { // drawing the menu's if the button is clicked and the state is changed
		KeysSubMenu(target);
	}
	if (state == craftState) {
		CraftingSubMenu(target);
	}
	if (state == skillState) {
		SkillsSubMenu(target);
	}
	if (state == routineState) {
		RoutineSubMenu(target);
	}
}
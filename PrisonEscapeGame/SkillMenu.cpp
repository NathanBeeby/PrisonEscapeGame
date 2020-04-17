#include "SkillMenu.h"
#include <iostream>
#include "HUD.h"

void SkillMenu::initVariables()
{
	// Integer Variables
	this->selectedItemIndex = 0;
	this->height = 600;
	this->width = 800;
	this->startSkillPoints = 10;
	// Boolean Variables
	this->exitPress = false;
	this->gamePress = false;

	if (!this->skillsBackgroundTexture.loadFromFile("../assets/image_assets/SkillsMenuBackground.png")) {
		std::cout << "Error: loading SkillsBackground.png" << std::endl;
	}

	this->skillsBackground.setSize(sf::Vector2f(this->width, this->height));
	this->skillsBackground.setPosition(0, 0);
	this->skillsBackground.setTexture(&this->skillsBackgroundTexture);
}

void SkillMenu::initFont()
{
	if (!this->font.loadFromFile("../assets/text_assets/Font.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}
}

SkillMenu::SkillMenu()
{
	this->initVariables();
	this->initFont();

	//set the background, draw it out
	SkillMenuText[0].setFont(font);
	SkillMenuText[0].setCharacterSize(35);
	SkillMenuText[0].setFillColor(sf::Color::Blue);
	SkillMenuText[0].setString("Strength");
	SkillMenuText[0].setPosition(sf::Vector2f(50, this->height / (skill_item_Number + 8) * 1)); // center item for width, have the amount of string items + 1, so that they're equally spaced out



	SkillMenuText[1].setFont(font);
	SkillMenuText[1].setCharacterSize(35);
	SkillMenuText[1].setFillColor(sf::Color::White);
	SkillMenuText[1].setString("Stamina");
	SkillMenuText[1].setPosition(sf::Vector2f(50, this->height / (skill_item_Number + 6) * 2.5)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[2].setFont(font);
	SkillMenuText[2].setCharacterSize(35);
	SkillMenuText[2].setFillColor(sf::Color::White);
	SkillMenuText[2].setString("Endurance");
	SkillMenuText[2].setPosition(sf::Vector2f(50, this->height / (skill_item_Number + 6) * 4)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[3].setFont(font);
	SkillMenuText[3].setCharacterSize(35);
	SkillMenuText[3].setFillColor(sf::Color::White);
	SkillMenuText[3].setString("Charisma");
	SkillMenuText[3].setPosition(sf::Vector2f(50, this->height / (skill_item_Number + 6) * 5.5)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[4].setFont(font);
	SkillMenuText[4].setCharacterSize(35);
	SkillMenuText[4].setFillColor(sf::Color::White);
	SkillMenuText[4].setString("Knowledge");
	SkillMenuText[4].setPosition(sf::Vector2f(50, this->height / (skill_item_Number + 6) * 7)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[5].setFont(font);
	SkillMenuText[5].setCharacterSize(60);
	SkillMenuText[5].setFillColor(sf::Color::White);
	SkillMenuText[5].setString("Exit");
	SkillMenuText[5].setPosition(sf::Vector2f(90, this->height - 100)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[6].setFont(font);
	SkillMenuText[6].setCharacterSize(60);
	SkillMenuText[6].setFillColor(sf::Color::White);
	SkillMenuText[6].setString("Game");
	SkillMenuText[6].setPosition(sf::Vector2f(this->width - 170, this->height - 100)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	selectedItemIndex = 0;
}


SkillMenu::~SkillMenu()
{
}




void SkillMenu::keyHandler(sf::Keyboard::Key key) {

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

		case 0: std::cout << "Strength pressed" << std::endl;
			if (this->player.getStrength() > 0) {
				this->player.removeStrength(1);
				startSkillPoints++;
				//	playerStrength--;
			}
			break;
		case 1: std::cout << "Stamina pressed" << std::endl;
			if (this->player.getStamina() > 0) {
				this->player.removeStamina(1);
				startSkillPoints++;
				//playerStamina--;
			}
			break;
		case 2: std::cout << "Endurance pressed" << std::endl;
			if (this->player.getArmour() > 0) {
				this->player.removeArmour(1);
				startSkillPoints++;
				//	playerArmour--;
			}
			break;
		case 3: std::cout << "Charisma pressed" << std::endl;
			if (this->player.getCharisma() > 0) {
				this->player.removeCharisma(1);
				startSkillPoints++;
				//	playerCharisma--;
			}
			break;
		case 4: std::cout << "Knowledge pressed" << std::endl;
			if (this->player.getKnowledge() > 0) {
				this->player.removeKnowledge(1);
				startSkillPoints++;
				//	playerKnowledge--;
			}
			break;

		}
	}
	if (key == sf::Keyboard::Right) {
		std::cout << "Right Pressed" << std::endl;
		switch (GetPressedItem()) {

		case 0: std::cout << "Strength pressed" << std::endl;
			if (startSkillPoints > 0) {
				this->player.addStrength(1);
				startSkillPoints--;
				//	playerStrength++;
			}
			break;
		case 1: std::cout << "Stamina pressed! Start Skill Points: " << startSkillPoints << std::endl;
			if (startSkillPoints != 0) {
				this->player.addStamina(1);
				std::cout << "Stamina: " << this->player.getStamina() << std::endl;
				startSkillPoints--;
				//	playerStamina++;
			}
			break;
		case 2: std::cout << "Endurance pressed" << std::endl;
			if (startSkillPoints != 0) {
				this->player.addArmour(1);
				startSkillPoints--;
				//	playerArmour++;
			}
			break;
		case 3: std::cout << "Charisma pressed" << std::endl;
			if (startSkillPoints != 0) {
				this->player.addCharisma(1);
				startSkillPoints--;
				//playerCharisma++;
			}
			break;
		case 4: std::cout << "Knowledge pressed" << std::endl;
			if (startSkillPoints != 0) {
				this->player.addKnowledge(1);
				startSkillPoints--;
				//playerKnowledge++;
			}
			break;

		}
	}

	if (key == sf::Keyboard::Return) {
		std::cout << "Return Pressed" << std::endl;
		switch (GetPressedItem()) {

		case 5: std::cout << "exit skill pressed" << std::endl;
			exitPressed();
			break;

		case 6: std::cout << "Game pressed" << std::endl;
			//GameState = Exit;
			gamePressed();
			break;
		}
	}
}

void SkillMenu::gamePressed() {
	if (startSkillPoints == 0) {
		gamePress = true; // do additional stuff here for creation of game and transition effect between menu maybe?
	}
}
void SkillMenu::exitPressed() {
	exitPress = true; // do stuff on exit here (destructor)
}


void SkillMenu::mouseHandler(sf::RenderWindow &window) {
	sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= SkillMenuText[5].getPosition().x && mousePos.x <= SkillMenuText[5].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= SkillMenuText[5].getPosition().y && mousePos.y <= SkillMenuText[5].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Exit Button pressed" << std::endl;
				exitPressed();

			}
		}
		if (mousePos.x >= SkillMenuText[6].getPosition().x && mousePos.x <= SkillMenuText[6].getPosition().x + 115) { // if the x position is on the first HUD button
			if (mousePos.y >= SkillMenuText[6].getPosition().y && mousePos.y <= SkillMenuText[6].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Game Button pressed" << std::endl;
				gamePressed();
			}
		}
	}
}

void SkillMenu::drawBars(sf::RenderTarget &target) {

	StrBar.setSize(sf::Vector2f(200, 20));
	StrBar.setFillColor(sf::Color(255, 0, 0));
	StrBar.setOutlineThickness(2);
	StrBar.setOutlineColor(sf::Color(0, 0, 0));

	StaBar.setSize(sf::Vector2f(200, 20));
	StaBar.setFillColor(sf::Color(255, 0, 0));
	StaBar.setOutlineThickness(2);
	StaBar.setOutlineColor(sf::Color(0, 0, 0));

	EnduranceBar.setSize(sf::Vector2f(200, 20));
	EnduranceBar.setFillColor(sf::Color(255, 0, 0));
	EnduranceBar.setOutlineThickness(2);
	EnduranceBar.setOutlineColor(sf::Color(0, 0, 0));

	ChaBar.setSize(sf::Vector2f(200, 20));
	ChaBar.setFillColor(sf::Color(255, 0, 0));
	ChaBar.setOutlineThickness(2);
	ChaBar.setOutlineColor(sf::Color(0, 0, 0));

	KnoBar.setSize(sf::Vector2f(200, 20));
	KnoBar.setFillColor(sf::Color(255, 0, 0));
	KnoBar.setOutlineThickness(2);
	KnoBar.setOutlineColor(sf::Color(0, 0, 0));

	Str.setSize(sf::Vector2f((this->player.getStrength() * 2), 20));
	Str.setFillColor(sf::Color(237, 221, 80));

	Sta.setSize(sf::Vector2f((this->player.getStamina() * 2), 20));
	Sta.setFillColor(sf::Color(32, 157, 234));

	Endurance.setSize(sf::Vector2f((this->player.getArmour() * 2), 20));
	Endurance.setFillColor(sf::Color(175, 219, 206));

	Cha.setSize(sf::Vector2f((this->player.getCharisma() * 2), 20));
	Cha.setFillColor(sf::Color(155, 71, 216));

	Kno.setSize(sf::Vector2f((this->player.getKnowledge() * 2), 20));
	Kno.setFillColor(sf::Color(70, 234, 60));

	StrBar.setPosition(200, SkillMenuText[0].getPosition().y + 20); // these are the empty stat bars
	StaBar.setPosition(200, SkillMenuText[1].getPosition().y + 20);
	EnduranceBar.setPosition(200, SkillMenuText[2].getPosition().y + 20);
	ChaBar.setPosition(200, SkillMenuText[3].getPosition().y + 20);
	KnoBar.setPosition(200, SkillMenuText[4].getPosition().y + 20);

	Str.setPosition(200, SkillMenuText[0].getPosition().y + 20); // setting the positions to the respective bars
	Sta.setPosition(200, SkillMenuText[1].getPosition().y + 20);
	Endurance.setPosition(200, SkillMenuText[2].getPosition().y + 20);
	Cha.setPosition(200, SkillMenuText[3].getPosition().y + 20);
	Kno.setPosition(200, SkillMenuText[4].getPosition().y + 20);

	sf::Text SkillpointsLeft;
	std::string SkillsString = std::to_string(startSkillPoints);

	SkillpointsLeft.setFont(font);
	SkillpointsLeft.setFillColor(sf::Color(0, 0, 0));
	SkillpointsLeft.setString("Skillpoints Left: " + SkillsString);
	SkillpointsLeft.setCharacterSize(35);
	SkillpointsLeft.setPosition(target.getSize().x / 2.5, 400);
	target.draw(SkillpointsLeft);

	if (startSkillPoints != 0) {
		target.draw(SpendPoints);
	}

	SpendPoints.setFont(font);
	SpendPoints.setFillColor(sf::Color(255, 0, 0));
	SpendPoints.setString("You have more \nSkillpoints to spend");
	SpendPoints.setCharacterSize(30);
	SpendPoints.setPosition(450, 100);

	target.draw(StrBar);
	target.draw(StaBar);
	target.draw(EnduranceBar);
	target.draw(ChaBar);
	target.draw(KnoBar);

	target.draw(Str);
	target.draw(Sta);
	target.draw(Endurance);
	target.draw(Cha);
	target.draw(Kno);

}

void SkillMenu::render(sf::RenderTarget &target) {
	target.draw(skillsBackground);
	drawBars(target);
	for (int i = 0; i < skill_item_Number; i++) {
		target.draw(SkillMenuText[i]);
	}


}

void SkillMenu::Up() {
	if (selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex--; //decrememnt the index
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void SkillMenu::Down() {
	if (selectedItemIndex + 1 < skill_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex++; // increment the index
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}






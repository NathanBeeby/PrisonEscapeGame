#include "guardDialogue.h"

// Initialization
void guardDialogue::initVariables()
{
	// Integer Variaables
	this->prisonInfo = 0;
	this->guardItemIndex = 0;
	this->offset = 12;
	//Boolean Variables
	this->dialogueCheck = false;
	this->mousePress = false;
	// Gamestate Variables
	this->guardDState = guardDialogueMenu; // setting the state for the dialogue
}

void guardDialogue::initSprites()
{
	DialogueBox.setSize(sf::Vector2f(400, 200));
	DialogueBox.setFillColor(sf::Color(239, 239, 167));
	DialogueBox.setOutlineThickness(2);
	DialogueBox.setOutlineColor(sf::Color(0, 0, 0, 255));

	cancelButton.setSize(sf::Vector2f(25, 25));
	cancelButton.setTexture(&cancelTexture);

	declineButton.setSize(sf::Vector2f(150, 50));
	declineButton.setTexture(&declineTexture);
	declineButton.setOutlineThickness(2);
	declineButton.setOutlineColor(sf::Color(0, 0, 0));

	acceptButton.setSize(sf::Vector2f(150, 50));
	acceptButton.setTexture(&acceptTexture);
	acceptButton.setOutlineThickness(2);
	acceptButton.setOutlineColor(sf::Color(0, 0, 0));
}

void guardDialogue::initText()
{
	this->GuardText[0].setFont(font);
	this->GuardText[0].setCharacterSize(50);
	this->GuardText[0].setFillColor(sf::Color::Blue);
	this->GuardText[0].setString("Talk");

	this->GuardText[1].setFont(font);
	this->GuardText[1].setCharacterSize(50);
	this->GuardText[1].setFillColor(sf::Color::Black);
	this->GuardText[1].setString("Snitch");

	this->GuardText[2].setFont(font);
	this->GuardText[2].setCharacterSize(50);
	this->GuardText[2].setFillColor(sf::Color::Black);
	this->GuardText[2].setString("Mission");

	this->GM.resize(7);
	this->GM[0] = "Go find me a cookie";
	this->GM[1] = "I need you to help break up a fight";
	this->GM[2] = "I need you to retrieve a guard uniform";
	this->GM[3] = "Find me hidden weapons";
	this->GM[4] = "Go find me some scrap metal";
	this->GM[5] = "Snitch on 5 prisoners";
	this->GM[6] = "Find some information for me";

}

void guardDialogue::initTextures()
{
	if (!this->cancelTexture.loadFromFile("../assets/image_assets/cancelButton.png")) {
		std::cout << "Load fail Error on cancel button Texture for prison dialogue" << std::endl;
		system("pause");
	}
	if (!this->acceptTexture.loadFromFile("../assets/image_assets/acceptButton.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");
	}
	if (!this->declineTexture.loadFromFile("../assets/image_assets/declineButton.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");
	}
}

void guardDialogue::initFont()
{
	if (!this->font.loadFromFile("../assets/text_assets/Font.ttf"))
	{
		std::cout << "Font File for guard dialogue could not be found" << std::endl;
		system("pause"); // pausing out on the console
	}
}


//Constructor / Destructor
guardDialogue::guardDialogue()
{
	this->initTextures();
	this->initVariables();
	this->initSprites();
	this->initText();
	this->initFont();
}

guardDialogue::~guardDialogue()
{

}


// public Functions
void guardDialogue::drawDialogueBox(sf::View &view, sf::RenderTarget& target) {
	DialogueBox.setPosition(view.getCenter().x - 200, view.getCenter().y + 80);

	target.draw(DialogueBox);
}

void guardDialogue::draw(sf::View &view, sf::RenderTarget& target) {
	std::vector<sf::RectangleShape>  BoxSegment(3, sf::RectangleShape(segBox)); // an array of 5 cell doors

	for (int i = 0; i < BoxSegment.size(); i++) {

		BoxSegment[i].setSize(sf::Vector2f(DialogueBox.getSize().x - 40, 50));
		BoxSegment[i].setFillColor(sf::Color(0, 213, 255));
		BoxSegment[i].setOutlineThickness(1);
		BoxSegment[i].setOutlineColor(sf::Color(0, 0, 0, 255));
	}

	BoxSegment[0].setPosition(DialogueBox.getPosition().x + 20, DialogueBox.getPosition().y + offset);
	BoxSegment[1].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[0].getPosition().y + offset + 50);
	BoxSegment[2].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[1].getPosition().y + offset + 50);

	for (int i = 0; i < BoxSegment.size(); i++) {
		target.draw(BoxSegment[i]);
	}
	GuardText[0].setPosition(view.getCenter().x - 20, view.getCenter().y + 80); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	GuardText[1].setPosition(view.getCenter().x - 30, view.getCenter().y + 140); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	GuardText[2].setPosition(view.getCenter().x - 40, view.getCenter().y + 200); // center item for width, have the amount of string items + 1, so that they're equally spaced out


	for (int i = 0; i < guard_item_Number; i++) {
		target.draw(GuardText[i]);
	}
}

void guardDialogue::Up() {
	if (guardItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		GuardText[guardItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		guardItemIndex--; //decrememnt the index
		GuardText[guardItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void guardDialogue::Down() {
	if (guardItemIndex + 1 < guard_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		GuardText[guardItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		guardItemIndex++; // increment the index
		GuardText[guardItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void guardDialogue::Talk(sf::View &view, sf::RenderTarget& target) {

	cancelButton.setPosition(view.getCenter().x + 155, view.getCenter().y + 240);

	std::vector<sf::Text>  talking(7, sf::Text(TalkDialogue)); // a vector for the dialogue

	talking[0].setString("Sometimes I hate this job.\n others, I really like it");
	talking[1].setString("Hey man, I'm more ganster\n than you");
	talking[2].setString("The food in chow is\n like 40% cardboard");
	talking[3].setString("Get out of my face.");
	talking[4].setString("If you don't leave me alone,\n you're getting a charge!");
	talking[5].setString("Your girlfriends probably\n out there with Jodie");
	talking[6].setString("Protect them Junies\n in the shower");

	for (int i = 0; i < talking.size(); i++) {
		talking[i].setFont(font);
		talking[i].setCharacterSize(30);
		talking[i].setFillColor(sf::Color(0, 0, 0));
		talking[i].setPosition(view.getCenter().x - 190, view.getCenter().y + 90);
	}

	if (talkInt == 0) { target.draw(talking[0]); }
	else if (talkInt == 1) { target.draw(talking[1]); }
	else if (talkInt == 2) { target.draw(talking[2]); }
	else if (talkInt == 3) { target.draw(talking[3]); }
	else if (talkInt == 4) { target.draw(talking[4]); }
	else if (talkInt == 5) { target.draw(talking[5]); }
	else if (talkInt == 6) { target.draw(talking[6]); }
	target.draw(cancelButton);
}

void guardDialogue::Snitch(sf::View &view, sf::RenderTarget& target) {
	std::vector<sf::Text>  snitching(4, sf::Text(TalkDialogue));

	snitching[0].setString("No information for guard");
	snitching[0].setPosition(view.getCenter().x - 100, view.getCenter().y + 90);
	snitching[1].setString("Guard: Get out of here, punk!");
	snitching[1].setPosition(view.getCenter().x - 100, view.getCenter().y + 140);

	snitching[2].setPosition(view.getCenter().x - 100, view.getCenter().y + 90);
	snitching[2].setString("You give the information to the guard");
	snitching[3].setPosition(view.getCenter().x - 100, view.getCenter().y + 140);
	snitching[3].setString("Guard: Nice Work!");


	for (int i = 0; i < snitching.size(); i++) {
		snitching[i].setFont(font);
		snitching[i].setCharacterSize(40);
		snitching[i].setFillColor(sf::Color(0, 0, 0));

	}
	if (prisonInfo == 0) {
		target.draw(snitching[0]);
		target.draw(snitching[1]);
	}
	else if (prisonInfo >= 1) {
		target.draw(snitching[2]);
		target.draw(snitching[3]);
		prisonInfo = 0;
	}

}

void guardDialogue::Mission(sf::View &view, sf::RenderTarget &target, GUI &gui) {

	declineButton.setPosition(view.getCenter().x + 25, view.getCenter().y + 225);


	acceptButton.setPosition(view.getCenter().x - 175, view.getCenter().y + 225);

	std::vector<sf::Text>  guardmissions(7, sf::Text(missionDialogue));

	guardmissions[0].setString(GM[0]);
	guardmissions[1].setString(GM[1]);
	guardmissions[2].setString(GM[2]);
	guardmissions[3].setString(GM[3]);
	guardmissions[4].setString(GM[4]);
	guardmissions[5].setString(GM[5]);
	guardmissions[6].setString(GM[6]);

	for (int i = 0; i < guardmissions.size(); i++) {
		guardmissions[i].setFont(font);
		guardmissions[i].setCharacterSize(40);
		guardmissions[i].setFillColor(sf::Color(0, 0, 0));
		guardmissions[i].setPosition(view.getCenter().x - 170, view.getCenter().y + 90);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "Mission Accepted" << std::endl; // use this for trade functionality later, give positive rep to player for accepting
		guardDState = guardDialogueMenu;
		gui.missions.push_back(guardmissions[missionsInt]);
		dialogueCheck = false;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		std::cout << "Mission Declined" << std::endl; // use this for trade functionality later,give negative rep to player for declining
		guardDState = guardDialogueMenu;
		dialogueCheck = false;
	}

	if (missionsInt == 0) { target.draw(guardmissions[0]); }
	else if (missionsInt == 1) { target.draw(guardmissions[1]); }
	else if (missionsInt == 2) { target.draw(guardmissions[2]); }
	else if (missionsInt == 3) { target.draw(guardmissions[3]); }
	else if (missionsInt == 4) { target.draw(guardmissions[4]); }
	else if (missionsInt == 5) { target.draw(guardmissions[5]); }
	else if (missionsInt == 6) { target.draw(guardmissions[6]); }


	target.draw(acceptButton);
	target.draw(declineButton);
}

void guardDialogue::dialogueHandler(sf::View &view, sf::RenderTarget &target, GUI &gui) {


	if (guardDState == guardDialogueMenu) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			Up();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			Down();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			switch (GetPressedItem()) {
			case 0: std::cout << "Talk" << std::endl;
				this->talkPressed(gui);
				break;
			case 1: std::cout << "Snitch" << std::endl;
				this->snitchPressed(target, gui);
				break;
			case 2: std::cout << "Missions" << std::endl;
				this->missionsPressed(target, gui);
				break;

			}
		}
	}

	if (guardDState == guardDialogueMenu) {
		drawDialogueBox(view, target);
		draw(view, target);

	}

	//GUARD___________________________________________________
	if (guardDState == guardTalk) {
		drawDialogueBox(view, target);
		Talk(view, target);

	}
	if (guardDState == snitching) {
		drawDialogueBox(view, target);
		Snitch(view, target);

	}
	if (guardDState == guardMissions) {
		drawDialogueBox(view, target);
		Mission(view, target, gui);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		guardDState = guardDialogueMenu;
		dialogueCheck = false;
	}

}

void guardDialogue::mouseHandler(sf::RenderWindow &window, GUI &gui)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		std::cout << "Clicked inside Box" << std::endl;

		// Accept Mission
		if (worldPos.x >= acceptButton.getPosition().x && worldPos.x <= acceptButton.getPosition().x + 200) {
			if (worldPos.y >= acceptButton.getPosition().y && worldPos.y <= acceptButton.getPosition().y + 50) {
				if (!mousePress) {
					std::cout << "Mission Accepted:" << missionsInt << std::endl; // use this for trade functionality later, give positive rep to player for accepting
					guardDState = guardDialogueMenu;
					//if(gui.missions.size() < 7){
					//gui.missions.push_back(missions[missionsInt]); // Breaks on pushback
					//}
					dialogueCheck = false;
				}
			}
		}
		// Decine Mission
		if (worldPos.x >= declineButton.getPosition().x && worldPos.x <= declineButton.getPosition().x + 200) {
			if (worldPos.y >= declineButton.getPosition().y && worldPos.y <= declineButton.getPosition().y + 50) {
				if (!mousePress) {
					std::cout << "Mission Declined" << std::endl; // use this for trade functionality later,give negative rep to player for declining
					guardDState = guardDialogueMenu;
					dialogueCheck = false;
				}
			}
		}
		if (worldPos.x >= GuardText[0].getPosition().x && worldPos.x <= GuardText[0].getPosition().x + 200) {
			if (worldPos.y >= GuardText[0].getPosition().y && worldPos.y <= GuardText[0].getPosition().y + 50) {
				if (!mousePress) {
					std::cout << "Talk Clicked" << std::endl;
					this->talkPressed(gui);
				}
			}
		}

		if (worldPos.x >= GuardText[1].getPosition().x && worldPos.x <= GuardText[1].getPosition().x + 200) {
			if (worldPos.y >= GuardText[1].getPosition().y && worldPos.y <= GuardText[1].getPosition().y + 50) {
				if (!mousePress) {
					std::cout << "Snitch Clicked" << std::endl;
					this->snitchPressed(window, gui);
				}
			}
		}

		if (worldPos.x >= GuardText[2].getPosition().x && worldPos.x <= GuardText[2].getPosition().x + 200) {
			if (worldPos.y >= GuardText[2].getPosition().y && worldPos.y <= GuardText[2].getPosition().y + 50) {
				if (!mousePress) {
					std::cout << "Missions Clicked" << std::endl;
					this->missionsPressed(window, gui);
				}
			}
		}
		// Close Button on Talk
		if (worldPos.x >= cancelButton.getPosition().x && worldPos.x <= cancelButton.getPosition().x + 200) {
			if (worldPos.y >= cancelButton.getPosition().y && worldPos.y <= cancelButton.getPosition().y + 50) {
				if (!mousePress) {
					guardDState = guardDialogueMenu;
					dialogueCheck = false;
				}
			}
		}
	}
	else {
		mousePress = false;
	}
}

void guardDialogue::talkPressed(GUI & gui)
{
	gui.guardRep += 2;
	guardDState = guardTalk; // setting the state to guard talk
	talkInt = rand() % 6;
	gui.charIncrement += 1;

}

void guardDialogue::snitchPressed(sf::RenderTarget & target, GUI & gui)
{
	if (gui.guardRep > 30) {
		gui.prisonerRep -= 10;
		gui.guardRep += 5;
		guardDState = snitching; // setting the state to snitching
		gui.guardRep += 10;
	}
	else {
		std::cout << "You need at least 20 guard rep to do this" << std::endl;
		repText.setString("You need a higher guard reputation");
		repText.setFont(font);
		repText.setCharacterSize(40);
		repText.setFillColor(sf::Color(0, 0, 255));
		repText.setPosition(DialogueBox.getPosition().x + 80, DialogueBox.getPosition().y - 50);
		target.draw(repText);
	}
}

void guardDialogue::missionsPressed(sf::RenderTarget & target, GUI & gui)
{
	if (gui.guardRep > 60) {
		gui.guardRep += 7;
		gui.prisonerRep -= 7;
		guardDState = guardMissions; //setting the state to guard missions
		missionsInt = rand() % 6;
	}
	else {
		std::cout << "You need 40 guard rep to do this" << std::endl;
		sf::Text repText;
		repText.setString("You need a higher guard reputation");
		repText.setFont(font);
		repText.setCharacterSize(40);
		repText.setFillColor(sf::Color(0, 0, 255));
		repText.setPosition(DialogueBox.getPosition().x + 80, DialogueBox.getPosition().y - 50);
		target.draw(repText);
	}
}

void guardDialogue::update(sf::Time deltaTime)
{
}

void guardDialogue::render(sf::RenderTarget &target)
{
}

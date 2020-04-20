#include "GUI.h"

// Initialization
void GUI::initVariables()
{
	//reputation
	this->guardRep = 100;
	this->prisonerRep = 100;
	//Int variables
	this->MisOpenCount = 0;
	this->InvOpenCount = 0;
	this->SkilOpenCount = 0;
	this->RepOpenCount = 0;
	this->craftOpenCount = 0;
	this->GUITime = 0;
	this->GUITimeMinute = 0;
	this->day = 0;
	this->prisonMoney = 0;
	this->GUITimeMinute = 0;
	this->minute = 60;

	//float variables
	this->healthBar = 210;
	this->XPcount = 0;
	this->HUDopacity = 150;
	this->maxXP = 210; //create a system where the maxXP costs more each level of the players health
	this->night = 100; // box hue
					   //boolean variables
	this->yardTime = false;
	this->chowTime = false;
	this->showerTime = false;
	this->workTime = false;
	this->freeTime = false;
	this->bedTime = false;
	this->MisOpen = false;
	this->SkilOpen = false;
	this->InvOpen = false;
	this->RepOpen = false;
	this->craftOpen = false;
	this->mousePress = false;
	//String
	this->prisonerFile = "../assets/text_assets/prisoners.txt";
}

void GUI::initTextures()
{
	if (!this->characterTexture.loadFromFile("../assets/image_assets/sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->font.loadFromFile("../assets/text_assets/Font.ttf")) {
		std::cout << "Load fail Error on HUDFont" << std::endl;
		system("pause");
	}
	if (!this->playerTexture.loadFromFile("../assets/image_assets/sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->Skills.loadFromFile("../assets/image_assets/Skills.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->Inventory.loadFromFile("../assets/image_assets/Inventory.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->Missions.loadFromFile("../assets/image_assets/Missions.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->halfHealthPlayer.loadFromFile("../assets/image_assets/halfHealth_sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->lowHealthPlayer.loadFromFile("../assets/image_assets/lowHealth_sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!this->poundTexture.loadFromFile("../assets/image_assets/PrisonPound.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
}

void GUI::initSprites()
{
	InvSlot.resize(8);

	InventoryBox.setSize(sf::Vector2f(250, 420));
	InventoryBox.setFillColor(sf::Color(55, 55, 55, HUDopacity));
	InventoryBox.setOutlineThickness(2);
	InventoryBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	characterBox.setSize(sf::Vector2f(150, 195));
	//characterBox.setFillColor(sf::Color(15, 15, 15, HUDopacity));
	characterBox.setTexture(&characterTexture);
	characterBox.setOutlineThickness(1);
	characterBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	MissionsBox.setSize(sf::Vector2f(250, 400));
	MissionsBox.setFillColor(sf::Color(242, 232, 171, HUDopacity));
	MissionsBox.setOutlineThickness(2);
	MissionsBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	SkillsBox.setSize(sf::Vector2f(250, 370));
	SkillsBox.setFillColor(sf::Color(100, 100, 100, HUDopacity));
	SkillsBox.setOutlineThickness(2);
	SkillsBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	StrengthBar.setSize(sf::Vector2f(200, 20));
	StrengthBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	StrengthBar.setOutlineThickness(2);
	StrengthBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Strength.setFillColor(sf::Color(237, 221, 80, HUDopacity));

	StaminaBar.setSize(sf::Vector2f(200, 20));
	StaminaBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	StaminaBar.setOutlineThickness(2);
	StaminaBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Stamina.setFillColor(sf::Color(32, 157, 234, HUDopacity));

	ArmourBar.setSize(sf::Vector2f(200, 20));
	ArmourBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	ArmourBar.setOutlineThickness(2);
	ArmourBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Armour.setFillColor(sf::Color(175, 219, 206, HUDopacity));

	CharismaBar.setSize(sf::Vector2f(200, 20));
	CharismaBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	CharismaBar.setOutlineThickness(2);
	CharismaBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Charisma.setFillColor(sf::Color(155, 71, 216, HUDopacity));

	KnowledgeBar.setSize(sf::Vector2f(200, 20));
	KnowledgeBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	KnowledgeBar.setOutlineThickness(2);
	KnowledgeBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Knowledge.setFillColor(sf::Color(70, 234, 60, HUDopacity));


	for (int i = 0; i < InvSlot.size(); i++) {
		InvSlot[i].setSize(sf::Vector2f(40, 45));
		InvSlot[i].setOutlineThickness(1);
		InvSlot[i].setFillColor(sf::Color(15, 15, 15, HUDopacity));
		InvSlot[i].setOutlineColor(sf::Color(0, 0, 0, HUDopacity));


	}

	CraftButton.setSize(sf::Vector2f(210, 100));
	CraftButton.setOutlineThickness(1);
	CraftButton.setFillColor(sf::Color(15, 15, 15, HUDopacity));
	CraftButton.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	emptyGRep.setSize(sf::Vector2f(200, 20));
	emptyGRep.setFillColor(sf::Color(0, 0, 255, HUDopacity));
	emptyGRep.setOutlineThickness(2);
	emptyGRep.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	GRep.setSize(sf::Vector2f(guardRep, 20));
	GRep.setFillColor(sf::Color(0, 128, 255, HUDopacity));

	emptyPRep.setSize(sf::Vector2f(200, 20));
	emptyPRep.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	emptyPRep.setOutlineThickness(2);
	emptyPRep.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	PRep.setSize(sf::Vector2f(prisonerRep, 20));
	PRep.setFillColor(sf::Color(255, 51, 51, HUDopacity));

	prisonPound.setSize(sf::Vector2f(50, 50));
	prisonPound.setTexture(&poundTexture);

	CashBox.setSize(sf::Vector2f(150, 70));
	CashBox.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	CashBox.setOutlineThickness(2);
	CashBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	PlayerIcon.setRadius(35);

	PlayerIcon.setTextureRect(sf::IntRect(0, 0, 50, 100));
	PlayerIcon.setOutlineThickness(1);
	PlayerIcon.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	PlayerBox.setSize(sf::Vector2f(310, 150));
	PlayerBox.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	PlayerBox.setOutlineThickness(2);
	PlayerBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	noHealth.setSize(sf::Vector2f(210, 20));
	noHealth.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	noHealth.setOutlineThickness(2);
	noHealth.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	health.setSize(sf::Vector2f(healthBar, 20));
	health.setFillColor(sf::Color(0, 255, 0, HUDopacity));
	ArmourAddition.setFillColor(sf::Color(155, 155, 155));

	noXP.setSize(sf::Vector2f(210, 20));
	noXP.setFillColor(sf::Color(100, 100, 100, HUDopacity));
	noXP.setOutlineThickness(2);
	noXP.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	XP.setSize(sf::Vector2f(XPcount, 20));
	XP.setFillColor(sf::Color(234, 149, 37, HUDopacity));

	box.setSize(sf::Vector2f(50, 50));
	box.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box.setTexture(&Missions);
	box.setOutlineThickness(1);
	box.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	box1.setSize(sf::Vector2f(50, 50));
	box1.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box1.setTexture(&Skills);
	box1.setOutlineThickness(1);
	box1.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	box2.setSize(sf::Vector2f(50, 50));
	box2.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box2.setTexture(&Inventory);
	box2.setOutlineThickness(1);
	box2.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	clockOuterBox.setSize(sf::Vector2f(170, 130));
	clockOuterBox.setOutlineThickness(2);
	clockOuterBox.setFillColor(sf::Color(155, 155, 155, HUDopacity));
	clockOuterBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	date.setSize(sf::Vector2f(150, 30));
	date.setOutlineThickness(2);
	date.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	date.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	clockDigital.setSize(sf::Vector2f(150, 30));
	clockDigital.setOutlineThickness(2);
	clockDigital.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	clockDigital.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	routineBox.setSize(sf::Vector2f(150, 30));
	routineBox.setOutlineThickness(2);
	routineBox.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	routineBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	CraftBox.setSize(sf::Vector2f(250, 250));
	CraftBox.setOutlineThickness(1);
	CraftBox.setFillColor(sf::Color(15, 15, 15, HUDopacity));
	CraftBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	submitCraft.setSize(sf::Vector2f(210, 75));
	submitCraft.setOutlineThickness(1);
	submitCraft.setFillColor(sf::Color(15, 15, 15, HUDopacity));
	submitCraft.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	daynight.setSize(sf::Vector2f(800, 600));
	daynight.setFillColor(sf::Color(0, 0, 255, night));
	daynight.setOrigin(400, 300);
}

void GUI::initText()
{
	MissionsHeader.setFont(font);
	MissionsHeader.setFillColor(sf::Color(0, 0, 0, HUDopacity));
	MissionsHeader.setString("Missions");
	MissionsHeader.setCharacterSize(30);

	SkillsText.setFont(font);
	SkillsText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	SkillsText.setString("Skills");
	SkillsText.setCharacterSize(25);

	strengthText.setFont(font);
	strengthText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	strengthText.setCharacterSize(30);

	staminaText.setFont(font);
	staminaText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	staminaText.setCharacterSize(30);

	armourText.setFont(font);
	armourText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	armourText.setCharacterSize(30);

	charismaText.setFont(font);
	charismaText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	charismaText.setCharacterSize(30);

	knowledgeText.setFont(font);
	knowledgeText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	knowledgeText.setCharacterSize(30);

	InventoryText.setFont(font);
	InventoryText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	InventoryText.setString("Inventory");
	InventoryText.setCharacterSize(25);

	CraftText.setFont(font);
	CraftText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	CraftText.setString("Crafting");
	CraftText.setCharacterSize(30);

	this->moneyString = std::to_string(prisonMoney);
	moneyText.setFont(font);
	moneyText.setString(moneyString);
	moneyText.setFillColor(sf::Color(0, 0, 0));

	HealthText.setFont(font);
	HealthText.setString("Health");
	HealthText.setCharacterSize(22);

	XPText.setFont(font);
	XPText.setString("XP");
	XPText.setCharacterSize(22);

	dayText.setFont(font);
	dayText.setFillColor(sf::Color(0, 0, 0));

	TimerText.setFont(font);
	TimerText.setFillColor(sf::Color(0, 0, 0));

	LevelText.setFont(font); // level text under the character icon
	LevelText.setString("Level:");
	LevelText.setCharacterSize(35);

	this->lvlString = std::to_string(this->player.getLevel());
	LevelString.setFont(font);
	LevelString.setString(lvlString);
	LevelString.setCharacterSize(35);

	submitText.setFont(font);
	submitText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	submitText.setString("Craft Item");
	submitText.setCharacterSize(30);
}

void GUI::initGUI()
{
}

// Constructor / Destructor
GUI::GUI() {
	this->initTextures();
	this->initVariables();
	this->initSprites();
	this->initText();
}

GUI::~GUI()
{


}


void GUI::MouseInput(sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (worldPos.y >= box.getPosition().y && worldPos.y <= box.getPosition().y + box.getSize().y) { // if the y position is between the HUD button																							
			if (worldPos.x >= box.getPosition().x && worldPos.x <= box.getPosition().x + box.getSize().x) { // if the x position is on the first HUD button
					//Box 1
				if (!mousePress) {
					std::cout << "Missions" << std::endl;
					missionsOpening();
				}
			}

			if (worldPos.x >= box1.getPosition().x && worldPos.x <= box1.getPosition().x + box1.getSize().x) { // if the x position is on the first HUD button
					//Box 2
				if (!mousePress) {
					std::cout << "Skills" << std::endl;
					skillsOpening();
				}
			}

			if (worldPos.x >= box2.getPosition().x && worldPos.x <= box2.getPosition().x + box2.getSize().x) { // if the x position is on the first HUD button
					//Box 3
				if (!mousePress) {
					std::cout << "Inventory" << std::endl;
					inventoryOpening();
				}
			}
		}
		//this->mousePress = true;
	}
	else {
		mousePress = false;
	}
}

void GUI::craftingMouseInput(sf::RenderWindow &window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button

		if (worldPos.x >= CraftButton.getPosition().x && worldPos.x <= CraftButton.getPosition().x + CraftButton.getSize().x) {
			if (worldPos.y >= CraftButton.getPosition().y && worldPos.y <= CraftButton.getPosition().y + CraftButton.getSize().y) {
				if (!mousePress) {
					std::cout << "Inside craft button" << std::endl;
					craftingOpening();
				}
			}
		}

		if (worldPos.x >= CraftBox.getPosition().x && worldPos.x <= CraftBox.getPosition().x + CraftBox.getSize().x) {
			if (worldPos.y >= CraftBox.getPosition().y && worldPos.y <= CraftBox.getPosition().y + CraftBox.getSize().y) {
				if (!mousePress) {
					std::cout << "Inside Craft Box" << std::endl;
					craftButtonClicked();
				}
			}
		}
		this->mousePress = true;
	}
	else {
		mousePress = false;
	}
}
// Public Functions
void GUI::skillsOpening() {
	if (MisOpen == false && InvOpen == false) {
		SkilOpenCount++; // incrementing to know if the player has hit the key a second time	

		if ((SkilOpen = true) && SkilOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
			std::cout << "skills Closed" << std::endl;
			SkilOpenCount = 0;
			SkilOpen = false; // shutting the Missions screen down
		}
		else {
			std::cout << "skills Open" << std::endl;
			SkilOpen = true; // opening missions screen, drawing it to screen
		}
	}
}
void GUI::missionsOpening() {
	if (SkilOpen == false && InvOpen == false) {
		MisOpenCount++; // incrementing to know if the player has hit the key a second time	

		if ((MisOpen = true) && MisOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
			std::cout << "Missions Closed" << std::endl;
			MisOpenCount = 0;
			MisOpen = false; // shutting the Missions screen down
		}
		else {
			std::cout << "Missions Open" << std::endl;
			MisOpen = true; // opening missions screen, drawing it to screen
		}
	}
}
void GUI::inventoryOpening() {
	if (SkilOpen == false && MisOpen == false) {
		InvOpenCount++; // incrementing to know if the player has hit the key a second time	

		if ((InvOpen = true) && InvOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
			std::cout << "Inventory Closed" << std::endl;
			InvOpenCount = 0;
			InvOpen = false; // shutting the Missions screen down
		}
		else {
			std::cout << "Inventory Open" << std::endl;
			InvOpen = true; // opening missions screen, drawing it to screen

		}
	}
}
void GUI::reputationOpening() {
	RepOpenCount++; // incrementing to know if the player has hit the key a second time	

	if ((RepOpen = true) && RepOpenCount >= 2) { // if the repOpenCount is 2, return the value back to 0, and turn the reputation open screen to false, to stop drawing
		std::cout << "Reputation Closed" << std::endl;
		RepOpenCount = 0;
		RepOpen = false; // shutting the Missions screen down
	}
	else {
		std::cout << "Reputation Open" << std::endl;
		RepOpen = true; // opening missions screen, drawing it to screen
	}
}
void GUI::craftingOpening() {
	if (InvOpen == true) {
		craftOpenCount++;
		if ((craftOpen = true) && craftOpenCount >= 2) {
			craftOpenCount = 0;
			craftOpen = false;
		}
		else {
			craftOpen = true;
		}
	}
}

void GUI::craftButtonClicked() {
	//std::cout << "Crafted Something" << std::endl;
	craftOpen = false;
	InvOpen = false;
}

void GUI::Times(sf::View &view, sf::RenderTarget& target) {
	std::vector<sf::Text>  routine(6, sf::Text(RoutineDialogue)); // an array of 5 cell doorsa

	routine[0].setString("Chow Time");
	routine[1].setString("Work Time");
	routine[2].setString("Shower Time");
	routine[3].setString("Yard Time");
	routine[4].setString("Bed Time");
	routine[5].setString("Free Time");



	for (int i = 0; i < routine.size(); i++) {
		routine[i].setFont(font);
		routine[i].setCharacterSize(30);
		routine[i].setFillColor(sf::Color(255, 255, 255));
		routine[i].setPosition(view.getCenter().x + 260, view.getCenter().y - 208);
	}

	if (GUITimeMinute >= 0 && GUITimeMinute <= 6) { // if between 0 - 7
		target.draw(routine[4]); // bed time
		bedTime = true;

	}
	else if (GUITimeMinute >= 7 && GUITimeMinute <= 7) { // if 8
		target.draw(routine[0]); // chow time
		bedTime = false;
		chowTime = true;
	}
	else if (GUITimeMinute >= 8 && GUITimeMinute <= 8) { // if 8
		target.draw(routine[3]); // yard time
		chowTime = false;
		yardTime = true;
	}
	else if (GUITimeMinute >= 9 && GUITimeMinute <= 12) { // if 9-12
		target.draw(routine[1]); // work
		yardTime = false;
		workTime = true;

	}
	else if (GUITimeMinute >= 13 && GUITimeMinute <= 13) { // if 13
		target.draw(routine[0]); // chow time
		workTime = false;
		chowTime = true;

	}
	else if (GUITimeMinute >= 14 && GUITimeMinute <= 17) { // if 14-17
		target.draw(routine[1]); // work time
		chowTime = false;
		workTime = true;
	}
	else if (GUITimeMinute >= 18 && GUITimeMinute <= 18) { // if 18
		target.draw(routine[0]); // chow time
		workTime = false;
		chowTime = true;

	}
	else if (GUITimeMinute >= 19 && GUITimeMinute <= 19) { // if 19
		target.draw(routine[2]); // shower time
		chowTime = false;
		showerTime = true;

	}
	else if (GUITimeMinute > 19 && GUITimeMinute <= 22) { // if 20-22
		target.draw(routine[5]);// free time
		showerTime = false;
		freeTime = true;

	}
	else if (GUITimeMinute >= 23 && GUITimeMinute <= 23) { // if 23
		target.draw(routine[4]);//bedtime
		freeTime = false;
		bedTime = true;
	}

} // THIS CAN BE REMOVED OR CHANGED AFTER ENUMERATIONS ADDED

void GUI::drawInventory(sf::View &view, sf::RenderTarget& target) {
	InventoryBox.setPosition(view.getCenter().x + 140, view.getCenter().y - 150);
	InvSlot[0].setPosition(InventoryBox.getPosition().x + 160, InventoryBox.getPosition().y + 70);
	InvSlot[1].setPosition(InvSlot[0].getPosition().x, InvSlot[0].getPosition().y + 50);
	InvSlot[2].setPosition(InvSlot[1].getPosition().x, InvSlot[1].getPosition().y + 50);
	InvSlot[3].setPosition(InvSlot[2].getPosition().x, InvSlot[2].getPosition().y + 50);
	InvSlot[4].setPosition(InventoryBox.getPosition().x + 205, InventoryBox.getPosition().y + 70);
	InvSlot[5].setPosition(InvSlot[4].getPosition().x, InvSlot[4].getPosition().y + 50);
	InvSlot[6].setPosition(InvSlot[5].getPosition().x, InvSlot[5].getPosition().y + 50);
	InvSlot[7].setPosition(InvSlot[6].getPosition().x, InvSlot[6].getPosition().y + 50);
	for (int i = 0; i < InvSlot.size(); i++) {
		target.draw(InvSlot[i]);
	}
	for (int i = 0; i < EmptySlot.size(); i++) {
		EmptySlot[i].setPosition(InvSlot[i].getPosition().x, InvSlot[i].getPosition().y);
		EmptySlot[i].setTexture(&EmptyTexture[i]); // setting the texture to the texture set in the inventory items class
		target.draw(EmptySlot[i]);
	}

	characterBox.setPosition(InventoryBox.getPosition().x + 5, InventoryBox.getPosition().y + 70);
	CraftButton.setPosition(InventoryBox.getPosition().x + 20, InventoryBox.getPosition().y + 280);
	InventoryText.setPosition(InventoryBox.getPosition().x + 50, InventoryBox.getPosition().y + 10);
	CraftText.setPosition(CraftButton.getPosition().x + 50, CraftButton.getPosition().y + 30);

	target.draw(InventoryBox);
	target.draw(InventoryText);
	target.draw(characterBox);
	target.draw(CraftButton);
	target.draw(CraftText);

}
void GUI::drawReputation(sf::View &view, sf::RenderTarget& target) {
	emptyGRep.setPosition(view.getCenter().x - 70, view.getCenter().y - 200);
	GRep.setPosition(view.getCenter().x - 70, view.getCenter().y - 200);

	emptyPRep.setPosition(view.getCenter().x - 70, view.getCenter().y - 170);
	PRep.setPosition(view.getCenter().x - 70, view.getCenter().y - 170);

	if (prisonerRep <= 0) {
		prisonerRep = 0;
	}
	if (prisonerRep >= 200) {
		prisonerRep = 200;
	}

	if (guardRep <= 0) {
		guardRep = 0;
	}
	if (guardRep >= 200) {
		guardRep = 200;
	}

	target.draw(emptyGRep);
	target.draw(GRep);
	target.draw(emptyPRep);
	target.draw(PRep);
}
void GUI::drawGUI(sf::View &view, sf::RenderTarget& target) {
	if (XPcount >= maxXP) {
		XPcount = 0;
		this->player.addLevel(1); // incrementing the player level if the XP count is more than the max required XP
		healthBar += 20; // increasing the health of the player slightly, unless they have full health
		std::cout << this->player.getLevel() << std::endl;
	}

	if (healthBar >= 210) { // if the health is more than the maximum, keep it at the max HP(cant go over max HP)
		healthBar = 210;
	}
	if (this->player.getLevel() >= 100) {
		this->player.setLevel(100); //the maximum level is 100
	}

	//if (charIncrement >= 10) {
	//	this->player.addCharisma(1);
	//	charIncrement = 0;
	//	std::cout << "playerCharisma += 1" << std::endl;
	//}
	//Routine routine;

	prisonPound.setPosition(view.getCenter().x - 25, view.getCenter().y - 280);
	moneyText.setPosition(view.getCenter().x + 45, view.getCenter().y - 275);
	CashBox.setPosition(view.getCenter().x - 35, view.getCenter().y - 290);
	HealthText.setPosition(view.getCenter().x - 230, view.getCenter().y - 284);
	XPText.setPosition(view.getCenter().x - 220, view.getCenter().y - 254);
	dayText.setPosition(view.getCenter().x + 235, view.getCenter().y - 285);
	TimerText.setPosition(view.getCenter().x + 235, view.getCenter().y - 245);
	LevelText.setPosition(view.getCenter().x - 370, view.getCenter().y - 220);
	LevelString.setPosition(view.getCenter().x - 370, view.getCenter().y - 190);
	ArmourAddition.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);
	PlayerIcon.setPosition(view.getCenter().x - 380, view.getCenter().y - 280);
	PlayerBox.setPosition(view.getCenter().x - 390, view.getCenter().y - 290);
	noHealth.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);
	health.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);
	noXP.setPosition(view.getCenter().x - 300, view.getCenter().y - 250);
	XP.setPosition(view.getCenter().x - 300, view.getCenter().y - 250);
	box.setPosition(view.getCenter().x - 160, view.getCenter().y - 220); //view.getCenter().x - 160, view.getCenter().y - 220
	box1.setPosition(view.getCenter().x - 220, view.getCenter().y - 220);
	box2.setPosition(view.getCenter().x - 280, view.getCenter().y - 220);
	clockOuterBox.setPosition(view.getCenter().x + 220, view.getCenter().y - 290);
	date.setPosition(view.getCenter().x + 230, view.getCenter().y - 280);
	clockDigital.setPosition(view.getCenter().x + 230, view.getCenter().y - 240);
	routineBox.setPosition(view.getCenter().x + 230, view.getCenter().y - 200);
	daynight.setPosition(view.getCenter()); //setting the day night to the view

	std::string MinutesString = std::to_string(GUITimeMinute);
	std::string SecondsString = std::to_string(GUITime);
	std::string dayString = std::to_string(day);

	dayText.setString("Day : " + dayString);
	if (GUITimeMinute <= 9 && GUITime <= 9) { // if both HUDTime and HUDTimeMinute is less than 9, put a 0 before both 
		TimerText.setString("0" + MinutesString + " : 0" + SecondsString);
	}
	else if (GUITime <= 9) { // if the HUDTime seconds is less than 9, have a 0 before the number, so it's digital time
		TimerText.setString(MinutesString + " : 0" + SecondsString);
	}
	else if (GUITimeMinute <= 9) { // ig HUDTimeMinute is less than 9, but a 0 before the minutes
		TimerText.setString("0" + MinutesString + " : " + SecondsString);
	}
	else {
		TimerText.setString(MinutesString + " : " + SecondsString);

	}

	if (healthBar >= 110) {
		PlayerIcon.setTexture(&playerTexture);
	}
	else if (healthBar >= 40 && healthBar <= 110) {
		PlayerIcon.setTexture(&halfHealthPlayer);
	}
	else {
		PlayerIcon.setTexture(&lowHealthPlayer);
	}
	ArmourAddition.setSize(sf::Vector2f((this->player.getArmour() * 2), 20));

	target.draw(daynight);

	target.draw(PlayerBox);
	target.draw(box);
	target.draw(box1);
	target.draw(box2);
	target.draw(PlayerIcon);
	target.draw(noHealth);
	target.draw(health);
	target.draw(ArmourAddition);
	target.draw(noXP);
	target.draw(XP);

	target.draw(clockOuterBox);
	target.draw(CashBox);
	target.draw(date);
	target.draw(clockDigital);
	target.draw(routineBox);

	target.draw(HealthText);
	target.draw(XPText);
	target.draw(TimerText);
	target.draw(dayText);
	target.draw(LevelText);
	target.draw(LevelString);
	target.draw(prisonPound);
	target.draw(moneyText);

	Times(view, target);
}
void GUI::drawCraft(sf::View &view, sf::RenderTarget& target) {
	CraftBox.setPosition(view.getCenter().x - 150, view.getCenter().y - 120);
	submitCraft.setPosition(CraftBox.getPosition().x + 20, CraftBox.getPosition().y + 150);
	submitText.setPosition(submitCraft.getPosition().x + 40, submitCraft.getPosition().y + 20);

	std::vector<sf::RectangleShape>  inputBox(4, sf::RectangleShape(craftInputBox)); // an array of 5 cell doorsa

	for (int i = 0; i < inputBox.size(); i++) {
		inputBox[i].setSize(sf::Vector2f(50, 50));
		inputBox[i].setOutlineThickness(1);
		inputBox[i].setFillColor(sf::Color(15, 15, 15, HUDopacity));
		inputBox[i].setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
		//inputBox[i].setTexture(&cellTexture);

	}

	inputBox[0].setPosition(CraftBox.getPosition().x + 80, CraftBox.getPosition().y + 20);
	inputBox[1].setPosition(CraftBox.getPosition().x + 130, CraftBox.getPosition().y + 20);
	inputBox[2].setPosition(CraftBox.getPosition().x + 80, CraftBox.getPosition().y + 70);
	inputBox[3].setPosition(CraftBox.getPosition().x + 130, CraftBox.getPosition().y + 70);



	if (craftOpen = true) {
		target.draw(CraftBox);
		target.draw(submitCraft);
		target.draw(submitText);
		for (int i = 0; i < inputBox.size(); i++) {
			target.draw(inputBox[i]);
		}
	}

} // NEEDS WORK
void GUI::drawMissions(sf::View &view, sf::RenderTarget& target) {
	MissionsBox.setPosition(view.getCenter().x - 125, view.getCenter().y - 130);
	MissionsHeader.setPosition(MissionsBox.getPosition().x + 50, MissionsBox.getPosition().y + 20);


	target.draw(MissionsBox);
	target.draw(MissionsHeader);
	for (int i = 0; i < missions.size(); i++) {
		std::cout << "Mission Size: " << missions.size() << std::endl;
		missions[i].setCharacterSize(25);
		missions[i].setPosition(view.getCenter().x - 115, (view.getCenter().y - 70) + (i * 20));
		target.draw(missions[i]);
	}
}
void GUI::drawSkills(sf::View &view, sf::RenderTarget& target) {
	this->StrengthString = std::to_string(this->player.getStrength()); // converting the int to string, so player knows the stats
	this->StaminaString = std::to_string(this->player.getStamina());
	this->ArmourString = std::to_string(this->player.getArmour());
	this->CharismaString = std::to_string(this->player.getCharisma());
	this->KnowledgeString = std::to_string(this->player.getKnowledge());

	Strength.setSize(sf::Vector2f((this->player.getStrength() * 2), 20));
	Stamina.setSize(sf::Vector2f((this->player.getStamina() * 2), 20));
	Armour.setSize(sf::Vector2f((this->player.getArmour() * 2), 20));
	Charisma.setSize(sf::Vector2f((this->player.getCharisma() * 2), 20));
	Knowledge.setSize(sf::Vector2f((this->player.getKnowledge() * 2), 20));

	strengthText.setString("Strength: " + StrengthString);
	staminaText.setString("Stamina: " + StaminaString);
	armourText.setString("Endurance: " + ArmourString);
	charismaText.setString("Charisma: " + CharismaString);
	knowledgeText.setString("Knowledge: " + KnowledgeString);

	SkillsBox.setPosition(view.getCenter().x - 390, view.getCenter().y - 130);
	StrengthBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 85); // these are the empty stat bars
	StaminaBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 145);
	ArmourBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 205);
	CharismaBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 265);
	KnowledgeBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 325);

	Strength.setPosition(StrengthBar.getPosition().x, StrengthBar.getPosition().y); // setting the positions to the respective bars
	Stamina.setPosition(StaminaBar.getPosition().x, StaminaBar.getPosition().y);
	Armour.setPosition(ArmourBar.getPosition().x, ArmourBar.getPosition().y);
	Charisma.setPosition(CharismaBar.getPosition().x, CharismaBar.getPosition().y);
	Knowledge.setPosition(KnowledgeBar.getPosition().x, KnowledgeBar.getPosition().y);

	SkillsText.setPosition(SkillsBox.getPosition().x + 75, SkillsBox.getPosition().y + 10);
	strengthText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 40); // setting the position relative to the skillbox
	staminaText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 100);
	armourText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 160);
	charismaText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 220);
	knowledgeText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 280);

	target.draw(SkillsBox);
	target.draw(SkillsText);

	target.draw(StrengthBar);
	target.draw(StaminaBar);
	target.draw(ArmourBar);
	target.draw(CharismaBar);
	target.draw(KnowledgeBar);

	target.draw(strengthText);
	target.draw(staminaText);
	target.draw(armourText);
	target.draw(charismaText);
	target.draw(knowledgeText);

	target.draw(Strength);
	target.draw(Stamina);
	target.draw(Armour);
	target.draw(Charisma);
	target.draw(Knowledge);


}

void GUI::updateHUD() {
	sf::Time TimeElapsed = GUIClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second

	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		GUITime++;
		GUIClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;

		if (GUITimeMinute >= 20 && GUITimeMinute <= 22) { //between the 20th and 22nd minute, increase the nighttime
			if (night < 100) {
				night++;
			}
		}

		if (GUITimeMinute >= 5 && GUITimeMinute <= 7) {
			if (night > 0) {
				night--;
			}
		}
	}

	if (GUITime >= minute) { // if the HUDTime is more or equal to 60, do this
		GUITimeMinute++; // increment the hud time minute
		GUITime = 0; // change the hud time back to 0
		if (GUITimeMinute >= 24) {// if the hudtime minute is more than 24(like a 24 hour clock)
			day++;
			GUITimeMinute = 0; // set hudtime back to 0
		}
	}
}
void GUI::update(sf::Time deltaTime)
{
	this->updateHUD();
}
void GUI::render(sf::RenderTarget & target)
{
}


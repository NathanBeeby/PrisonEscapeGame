#pragma once
#include "HUD.h"
#include "Player.h"

class GUI : virtual public HUD
{
private:
	//Variables
	sf::Clock GUIClock;
	sf::CircleShape PlayerIcon;
	sf::RectangleShape ArmourAddition, daynight;
	sf::Event event;
	sf::Font font;
	sf::Text SkillsText, strengthText, staminaText, armourText, charismaText, knowledgeText, playerMissions, MissionsHeader, InventoryText, CraftText, moneyText, HealthText, LevelText, LevelString, XPText, TimerText, dayText, dateText, RoutineDialogue, submitText;
	sf::Texture playerTexture, halfHealthPlayer, lowHealthPlayer, poundTexture, Skills, Inventory, Missions, characterTexture;
	bool mousePress;

	std::string prisonerFile, moneyString, lvlString;
	std::string StrengthString, StaminaString, ArmourString, CharismaString, KnowledgeString;
	std::vector<sf::RectangleShape> InvSlot;


	int missionList, MisOpenCount, InvOpenCount, SkilOpenCount, RepOpenCount, craftOpenCount, GUITime, GUITimeMinute, day, prisonMoney;

	Player player;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
	void initGUI();
public:
	GUI();
	virtual ~GUI();

	// Public Variables
	std::vector<sf::RectangleShape> EmptySlot;
	std::vector<sf::Texture> EmptyTexture;
	std::vector<sf::Text> missions;
	sf::RectangleShape clockOuterBox, clockDigital, date, routineBox, PlayerBox, noHealth, health, noXP, XP, prisonPound, emptyGRep, emptyPRep, GRep, PRep;
	sf::RectangleShape box, box1, box2, StrengthBar, StaminaBar, ArmourBar, CharismaBar, KnowledgeBar, Strength, Stamina, Armour, Charisma, Knowledge;
	sf::RectangleShape MissionsBox, SkillsBox, InventoryBox, characterBox, CashBox, CraftButton, CraftBox, closeCraft, craftInputBox, submitCraft;

	bool yardTime, chowTime, showerTime, workTime, freeTime, bedTime, MisOpen, SkilOpen, InvOpen, RepOpen, craftOpen; // USE ENUMERATION INSTEAD OF THESE BOOLS
	int charIncrement, prisonerRep, guardRep, minute;
	float healthBar, XPcount, HUDopacity, maxXP, night;



	// Public Functions
	void drawMissions(sf::View &view, sf::RenderTarget& target);
	void drawSkills(sf::View &view, sf::RenderTarget& target);
	void drawInventory(sf::View &view, sf::RenderTarget& target);
	void drawReputation(sf::View &view, sf::RenderTarget& target);
	void drawCraft(sf::View &view, sf::RenderTarget& target);
	void drawGUI(sf::View &view, sf::RenderTarget& target);
	void Times(sf::View &view, sf::RenderTarget& target);
	void MouseInput(sf::RenderWindow &window);
	void craftingMouseInput(sf::RenderWindow &window);
	void skillsOpening();
	void missionsOpening();
	void inventoryOpening();
	void craftingOpening();
	void craftButtonClicked();
	void reputationOpening();

	void updateHUD();
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);

};


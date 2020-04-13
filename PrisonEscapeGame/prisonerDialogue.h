#pragma once
#include "Dialogue.h"
#include "guardDialogue.h"
#include "GUI.h"

#define prisoner_item_Number 3
class prisonerDialogue : virtual public Dialogue
{
private:
	// Variables
	enum prisonerDialogueState { prisonerTalk, prisonerMissions, prisonerTrade, prisonerDialogueMenu, prisonerNoState };

	std::vector<bool> acceptedMission;
	std::vector <std::string> PM;
	std::vector<sf::Text>  missions;

	sf::Font font;
	sf::RectangleShape DialogueBox, segBox, tradeBox, tradeSymbol, tradeButton, acceptButton, declineButton, cancelButton;
	sf::Text PrisonerText[prisoner_item_Number];
	sf::Text TalkDialogue, missionDialogue;
	sf::Texture tradeTexture, tradeButtonTexture, acceptTexture, declineTexture, cancelTexture;

	int talkInt, missionsInt, prisonItemIndex, offset;
	int GetPressedItem() { return prisonItemIndex; }

	guardDialogue guardD;
	prisonerDialogueState prisonerDState;

	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initText();
	void initFont();

public:
	// Constructor / Destructor
	prisonerDialogue();
	virtual ~prisonerDialogue();

	// Public Variables
	bool dialogueCheck;

	// Public Functions
	void drawDialogueBox(sf::View &view, sf::RenderTarget& target);
	void draw(sf::View &view, sf::RenderTarget& target);

	void Up();
	void Down();

	void Talk(sf::View &view, sf::RenderTarget& target);
	void Trade(sf::View &view, sf::RenderTarget& target);
	void Mission(sf::View &view, sf::RenderTarget& target, GUI &gui);
	void dialogueHandler(sf::View &view, sf::RenderTarget& target, GUI &gui);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);
};


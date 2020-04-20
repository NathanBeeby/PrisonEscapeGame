#pragma once
#include "Dialogue.h"
#include "guardDialogue.h"


#define prisoner_item_Number 3
class prisonerDialogue : virtual public Dialogue
{
private:
	// Variables
	enum prisonerDialogueState { prisonerTalk, prisonerMissions, prisonerTrade, prisonerDialogueMenu, prisonerNoState };

	std::vector <std::string> PM;

	sf::RectangleShape tradeBox, tradeSymbol, tradeButton;
	sf::Text PrisonerText[prisoner_item_Number];
	sf::Texture tradeTexture, tradeButtonTexture, acceptTexture, declineTexture, cancelTexture;

	int prisonItemIndex;
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

	// Public Functions
	void drawDialogueBox(sf::View &view, sf::RenderTarget& target);
	void draw(sf::View &view, sf::RenderTarget& target);

	void Up();
	void Down();

	void Talk(sf::View &view, sf::RenderTarget& target);
	void Trade(sf::View &view, sf::RenderTarget& target);
	void Mission(sf::View &view, sf::RenderTarget& target, GUI &gui);
	void dialogueHandler(sf::View &view, sf::RenderTarget& target, GUI &gui);
	void mouseHandler(sf::RenderWindow &window, GUI &gui);
	void talkPressed(GUI &gui);
	void tradePressed(sf::RenderTarget &target, GUI &gui);
	void missionsPressed(sf::RenderTarget &target, GUI &gui);


	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);
};


#pragma once

#include <SFML/Graphics.hpp>
#include "Dialogue.h"
#include "GUI.h"

#define guard_item_Number 3
class guardDialogue : virtual public Dialogue
{
private:
	// Variables
	enum guardDialogueState { guardTalk, guardMissions, snitching, guardDialogueMenu, guardNoState };
	std::string GM1;
	std::string GM2;
	std::string GM3;
	std::string GM4;
	std::string GM5;
	std::string GM6;
	std::string GM7;

	sf::Font font;
	sf::Text GuardText[guard_item_Number];
	sf::Text TalkDialogue, missionDialogue, repText;
	sf::Texture acceptTexture, declineTexture, cancelTexture;
	sf::RectangleShape acceptButton, declineButton, cancelButton, segBox, DialogueBox;

	int talkInt, missionsInt, offset, guardItemIndex;
	int GetPressedItem() { return guardItemIndex; }

	//Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
	void initFont();

public:
	//Constructor / Destructor
	guardDialogue();
	virtual ~guardDialogue();

	// Public Variables
	bool dialogueCheck;
	int prisonInfo; // int for number of information collected on prisoner

	guardDialogueState guardDState;

	// Public Functions
	void drawDialogueBox(sf::View &view, sf::RenderTarget& target);
	void draw(sf::View &view, sf::RenderTarget& target);
	void Up();
	void Down();

	void Talk(sf::View &view, sf::RenderTarget& target);
	void Snitch(sf::View &view, sf::RenderTarget& target);
	void Mission(sf::View &view, sf::RenderTarget& target, GUI &gui);
	void dialogueHandler(sf::View &view, sf::RenderTarget& target, GUI &gui);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);



};


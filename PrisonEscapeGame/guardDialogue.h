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
	
	std::vector<bool> acceptedMission;
	std::vector <std::string> GM;
	std::vector<sf::Text>  missions;


	sf::Font font;
	sf::Text GuardText[guard_item_Number];
	sf::Text TalkDialogue, missionDialogue, repText;
	sf::Texture acceptTexture, declineTexture, cancelTexture;
	sf::RectangleShape acceptButton, declineButton, cancelButton, segBox, DialogueBox;

	int talkInt, missionsInt, offset, guardItemIndex;
	int GetPressedItem() { return guardItemIndex; }
	bool mousePress;
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
	void mouseHandler(sf::RenderWindow &window, GUI &gui);
	void talkPressed(GUI &gui);
	void snitchPressed(sf::RenderTarget &target, GUI &gui);
	void missionsPressed(sf::RenderTarget &target, GUI &gui);


	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);



};


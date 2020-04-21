#pragma once
#ifndef GUARDDIALOGUE_H
#define GUARDDIALOGUE_H
#include "Dialogue.h"

#define guard_item_Number 3
class guardDialogue : virtual public Dialogue
{
private:
#pragma region Private Variables
	// Private Variables
	enum guardDialogueState { guardTalk, guardMissions, snitching, guardDialogueMenu, guardNoState };
	std::vector <std::string> GM;
	sf::Text GuardText[guard_item_Number];
	sf::Text repText;
	sf::Texture acceptTexture, declineTexture, cancelTexture;
	sf::RectangleShape acceptButton, declineButton, cancelButton, segBox, DialogueBox;

	int guardItemIndex;
	int GetPressedItem() { return guardItemIndex; }
#pragma endregion

#pragma region Initialization
	//Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
	void initFont();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	guardDialogue();
	virtual ~guardDialogue();
#pragma endregion

#pragma region Public Variables
	// Public Variables
	int prisonInfo; // int for number of information collected on prisoner
	guardDialogueState guardDState;
#pragma endregion

#pragma region Public Functions
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
#pragma endregion
};

#endif

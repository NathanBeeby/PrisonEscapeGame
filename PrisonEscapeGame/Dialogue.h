#pragma once
#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"

class Dialogue
{
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	Dialogue() { }
	virtual ~Dialogue() {}
#pragma endregion

#pragma region Public Variables
	// Public Variables
	sf::Font font;
	std::vector<sf::Text>  missions;
	std::vector<bool> acceptedMission;
	sf::RectangleShape acceptButton, declineButton, cancelButton, segBox, DialogueBox;
	sf::Text TalkDialogue, missionDialogue;
	int talkInt, missionsInt, offset;
	bool mousePress;
	bool dialogueCheck;
#pragma endregion
};

#endif
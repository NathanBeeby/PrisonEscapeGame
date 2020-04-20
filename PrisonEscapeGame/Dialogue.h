#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI.h"

class Dialogue
{
public:
	// Constructor / Destructor
	Dialogue();
	virtual ~Dialogue();

	// Public Variables
	sf::Font font;
	std::vector<sf::Text>  missions;
	std::vector<bool> acceptedMission;
	sf::RectangleShape acceptButton, declineButton, cancelButton, segBox, DialogueBox;
	sf::Text TalkDialogue, missionDialogue;
	int talkInt, missionsInt, offset;
	bool mousePress;
	bool dialogueCheck;
};


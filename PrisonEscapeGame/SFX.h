#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include "OptionsMenu.h"

class SFX
{
private:
	// Variables
	sf::Sound soundEffect;
	sf::SoundBuffer punchBuffer, collideBuffer, dangerBuffer, doorBuffer, menuBuffer;
	sf::Music menuSound; // backgroundMusic


						 // Initialization
	void initVariables();
	void initSounds();
public:
	// Constructor / Destructor
	SFX();
	virtual ~SFX();

	// Public Functions
	// punching sound effect
	void punchEffect(OptionsMenu &options);
	// colliding with wall sound effect
	void collisionEffect(OptionsMenu &options);
	// Danger sound effect
	void dangerEffect(OptionsMenu &options);
	// door opening
	void openDoorEffect(OptionsMenu &options);

	void menuMusic(OptionsMenu &options);

	void playMenuMusic();

	void pauseMenuMusic();

	void setMusicVolume(OptionsMenu &options);
};


#pragma once
#ifndef SFX_H
#define SFX_H

#include <SFML/Audio.hpp>
#include <iostream>
#include "OptionsMenu.h"

class SFX
{
private:
#pragma region Private Variables
	// Private Variables
	sf::Sound soundEffect;
	sf::SoundBuffer punchBuffer, collideBuffer, dangerBuffer, doorBuffer, menuBuffer;
	sf::Music menuSound; // backgroundMusic
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSounds();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	SFX();
	virtual ~SFX();
#pragma endregion

#pragma region Public Functions
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
#pragma endregion
};

#endif
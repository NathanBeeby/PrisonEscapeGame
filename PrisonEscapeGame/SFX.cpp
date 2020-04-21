#include "SFX.h"

#pragma region Initialization
// Initialization
void SFX::initVariables()
{

}

void SFX::initSounds()
{
	//Loading in sound files
	if (!this->punchBuffer.loadFromFile("../assets/sound_assets/SFX/Punch.wav")) {
		std::cout << "Sound effect Punch not working" << std::endl;
	}
	if (!this->collideBuffer.loadFromFile("../assets/sound_assets/SFX/hitWall.ogg")) {
		std::cout << "Sound effect collide not working" << std::endl;
	}
	if (!this->dangerBuffer.loadFromFile("../assets/sound_assets/SFX/Danger.wav")) {
		std::cout << "Sound effect danger not working" << std::endl;
	}
	if (!this->doorBuffer.loadFromFile("../assets/sound_assets/SFX/DoorOpen.wav")) {
		std::cout << "Sound effect door open not working" << std::endl;
	}
	if (!this->menuSound.openFromFile("../assets/sound_assets/Music/BlueHighway.ogg")) {
		std::cout << "Background music not loaded" << std::endl;
	}
}
#pragma endregion

#pragma region Constructor / Destructor
// Constructor / Destructor
SFX::SFX()
{
	this->initVariables();
	this->initSounds();
}

SFX::~SFX()
{

}
#pragma endregion

#pragma region Public Functions
// Public Functions
void SFX::punchEffect(OptionsMenu &options) {
	std::cout << "Punched" << std::endl;
	this->soundEffect.setBuffer(punchBuffer);
	this->soundEffect.setVolume(options.Sound);
	this->soundEffect.play();
}

void SFX::collisionEffect(OptionsMenu &options) {
	std::cout << "Hit Wall" << std::endl;
	this->soundEffect.setBuffer(collideBuffer);
	this->soundEffect.setVolume(options.Sound);
	this->soundEffect.play();
}

void SFX::dangerEffect(OptionsMenu &options) {
	std::cout << "Danger" << std::endl;
	this->soundEffect.setBuffer(dangerBuffer);
	this->soundEffect.setVolume(options.Sound);
	this->soundEffect.play();
}

void SFX::openDoorEffect(OptionsMenu &options) {
	std::cout << "Door Sound" << std::endl;
	this->soundEffect.setBuffer(doorBuffer);
	this->soundEffect.setVolume(options.Sound);
	this->soundEffect.play();
}

void SFX::menuMusic(OptionsMenu &options) {

}

void SFX::playMenuMusic()
{
	this->menuSound.play(); // play the menu music. do not want to loop
}

void SFX::pauseMenuMusic()
{
	this->menuSound.pause(); // pause that funky music
}

void SFX::setMusicVolume(OptionsMenu &options)
{
	this->menuSound.setVolume(options.Music);
}
#pragma endregion
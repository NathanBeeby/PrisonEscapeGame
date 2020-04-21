#pragma once
#ifndef FURNINV_H
#define FURNINV_H
#include "GUI.h"
#include "HUD.h"
#include "InventoryItems.h"

class furnitureInv : virtual public HUD
{
private:
#pragma region Private Variables
	// Private Variables
	sf::RectangleShape gridBox, bin, desk, locker, BigBin, toolsCabinet, footLocker;
	sf::Texture binTexture, deskTexture, lockerTexture, BigBinTexture, toolsCabinetTexture, footLockerTexture;
	std::string inventoryFile;

	InventoryItems inv;
#pragma endregion

#pragma region Initialization
	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
#pragma endregion
public:
#pragma region Constructor / Destructor
	// Constructor / Destructor
	furnitureInv();
	virtual ~furnitureInv();
#pragma endregion

#pragma region Public Functions
	// Public Functions
	void Grid2by2(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void Grid5by2(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void Grid4by4(sf::View &view, sf::RenderWindow &window, GUI &gui);

	void drawBin(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void drawDesk(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void drawLocker(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void drawBigBin(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void drawToolsCabinet(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void drawFootLocker(sf::View &view, sf::RenderWindow &window, GUI &gui);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);
#pragma endregion
};
#endif
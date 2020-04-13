#pragma once

#include "GUI.h"
#include "HUD.h"
#include "InventoryItems.h"

class furnitureInv : virtual public HUD
{
private:
	// Variables
	sf::RectangleShape gridBox, bin, desk, locker, BigBin, toolsCabinet, footLocker;
	sf::Texture binTexture, deskTexture, lockerTexture, BigBinTexture, toolsCabinetTexture, footLockerTexture;
	std::string inventoryFile;

	InventoryItems inv;

	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
public:
	// Constructor / Destructor
	furnitureInv();
	virtual ~furnitureInv();

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
};


#pragma once

#include "HUD.h"
#include "GUI.h"

class InventoryItems : virtual public HUD
{
private:
	// Variables
	sf::RectangleShape item;
	std::vector<sf::RectangleShape>  InvItems;
	std::vector<sf::RectangleShape> Items2by2; // 4
	std::vector<sf::RectangleShape> Items5by2; // 10
	std::vector<sf::RectangleShape> Items4by4; // 16
	std::vector<int> ItemRand2x2;
	std::vector<int> ItemRand5x2;
	std::vector<int> ItemRand4x4;
	std::vector<sf::Texture>  inventoryTexture;
	std::stringstream iss;
	std::string inventoryFile;
	std::string inventoryfilename;
	std::string is;
	std::string inventoryPath;
	std::string type;
	std::ifstream myInputFile;

	bool inv2by2Empty, inv5by2Empty, inv4by4Empty;
	int inv2by2Size, inv5by2Size, inv4by4Size, inventoryNumber, InvRand2by2, InvRand5by2, InvRand4by4;
	float InvX, InvY, sizeX, sizeY; // position X and Y

									// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
	void initFont();
	void initReadFile();

public:
	// Constructor / Destructor
	InventoryItems();
	virtual ~InventoryItems();

	// Public Functions
	void prepare2x2Items(sf::View &view);
	void prepare5x2Items(sf::View &view);
	void prepare4x4Items(sf::View &view);

	void draw2x2Items(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void draw5x2Items(sf::View &view, sf::RenderWindow &window, GUI &gui);
	void draw4x4Items(sf::View &view, sf::RenderWindow &window, GUI &gui);

	void update(sf::Time deltaTime);
	void render(sf::RenderTarget& target);

};


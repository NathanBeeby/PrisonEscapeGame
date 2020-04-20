#include "InventoryItems.h"

// Initialization
void InventoryItems::initVariables()
{
	// String Variables
	this->inventoryFile = "../assets/text_assets/InventoryItems.txt";
	this->inventoryfilename = "file.txt";
	// Integer Variables
	this->inv2by2Size = 0;
	this->inv5by2Size = 0;
	this->inv4by4Size = 0;
	// Boolean Variables
	this->inv2by2Empty = true;
	this->inv5by2Empty = true;
	this->inv4by4Empty = true;
}

void InventoryItems::initTextures()
{

}

void InventoryItems::initSprites()
{
}

void InventoryItems::initFont()
{
}

void InventoryItems::initReadFile()
{
	myInputFile.open(inventoryFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, is);
		iss.str(is);
		iss.ignore(20);
		iss >> inventoryNumber;
		InvItems.resize(inventoryNumber);
		inventoryTexture.resize(inventoryNumber);

		iss.clear();

		for (int i = 0; i < inventoryNumber; i++)
		{
			//NAME AND NUMBER
			//POSITION
			//SIZE
			//TEXTURE
			getline(myInputFile, is);
			iss.clear();
			iss.str(is);
			iss >> type;
			getline(myInputFile, is);
			iss.clear();
			iss.str(is);
			iss >> sizeX >> sizeY;
			getline(myInputFile, is);
			iss.clear();
			iss.str(is);
			iss >> inventoryPath;

			sf::Vector2f size(sizeX, sizeY);

			if (!inventoryTexture[i].loadFromFile(inventoryPath)) {
				std::cout << "Load fail Error on inventory Texture" << std::endl;
				system("pause");
			}
			//InvItems[i].setPosition(300 + (i*50), 300);
			//InvItems[i].setSize(size);
			//InvItems[i].setTexture(&inventoryTexture[i]);
		}
	}
}

// Constructor / Destructor
InventoryItems::InventoryItems()
{
	this->initVariables();
	this->initReadFile();
}

InventoryItems::~InventoryItems()
{

}

// Public Functions
void InventoryItems::prepare2x2Items(sf::View &view) {
	if (inv2by2Empty == true) {
		InvRand2by2 = rand() % 4 + 1; // randomizing InvRand2by2 to get a number between 1 and 4
		ItemRand2x2.resize(InvRand2by2);
		for (int i = 0; i < InvRand2by2; i++) {
			ItemRand2x2[i] = rand() % 15 + 1; // ItemRand2by2 will have a texture for each number
		}
		inv2by2Empty = false; //stopping the randomization
	}

	for (int i = 0; i < 2; i++) { //looping through for the positions
		for (int j = 0; j < 2; j++) {
			if (inv2by2Size < InvRand2by2) {
				Items2by2.push_back(item);
				Items2by2[inv2by2Size].setPosition(view.getCenter().x - 64 + (i * 64), view.getCenter().y - 64 + (j * 64));
				Items2by2[inv2by2Size].setSize(sf::Vector2f(40, 45)); // giving the item a size
				inv2by2Size++;
			}
		}
	}
}

void InventoryItems::draw2x2Items(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	prepare2x2Items(view);

	for (int i = 0; i < Items2by2.size(); i++) {
		Items2by2[i].setTexture(&inventoryTexture[ItemRand2x2[i]]); // getting a random texture
		window.draw(Items2by2[i]);
	}
	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
															// convert it to world coordinates
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		std::cout << "WorldPos X: " << worldPos.x << ", Y: " << worldPos.y << std::endl;
		for (int i = 0; i < Items2by2.size(); i++) {
			if (worldPos.x >= Items2by2[i].getPosition().x && worldPos.x <= Items2by2[i].getPosition().x + Items2by2[i].getSize().x) {
				if (worldPos.y >= Items2by2[i].getPosition().y && worldPos.y <= Items2by2[i].getPosition().y + Items2by2[i].getSize().y) {

					std::cout << "This is Item: " << i << std::endl; // use this method to get the item to inventory
					if (gui.EmptySlot.size() < 8) {
						gui.EmptySlot.push_back(Items2by2[i]); // sending the item to the player inventory
						gui.EmptyTexture.push_back(inventoryTexture[ItemRand2x2[i]]);
						this->inventoryTexture.erase(inventoryTexture.begin() + i);
						this->Items2by2.erase(Items2by2.begin() + i); // erasing the selected Item from the array	
																	  // This removes the item within the array, however swaps texture with another item in the array
					}
				}
			}
		}
	}
}

void InventoryItems::prepare5x2Items(sf::View &view) {
	if (inv5by2Empty == true) {
		InvRand5by2 = rand() % 10 + 1; // randomizing InvRand2by2 to get a number between 1 and 10
		ItemRand5x2.resize(InvRand5by2);
		for (int i = 0; i < InvRand5by2; i++) {
			ItemRand5x2[i] = rand() % 15 + 1; // ItemRand2by2 will have a texture for each number
		}
		inv5by2Empty = false; //stopping the randomization
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			if (inv5by2Size < InvRand5by2) {
				Items5by2.push_back(item);
				Items5by2[inv5by2Size].setPosition(view.getCenter().x - 145 + (i * 64), view.getCenter().y - 55 + (j * 64));
				inv5by2Size++;
			}
		}
	}
}

void InventoryItems::prepare4x4Items(sf::View &view) {
	if (inv4by4Empty == true) {
		InvRand4by4 = rand() % 16 + 1; // randomizing InvRand2by2 to get a number between 1 and 4
		ItemRand4x4.resize(InvRand4by4);
		for (int i = 0; i < InvRand4by4; i++) {
			ItemRand4x4[i] = rand() % 15 + 1; // ItemRand2by2 will have a texture for each number
		}
		inv4by4Empty = false; //stopping the randomization
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (inv4by4Size < InvRand4by4) {
				Items4by4.push_back(item);
				Items4by4[inv4by4Size].setPosition(view.getCenter().x - 120 + (i * 64), view.getCenter().y - 119 + (j * 64));
				inv4by4Size++;
			}
		}
	}
}

void InventoryItems::draw5x2Items(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	prepare5x2Items(view);

	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window	
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); // convert it to world coordinates
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		for (int i = 0; i < Items5by2.size(); i++) {
			if (worldPos.x >= Items5by2[i].getPosition().x && worldPos.x <= Items5by2[i].getPosition().x + Items5by2[i].getSize().x) {
				if (worldPos.y >= Items5by2[i].getPosition().y && worldPos.y <= Items5by2[i].getPosition().y + Items5by2[i].getSize().y) {
					std::cout << "This is Item: " << i << std::endl; // use this method to get the item to inventory
					if (gui.EmptySlot.size() < 8) {
						gui.EmptySlot.push_back(Items5by2[i]); // sending the item to the player inventory
						gui.EmptyTexture.push_back(inventoryTexture[ItemRand5x2[i]]);

						this->inventoryTexture.erase(inventoryTexture.begin() + i);
						this->Items5by2.erase(Items5by2.begin() + i); // erasing the selected Item from the array
					}
				}
			}
		}
	}
	for (int i = 0; i < Items5by2.size(); i++) {
		Items5by2[i].setSize(sf::Vector2f(40, 45)); // giving the item a size
		Items5by2[i].setTexture(&inventoryTexture[ItemRand5x2[i]]); // getting a random texture
		window.draw(Items5by2[i]);
	}
}

void InventoryItems::draw4x4Items(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	prepare4x4Items(view);

	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
															// convert it to world coordinates
	sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		for (int i = 0; i < Items5by2.size(); i++) {
			if (worldPos.x >= Items4by4[i].getPosition().x && worldPos.x <= Items4by4[i].getPosition().x + Items4by4[i].getSize().x) {
				if (worldPos.y >= Items4by4[i].getPosition().y && worldPos.y <= Items4by4[i].getPosition().y + Items4by4[i].getSize().y) {
					std::cout << "This is Item: " << i << std::endl; // use this method to get the item to inventory
					if (gui.EmptySlot.size() < 8) {
						gui.EmptySlot.push_back(Items4by4[i]); // sending the item to the player inventory
						gui.EmptyTexture.push_back(inventoryTexture[ItemRand4x4[i]]);

						this->inventoryTexture.erase(inventoryTexture.begin() + i);
						this->Items4by4.erase(Items4by4.begin() + i); // erasing the selected Item from the array
					}
				}
			}
		}
	}

	for (int i = 0; i < Items4by4.size(); i++) {
		Items4by4[i].setSize(sf::Vector2f(40, 45)); // giving the item a size
		Items4by4[i].setTexture(&inventoryTexture[ItemRand4x4[i]]); // getting a random texture
		window.draw(Items4by4[i]);
	}
}

void InventoryItems::update(sf::Time deltaTime)
{

}

void InventoryItems::render(sf::RenderTarget &target)
{

}


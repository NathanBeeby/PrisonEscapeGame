#include "furnitureInv.h"

// Initialization
void furnitureInv::initVariables()
{
	// String Variables
	this->inventoryFile = "../assets/text_assets/InventoryItems.txt";
}

void furnitureInv::initSprites()
{
	bin.setSize(sf::Vector2f(150, 150));
	bin.setTexture(&binTexture);

	desk.setSize(sf::Vector2f(150, 150));
	desk.setTexture(&deskTexture);

	BigBin.setSize(sf::Vector2f(275, 275));
	BigBin.setTexture(&BigBinTexture);

	toolsCabinet.setSize(sf::Vector2f(275, 275));
	toolsCabinet.setTexture(&toolsCabinetTexture);

	locker.setSize(sf::Vector2f(150, 150));
	locker.setTexture(&lockerTexture);

	footLocker.setSize(sf::Vector2f(350, 150));
	footLocker.setTexture(&footLockerTexture);
}

void furnitureInv::initTextures()
{
	if (!this->binTexture.loadFromFile("../assets/image_assets/insideBin.png")) {
		std::cout << "Load fail Error on inside bin" << std::endl;
		system("pause");
	}
	if (!this->deskTexture.loadFromFile("../assets/image_assets/insideDesk.png")) {
		std::cout << "Load fail Error on inside bin" << std::endl;
		system("pause");
	}
	if (!this->lockerTexture.loadFromFile("../assets/image_assets/insideLocker.png")) {
		std::cout << "Load fail Error on inside bin" << std::endl;
		system("pause");
	}
	if (!this->BigBinTexture.loadFromFile("../assets/image_assets/insideBigBin.png")) {
		std::cout << "Load fail Error on inside big bin" << std::endl;
		system("pause");
	}
	if (!this->toolsCabinetTexture.loadFromFile("../assets/image_assets/insideToolsCabinet.png")) {
		std::cout << "Load fail Error on inside big bin" << std::endl;
		system("pause");
	}
	if (!this->footLockerTexture.loadFromFile("../assets/image_assets/insideFootLocker.png")) {
		std::cout << "Load fail Error on inside big bin" << std::endl;
		system("pause");
	}
}

// Constructor / Destructor
furnitureInv::furnitureInv()
{
	this->initTextures();
	this->initVariables();
	this->initSprites();
}


furnitureInv::~furnitureInv()
{
}


// Public Functions
void furnitureInv::Grid2by2(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	std::vector<sf::RectangleShape>  TwoByTwo(4, sf::RectangleShape(gridBox));

	TwoByTwo[0].setPosition(view.getCenter().x - 64, view.getCenter().y - 64);
	TwoByTwo[1].setPosition(view.getCenter().x, view.getCenter().y - 64);
	TwoByTwo[2].setPosition(view.getCenter().x - 64, view.getCenter().y);
	TwoByTwo[3].setPosition(view.getCenter().x, view.getCenter().y);


	for (int i = 0; i < TwoByTwo.size(); i++) {
		TwoByTwo[i].setSize(sf::Vector2f(64, 64));
		TwoByTwo[i].setFillColor(sf::Color(155, 155, 155, 150));
		TwoByTwo[i].setOutlineThickness(2);
		TwoByTwo[i].setOutlineColor(sf::Color(0, 0, 0));
		window.draw(TwoByTwo[i]);
	}

	inv.draw2x2Items(view, window, gui);
}

void furnitureInv::Grid5by2(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	std::vector<sf::RectangleShape>  FiveByTwo(10, sf::RectangleShape(gridBox));

	for (int i = 0; i < FiveByTwo.size(); i++) {
		FiveByTwo[i].setSize(sf::Vector2f(64, 64));
		FiveByTwo[i].setFillColor(sf::Color(155, 155, 155, 150));
		FiveByTwo[i].setOutlineThickness(2);
		FiveByTwo[i].setOutlineColor(sf::Color(0, 0, 0));
	}

	for (int i = 0; i < 5; i++) {
		FiveByTwo[i].setPosition(view.getCenter().x - 160 + (i * 64), view.getCenter().y - 64);
		window.draw(FiveByTwo[i]);
	}
	for (int j = 0; j < 5; j++) {
		FiveByTwo[j].setPosition(view.getCenter().x - 160 + (j * 64), view.getCenter().y);
		window.draw(FiveByTwo[j]);
	}

	inv.draw5x2Items(view, window, gui);
}

void furnitureInv::Grid4by4(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	std::vector<sf::RectangleShape>  FourByFour(16, sf::RectangleShape(gridBox));

	for (int i = 0; i < FourByFour.size(); i++) {
		FourByFour[i].setSize(sf::Vector2f(64, 64));
		FourByFour[i].setFillColor(sf::Color(155, 155, 155, 150));
		FourByFour[i].setOutlineThickness(2);
		FourByFour[i].setOutlineColor(sf::Color(0, 0, 0));
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			FourByFour[i].setPosition(view.getCenter().x - 128 + (i * 64), view.getCenter().y - 128 + (j * 64));
			window.draw(FourByFour[i]);
		}
	}

	inv.draw4x4Items(view, window, gui);
}

// BIN (2x2)
void furnitureInv::drawBin(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	bin.setPosition(view.getCenter().x - 75, view.getCenter().y - 75);
	window.draw(bin);
	Grid2by2(view, window, gui);
}
// DESK (2x2) 
void furnitureInv::drawDesk(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	desk.setPosition(view.getCenter().x - 75, view.getCenter().y - 75);
	window.draw(desk);
	Grid2by2(view, window, gui);
}
// LOCKER (2x2)
void furnitureInv::drawLocker(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	locker.setPosition(view.getCenter().x - 75, view.getCenter().y - 75);
	window.draw(locker);
	Grid2by2(view, window, gui);
}
// BIG BIN (4x4)
void furnitureInv::drawBigBin(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	BigBin.setPosition(view.getCenter().x - 138, view.getCenter().y - 138);
	window.draw(BigBin);
	Grid4by4(view, window, gui);
}
//TOOLS CABINET (4x4)
void furnitureInv::drawToolsCabinet(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	toolsCabinet.setPosition(view.getCenter().x - 138, view.getCenter().y - 138);
	window.draw(toolsCabinet);
	Grid4by4(view, window, gui);
}
// FOOTLOCKER (5x2)
void furnitureInv::drawFootLocker(sf::View &view, sf::RenderWindow &window, GUI &gui) {
	footLocker.setPosition(view.getCenter().x - 175, view.getCenter().y - 75);
	window.draw(footLocker);
	Grid5by2(view, window, gui);
}

void furnitureInv::update(sf::Time deltaTime)
{
}

void furnitureInv::render(sf::RenderTarget &target)
{
}

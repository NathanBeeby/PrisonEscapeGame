#include "SkillItems.h"

// Initialization
void SkillItems::initVariables()
{
	this->bikeStr = "bike";
	this->weightsStr = "weight";
	this->skillsfilename = "file.txt";
	this->skillsFile = "../assets/text_assets/SkillItems.txt";
}

void SkillItems::initSprites()
{
	this->bikeWindow.setSize(sf::Vector2f(250, 400));
	this->bikeWindow.setFillColor(sf::Color(242, 232, 171));
	this->bikeWindow.setOutlineThickness(2);
	this->bikeWindow.setOutlineColor(sf::Color(0, 0, 0));

	this->strengthWindow.setSize(sf::Vector2f(250, 400));
	this->strengthWindow.setFillColor(sf::Color(242, 232, 171));
	this->strengthWindow.setOutlineThickness(2);
	this->strengthWindow.setOutlineColor(sf::Color(0, 0, 0));

	this->knowledgeWindow.setSize(sf::Vector2f(250, 400));
	this->knowledgeWindow.setFillColor(sf::Color(242, 232, 171));
	this->knowledgeWindow.setOutlineThickness(2);
	this->knowledgeWindow.setOutlineColor(sf::Color(0, 0, 0));
}

void SkillItems::initTextures()
{

}

void SkillItems::initSkills()
{
	myInputFile.open(skillsFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		//read the first line which has the number of elements
		std::getline(myInputFile, Ss);
		Sss.str(Ss);
		Sss.ignore(22);
		Sss >> skillItemNumber;
		skillItems.resize(skillItemNumber);
		SkillItemTexture.resize(skillItemNumber);

		Sss.clear();


		float sizeX, sizeY;
		float rot; // rotation


		for (int i = 0; i < skillItemNumber; i++)
		{

			//NAME AND NUMBER
			getline(myInputFile, Ss);
			Sss.clear();
			Sss.str(Ss);
			//POSITION
			getline(myInputFile, Ss);
			Sss.clear();
			Sss.str(Ss);
			Sss >> skillItemX >> skillItemY;
			//SIZE
			getline(myInputFile, Ss);
			Sss.clear();
			Sss.str(Ss);
			Sss >> sizeX >> sizeY;
			//TEXTURE
			getline(myInputFile, Ss);
			Sss.clear();
			Sss.str(Ss);
			Sss >> skillItemPath;

			sf::Vector2i pos(skillItemX, skillItemY);
			sf::Vector2f size(sizeX, sizeY);


			if (!SkillItemTexture[i].loadFromFile(skillItemPath)) {
				std::cout << "Load fail Error on DoorsTexture" << std::endl;
				system("pause");
			}


			skillItems[i].setPosition(pos.x, pos.y);
			skillItems[i].setOrigin(size / 2.0f);
			skillItems[i].setSize(size);
			skillItems[i].setTexture(&SkillItemTexture[i]);
		}
	}
}

// Constructor / Destructor
SkillItems::SkillItems()
{
	this->initVariables();
	this->initSprites();
	this->initSkills();
	this->initTextures();
}

SkillItems::~SkillItems()
{
}

// Public Functions
void SkillItems::update(sf::Time deltaTime)
{
}

void SkillItems::render(sf::RenderTarget & target)
{
	for (int i = 0; i < skillItems.size(); i++) {
		target.draw(skillItems[i]);
	}
}

const sf::FloatRect SkillItems::getBounds() const
{
	for (int i = 0; i < this->skillItems.size(); i++) {
		return this->skillItems[i].getGlobalBounds();
	}
}

void SkillItems::knowledgeIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key) {

	knowledgeWindow.setPosition(view.getCenter().x - 125, view.getCenter().y - 130);
	target.draw(knowledgeWindow);
	
	if (key == sf::Keyboard::A && this->player.getKnowledge() < 100) {
		this->player.addKnowledge(5); 
		std::cout << "Knowledge + 5" << std::endl;
	}

}

void SkillItems::strengthIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key) {
	strengthWindow.setPosition(view.getCenter().x - 125, view.getCenter().y - 130);
	target.draw(strengthWindow);

	if (key == sf::Keyboard::A && this->player.getStrength() < 100) {
		this->player.addStrength(5); 
		std::cout << "Strength + 5" << std::endl;
	}
}

void SkillItems::staminaIncrease(sf::RenderTarget &target, sf::View &view, sf::Keyboard::Key key) {
	bikeWindow.setPosition(view.getCenter().x - 125, view.getCenter().y - 130);
	target.draw(bikeWindow);
	if (key == sf::Keyboard::A && this->player.getStamina() < 100) {
		this->player.addStamina(5); 
		std::cout << "Stamina + 5" << std::endl;
	}
}
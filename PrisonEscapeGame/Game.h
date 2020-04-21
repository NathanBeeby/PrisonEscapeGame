#pragma once
#ifndef GAME_H
#define GAME_H

// MENUS
#include "Menu.h"
#include "SkillMenu.h"
#include "OptionsMenu.h"
#include "Instructions.h"
#include "GameOver.h"

// Characters
#include "Prisoner.h"
#include "Guard.h"
#include "Warden.h"
#include "Nurse.h"

// Objects
#include "prisonWalls.h"
#include "Furniture.h"
#include "SkillItems.h"
#include "Doors.h"

// HUD Items
#include "GUI.h"
#include "furnitureInv.h"
#include "prisonerDialogue.h"

// World
#include "Background.h"
#include "mapLoader.h"
#include "SFX.h"

class Game
{
private:
#pragma region Private Variables
	enum InvState { LockerInv, BinInv, FtLockerInv, DeskInv, TlsCbInv, DumpsterInv, noState }; // furniture inventory states(which item is open, none open)
	enum skillItemsMenu { weightsMenu, bikeMenu, bookshelfMenu, noMenu }; // skill item interface gamestate, will be used to select which mini-game later on
	enum GameState { StartMenu, SkillsMenu, Options, PrisonGame, InstructionsMenu, GameOverMenu }; // gamestates for the menu system
	enum prisonerState { IDLE, PathFollow, prisonerAngry, deadState }; // moving idly, walking to destination, and chasing the player
	enum guardState { guardIDLE, guardStop, guardDESTINATION, guardCHASE }; // moving idly, walking to destination, and chasing the player

	// Time Variables
	sf::Time deltaTime;
	sf::Clock clock;
	sf::Time TimePerFrame;

	// Event
	sf::Event ev;

	// Window Variables
	sf::VideoMode videomode;
	sf::RenderWindow* window;

	sf::SoundBuffer soundBuffer; 
	sf::View view;

	// Screen position Variables
	sf::Vector2f ScreenSize;
	sf::Vector2f pos; 

	// gamestate variables
	int GameState;
	bool endGame;


	// Initializing classes in use
	InvState invS;
	skillItemsMenu skills;
	mapLoader map;
	prisonerDialogue prisonD;
	guardDialogue guardD;
	GUI gui;
	SFX sfx;
	furnitureInv furninv;
	GameOver gameover;

	//Characters (player and AI)
	Prisoner prisoner;
	Guard guard;
	Warden warden;
	Nurse nurse;
	Player player;

	//Collidable Furniture
	Doors doors;
	Furniture furniture;
	prisonWalls walls;
	SkillItems skillitems;

	//MENU'S with window parameters passed
	Menu menu;
	OptionsMenu options;
	Instructions instructions;
	SkillMenu skillmenu;
#pragma endregion

#pragma region initialization
	//Initialization
	void initWindow();
	void initView();
	void initVariables();
#pragma endregion
public:
#pragma region Constructor / Destructor
	//Constructor / Destructor
	Game();
	virtual ~Game();
#pragma endregion

#pragma region Accessors
	//Accessors
	const bool& getEndGame() const;
	const bool running() const;
	const bool gameOver() const;
#pragma endregion

#pragma region Public Functions
	//Public functions
	void NPCCollision();
	void objectCollision();
	void skillItemCollision();

	void updatePlayer(sf::Time deltaTime);
	void updateNPCs(sf::Time deltaTime);
	void updateGameState(sf::Keyboard::Key key);
	void updatePollEvents(sf::Time deltaTime);
	void keyHandler(sf::Keyboard::Key key);
	void updateCollision();
	void updateView();
	void update(sf::Time deltaTime);

	//State Changes
	void StateChange(sf::RenderTarget& target);
	void startMenuStateChange();
	void optionsMenuStateChange();
	void InstructionsMenuStateChange();
	void SkillsMenuStateChange();

	//Drawing
	void renderGame();
	void renderInventoryOptions();

	void GUIOptions();
	void SkillIncrease(sf::Keyboard::Key key);
	void dialogueCheck();

	//Render / Draw
	void renderPlayer(sf::RenderTarget& target);
	void renderNPCs(sf::RenderTarget& target);
	void renderGUI(sf::RenderTarget& target);
	void render();
	void run();
#pragma endregion
};

#endif
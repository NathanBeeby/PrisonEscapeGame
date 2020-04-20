#pragma once

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

/*
TODO:
- Add database input for Leaderboard, write a piece of code to check against the highscores in the leaderboard, and if one is beat, put the new name at the top
- Add in particle effects which work to simulate blood / water running etc.
GO THROUGH CODE, FIX BUGS. Read through code thoroughly and get into habbit of:
*/

class Game
{
private:
	enum InvState { LockerInv, BinInv, FtLockerInv, DeskInv, TlsCbInv, DumpsterInv, noState }; // furniture inventory states(which item is open, none open)
	enum skillItemsMenu { weightsMenu, bikeMenu, bookshelfMenu, noMenu }; // skill item interface gamestate, will be used to select which mini-game later on
	enum GameState { StartMenu, SkillsMenu, Options, PrisonGame, InstructionsMenu, GameOverMenu }; // gamestates for the menu system
	enum prisonerState { IDLE, PathFollow, prisonerAngry, deadState }; // moving idly, walking to destination, and chasing the player
	enum guardState { guardIDLE, guardStop, guardDESTINATION, guardCHASE }; // moving idly, walking to destination, and chasing the player


	sf::Time deltaTime;
	sf::Clock clock;// will be for the gameloop
	sf::Time TimePerFrame;
	sf::Event ev;

	sf::VideoMode videomode;
	sf::RenderWindow* window;

	sf::SoundBuffer soundBuffer; // sound buffer
	sf::View view; //setting the view for the scrolling screen
	sf::Vector2f ScreenSize;
	sf::Vector2f pos; // halving the screen size to set the centre of screen as the movement position

	int GameState; // the beginning state for the menu system will be the start menu
	bool endGame;
	//Declaring the classes that will be used within the main which have no parameters passed


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

	//Collidable Furniture
	Doors doors;
	Furniture furniture;
	prisonWalls walls;
	SkillItems skillitems;

	Player player;

	//MENU'S with window parameters passed
	Menu menu;
	OptionsMenu options;
	Instructions instructions;
	SkillMenu skillmenu;

	//Image Assets to be loaded in

	void initWindow();
	void initView();
	void initVariables();

public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool& getEndGame() const;
	const bool running() const;
	const bool gameOver() const;
	//Update functions
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
	void drawGame();
	void drawInventoryOptions();

	void GUIOptions();
	void SkillIncrease(sf::Keyboard::Key key);
	void dialogueCheck();

	//Render / Draw
	void renderPlayer(sf::RenderTarget& target);
	void renderNPCs(sf::RenderTarget& target);
	void renderGUI(sf::RenderTarget& target);
	void render();
	void run();
};


#include "Game.h"

#pragma region INITIALIZATION

void Game::initVariables()
{
	// Boolean Variables
	this->endGame = false;

	// State Variables
	this->GameState = StartMenu;
	this->invS = noState; 
	this->skills = noMenu; 

	// Position of screen center
	this->pos = sf::Vector2f(this->ScreenSize.x / 2, this->ScreenSize.y / 2);
	this->sfx.playMenuMusic();
	// Time Variables
	this->deltaTime = sf::Time::Zero;
}

void Game::initWindow()
{
	this->ScreenSize = sf::Vector2f(800, 600);
	this->videomode = sf::VideoMode(this->ScreenSize.x, this->ScreenSize.y);
	this->window = new sf::RenderWindow(this->videomode, "Prison Escape!", sf::Style::Close | sf::Style::Titlebar); //setting the window
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true); // controlling the refresh rate in line with the vertical frequency of the monitor
}

void Game::initView()
{
	view.reset(sf::FloatRect(0, 0, ScreenSize.x, ScreenSize.y)); // setting the view to the screen
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // from the left point(start point to width scale), top(start to screen height scale), screen width scale, screen height scale
	view.zoom(1.0f); // zooming out 
}
#pragma endregion

#pragma region CONSTRUCTOR / DESTRUCTOR
Game::Game()
{
	this->initWindow();
	this->initView();
	this->initVariables();
}

Game::~Game()
{
	delete this->window;
	delete &view;
	delete &player;
	delete &guard;
	delete &prisoner;
	delete &nurse;
	delete &warden;
}
#pragma endregion

#pragma region CONSTANTS
const bool & Game::getEndGame() const
{
	return this->endGame;
}
const bool Game::running() const
{
	return true;
}
const bool Game::gameOver() const
{
	return gui.healthBar <= 0;
}
#pragma endregion

#pragma region UPDATING
void Game::NPCCollision()
{
	for (int i = 0; i < prisoner.sprites.size(); i++) {
		if (this->player.getBounds().intersects(prisoner.sprites[i].getGlobalBounds())) {
			prisoner.CollisionResponse();
			player.CollisionResponse();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				prisonD.dialogueCheck = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				std::cout << "prisoner Hit" << std::endl;
				prisoner.prisonerAttacked = true;
				prisoner.PrisonerAttackedChoice(i); // telling the prisoner class who was attacked
				prisoner.prisonerHealth[i] -= player.getDamage() + player.getStrength(); // temporary value until strength and skills are implemented
				std::cout << "Player Damage was: " << player.getDamage() + player.getStrength() << std::endl;
				std::cout << "Prisoner Health: " << prisoner.prisonerHealth[i] << std::endl;
				gui.prisonerRep -= 10;
				sfx.punchEffect(options);
			}
		}
		else {
			this->prisoner.PState == IDLE; // making the prisoner go back to idle after interaction
		}
	}
	for (int i = 0; i < guard.sprites.size(); i++) {
		if (this->player.getBounds().intersects(guard.sprites[i].getGlobalBounds())) {
			player.CollisionResponse();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				this->guardD.dialogueCheck = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				this->guard.health -= 10; // temporary value until strength and skills are implemented
				gui.guardRep -= 10;
				sfx.punchEffect(options);
			}
		}
		else {
			this->guard.GState == guardIDLE;// making the guard go back to idle after interaction
		}
	}
	for (int i = 0; i < this->warden.sprites.size(); i++) {
		if (player.getBounds().intersects(warden.sprites[i].getGlobalBounds())) {
			player.CollisionResponse();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				warden.health -= 10;  // temporary value until strength and skills are implemented
				gui.guardRep -= 1;
				sfx.punchEffect(options);
			}
		}
	}
	for (int i = 0; i < nurse.sprites.size(); i++) {
		if (this->player.getBounds().intersects(nurse.sprites[i].getGlobalBounds())) {
			player.CollisionResponse();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				nurse.health -= 10;
				gui.guardRep -= 1;
				sfx.punchEffect(options);
			}
		}
	}
}
void Game::objectCollision()
{
	// DOOR COLLISION
	for (int i = 0; i < doors.doors.size(); i++) {
		if (this->player.getBounds().intersects(doors.doors[i].getGlobalBounds())) {
			player.CollisionResponse();// stops player movement
			sfx.openDoorEffect(options);

			if (doors.doors[i].getRotation() == 90) { // if the door is at a 90 degree angle, move it down if not move it right

				doors.doors[i].move(sf::Vector2f(0, 64));

			}
			else {
				doors.doors[i].move(sf::Vector2f(64, 0));
			}
		}

		if (prisoner.getBounds().intersects(doors.doors[i].getGlobalBounds())) {
			prisoner.CollisionResponse(); // stops player movement
		}

		if (guard.getBounds().intersects(doors.doors[i].getGlobalBounds())) {
			guard.CollisionResponse(); // stops player movement
		}

		if (nurse.getBounds().intersects(doors.doors[i].getGlobalBounds())) {
			nurse.CollisionResponse(); // stops player movement
		}

		if (warden.getBounds().intersects(doors.doors[i].getGlobalBounds())) {
			warden.CollisionResponse(); // stops player movement
		}
	}

	for (int i = 0; i < walls.Walls.size(); i++) {
		if (this->player.getBounds().intersects(walls.Walls[i].getGlobalBounds())) {
			player.CollisionResponse();// stops player movement
			sfx.collisionEffect(options);
		}

		if (prisoner.getBounds().intersects(walls.Walls[i].getGlobalBounds())) {
			prisoner.CollisionResponse(); // stops player movement

		}


		if (guard.getBounds().intersects(walls.Walls[i].getGlobalBounds())) {
			guard.CollisionResponse(); // stops player movement
		}


		if (nurse.getBounds().intersects(walls.Walls[i].getGlobalBounds())) {
			nurse.CollisionResponse(); // stops player movement
		}

		if (warden.getBounds().intersects(walls.Walls[i].getGlobalBounds())) {
			warden.CollisionResponse(); // stops player movement
		}
	}

	// Furniture Collision
	for (int i = 0; i < furniture.furniture.size(); i++) {
		if (this->player.getBounds().intersects(furniture.furniture[i].getGlobalBounds())) {
			player.CollisionResponse();// stops player movement

			if (i >= 18 && i <= 27) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed Locker - code Number: " << i << std::endl;
					invS = LockerInv;
				}
			}
			if (i >= 28 && i <= 38) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed Bin - code Number: " << i << std::endl;
					invS = BinInv;
				}
			}
			if (i >= 69 && i <= 73) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed Footlocker - code Number: " << i << std::endl;
					invS = FtLockerInv;
				}
			}
			if (i >= 89 && i <= 95) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed Desk - code Number: " << i << std::endl;
					invS = DeskInv;
				}
			}
			if (i >= 133 && i <= 134) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed ToolsCabinet - code Number: " << i << std::endl;
					invS = TlsCbInv;
				}
			}
			if (i >= 137 && i <= 138) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					std::cout << "Accessed Dumpster - code Number: " << i << std::endl;
					invS = DumpsterInv;
				}
			}
		}

		if (prisoner.getBounds().intersects(furniture.furniture[i].getGlobalBounds())) {
			this->prisoner.CollisionResponse(); // stops player movement

		}

		if (guard.getBounds().intersects(furniture.furniture[i].getGlobalBounds())) {
			this->guard.CollisionResponse(); // stops player movement

		}

		if (nurse.getBounds().intersects(furniture.furniture[i].getGlobalBounds())) {
			nurse.CollisionResponse(); // stops player movement
		}

		if (warden.getBounds().intersects(furniture.furniture[i].getGlobalBounds())) {
			warden.CollisionResponse(); // stops player movement
		}

	}
}
void Game::skillItemCollision()
{
	for (int i = 0; i < skillitems.skillItems.size(); i++) {
		if (player.getBounds().intersects(skillitems.skillItems[i].getGlobalBounds())) {
			player.CollisionResponse(); // stops player movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				if (i <= 5) {
					std::cout << "Interaction made with bike" << std::endl;
					skills = bikeMenu;
				}
				if (i >= 6 && i <= 11) {
					std::cout << "Interaction made with Weights Bench" << std::endl;
					skills = weightsMenu;
				}
				else if (i >= 12 && i <= 28) {
					std::cout << "Interaction made with bookshelf" << std::endl;
					skills = bookshelfMenu;
				}
			}
		}

		if (prisoner.getBounds().intersects(skillitems.skillItems[i].getGlobalBounds())) {
			prisoner.CollisionResponse(); // stops player movement

		}

		if (guard.getBounds().intersects(skillitems.skillItems[i].getGlobalBounds())) {
			guard.CollisionResponse(); // stops player movement

		}

		if (nurse.getBounds().intersects(skillitems.skillItems[i].getGlobalBounds())) {
			nurse.CollisionResponse(); // stops player movement

		}

		if (warden.getBounds().intersects(skillitems.skillItems[i].getGlobalBounds())) {
			warden.CollisionResponse(); // stops player movement
		}
	}
}
void Game::updatePlayer(sf::Time deltaTime)
{
	player.update(deltaTime);

	if (player.getHealth() <= 0) {
		// end game here
		endGame = true;
	}
}
void Game::updateNPCs(sf::Time deltaTime)
{
	this->prisoner.update(deltaTime);
	this->warden.update(deltaTime);
	this->nurse.update(deltaTime);
	this->guard.update(deltaTime);
}
void Game::updateGameState(sf::Keyboard::Key key) {
	if (this->GameState == StartMenu) {
		menu.KeyHandler(this->ev.key.code);
	}
	else if (this->GameState == SkillsMenu) {
		skillmenu.keyHandler(this->ev.key.code);
		std::cout << "GameState: Skills Menu" << std::endl;

	}
	else if (this->GameState == Options) {
		options.keyHandler(this->ev.key.code);
		std::cout << "GameState: Options Menu" << std::endl;
	}
	else if (this->GameState == InstructionsMenu) {
		instructions.keyHandler(this->ev.key.code);

	}
	else if (this->GameState == PrisonGame) {
		std::cout << "GameState: Prison Game" << std::endl;
		if (gui.healthBar <= 0) {
			GameState = GameOverMenu;
			std::cout << "You were beaten to death" << std::endl;
		}
		keyHandler(this->ev.key.code);
	}
	else if (this->GameState == GameOverMenu) {
		std::cout << "GameState: Game Over" << std::endl;
		gameover.KeyHandler(this->ev.key.code);
	}
}
void Game::updatePollEvents(sf::Time deltaTime)
{
	// use window events for keyboard input
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::KeyPressed: // handling the Key pressed events (mostly in other classes)
			if (GameState == PrisonGame) {
				this->player.playerKeyboardMovement(this->ev.key.code, this->deltaTime);
			}
			break;
		case sf::Event::KeyReleased:
			this->updateGameState(this->ev.key.code);
			break;
		case sf::Event::MouseButtonPressed: // case for mouse used
			break;
		case sf::Event::MouseButtonReleased:
			break;
		case sf::Event::Closed:
			exit(1); // exiting the program if the close button is pressed
			break;
		}
	}
}
void Game::keyHandler(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::S) { //skills
		gui.skillsOpening();
		std::cout << "S pressed" << std::endl;
	}
	if (key == sf::Keyboard::L) {
		this->player.addStrength(1);
	}
	else if (key == sf::Keyboard::M) { //missions
		gui.missionsOpening();
		std::cout << "M pressed" << std::endl;
	}
	else if (key == sf::Keyboard::R) { //reputation
		gui.reputationOpening();
		std::cout << "R pressed" << std::endl;
	}
	else if (key == sf::Keyboard::I) { // inventory
		gui.inventoryOpening();
		std::cout << "I pressed" << std::endl;
	}
	else if (key == sf::Keyboard::C) {
		gui.craftingOpening();
		std::cout << "C pressed" << std::endl;
	}
	else if (key == sf::Keyboard::X) { // simple button click to close all states
		invS = noState;
		skills = noMenu;
	}
}
void Game::updateCollision()
{
	this->objectCollision();

	this->skillItemCollision();

	this->NPCCollision();
}
void Game::updateView()
{
	view.setCenter(pos);
	view.move(player.getPos().x - (this->ScreenSize.x / 2), player.getPos().y - (this->ScreenSize.y / 2));
}
void Game::update(sf::Time deltaTime)
{
	if (this->endGame == false) {
		this->updatePollEvents(deltaTime);
		if (GameState == PrisonGame) {
			this->gui.update(deltaTime);
			this->updatePlayer(deltaTime);
			this->updateView();
			this->updateCollision();
		}
	}
}
#pragma endregion

#pragma region GAME LOGIC
void Game::GUIOptions() {
	if (gui.SkilOpen == true) {
		gui.drawSkills(view, *this->window);
	}
	if (gui.MisOpen == true) {
		gui.drawMissions(view, *this->window);
	}
	if (gui.InvOpen == true) {
		gui.drawInventory(view, *this->window);
	} if (gui.RepOpen == true) {
		gui.drawReputation(view, *this->window);
	}
	if (gui.craftOpen == true) {
		gui.drawCraft(view, *this->window);
	}
}
void Game::SkillIncrease(sf::Keyboard::Key key) {
	if (skills == bookshelfMenu) { 
		// if the bookshelf is accessed, open up the skills item hud and increase knowledge by playing minigame (not yet implemented)
		this->skillitems.knowledgeIncrease(*this->window, view, key);
	}
	else if (skills == bikeMenu) { 
		// if the bike is accessed, open up the skills item hud and increase knowledge by playing minigame (not yet implemented)
		this->skillitems.staminaIncrease(*this->window, view, key);
	}
	else if (skills == weightsMenu) {
		// if the weights bench is accessed, open up the skills item hud and increase knowledge by playing minigame (not yet implemented)
		this->skillitems.strengthIncrease(*this->window, view, key);
	}
}
void Game::dialogueCheck() {
	if (prisonD.dialogueCheck == true) {
		prisonD.dialogueHandler(view, *this->window, gui);
	}
	if (guardD.dialogueCheck == true) {
		guardD.dialogueHandler(view, *this->window, gui);
	}
}
#pragma endregion

#pragma region RENDERING

#pragma region STATE_CHANGES
void Game::StateChange(sf::RenderTarget& target)
{
	// GAME STATE ---- START MENU ----
	if (GameState == StartMenu) {
		this->menu.render(target);
		this->menu.MouseHandler(*this->window);
		this->startMenuStateChange();
	}

	// GAMESTATE ---- OPTIONS ----- 
	if (GameState == Options) {
		//draw menu
		this->options.render(*this->window);
		this->optionsMenuStateChange();
		this->options.mouseHandler(*this->window);
		this->sfx.setMusicVolume(this->options);
	}

	// GAMESTATE ---- INSTRUCTIONS MENU ----
	if (GameState == InstructionsMenu) {
		this->instructions.render(*this->window);
		this->InstructionsMenuStateChange();
		this->instructions.mouseHandler(*this->window);

	}
	// GAMESTATE --- SKILLS MENU ----
	if (GameState == SkillsMenu) {
		this->skillmenu.render(*this->window);
		this->SkillsMenuStateChange();
		this->skillmenu.mouseHandler(*this->window);

	}
	// GAMESTATE ---- PRISON GAME ----
	if (GameState == PrisonGame)
	{
		this->gui.MouseInput(*this->window);
		if (gui.InvOpen == true) {
			this->gui.craftingMouseInput(*this->window);
		}
		this->prisonD.mouseHandler(*this->window, this->gui);
		
		this->guardD.mouseHandler(*this->window, this->gui);
		this->renderGame();
	}
	// GAMESTATE ---- GAME OVER ----
	if (GameState == GameOverMenu) { // draw Game Over Screen here
		gameover.render(*this->window, view); // drawing end game screen

	}
}
void Game::startMenuStateChange() {
	if (menu.playPressed == true) {
		menu.playPressed = false;
		GameState = SkillsMenu;
	}
	if (menu.optionsPressed == true) {
		menu.optionsPressed = false;
		GameState = Options;
	}
	if (menu.exitPressed == true) {
		this->window->close();
	}
	menu.render(*this->window);
}
void Game::optionsMenuStateChange() {
	if (options.instrucPress == true) {
		options.instrucPress = false;
		GameState = InstructionsMenu;
	}
	if (options.backPress == true) {
		options.backPress = false;
		GameState = StartMenu;
	}
}
void Game::InstructionsMenuStateChange() {
	if (instructions.backPress == true) {
		instructions.backPress = false;
		GameState = Options;
	}
}
void Game::SkillsMenuStateChange() {
	if (skillmenu.exitPress == true) {
		skillmenu.exitPress = false;
		GameState = StartMenu;
	}
	if (this->skillmenu.gamePress == true) {
		this->skillmenu.gamePress = false;
		GameState = PrisonGame;
	}
}
#pragma endregion

#pragma region DRAWING
void Game::renderInventoryOptions() {
	if (this->invS == LockerInv) { furninv.drawLocker(this->view, *this->window, gui); }
	else if (invS == BinInv) { furninv.drawBin(this->view, *this->window, gui); }
	else if (invS == FtLockerInv) { furninv.drawFootLocker(this->view, *this->window, gui); }
	else if (invS == DeskInv) { furninv.drawDesk(this->view, *this->window, gui); }
	else if (invS == TlsCbInv) { furninv.drawToolsCabinet(this->view, *this->window, gui); }
	else if (invS == DumpsterInv) { furninv.drawBigBin(this->view, *this->window, gui); }
}
void Game::renderGame() {
	this->map.drawMap(*this->window);
	this->renderPlayer(*this->window);
	this->renderNPCs(*this->window);
	this->renderGUI(*this->window);
	this->walls.render(*this->window);
	this->furniture.render(*this->window);
	this->doors.render(*this->window);
	this->skillitems.render(*this->window);
	this->gui.drawGUI(view, *this->window);
	this->renderInventoryOptions();
	this->GUIOptions();
	this->SkillIncrease(this->ev.key.code);
	this->dialogueCheck();
}
#pragma endregion

void Game::renderPlayer(sf::RenderTarget &target)
{
	this->player.render(target);
}
void Game::renderNPCs(sf::RenderTarget &target)
{
	this->prisoner.render(target);
	this->guard.render(target);
	this->nurse.render(target);
	this->warden.render(target);
}
void Game::renderGUI(sf::RenderTarget &target)
{
	this->gui.render(target);
}
void Game::render()
{
	//Clearing the window before drawing
	this->window->clear(sf::Color::Black);

	//Setting the view
	this->window->setView(this->view);

	// State Changes
	this->StateChange(*this->window);

	//Displaying the items
	this->window->display();
}
void Game::run()
{
	while (this->window->isOpen()) {
		deltaTime += clock.restart(); // updating deltatime
		this->update(deltaTime); // Update via frame time
		this->render(); // Render to the window
	}
}
#pragma endregion



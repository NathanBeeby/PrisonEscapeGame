
#include "Game.h"
/*

TODO -

\\\\\\\\\\\\\\\\\\\\\          MINIMUM VIABLE PRODUCT TO SEND OUT			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- FIX SKILLS MENU NOT DISPLAYING SKILLS TO GUI
- FIX INVENTORY ITEMS NOT FOLLOWING THEIR CONTAINER
- FIX RANDOMIZATION OF INVENTORY ITEMS
- FIX PRISONERS AND GUARDS NOT ATTACKING ONCE ATTACKED
- FIX VECTOR OUT OF RANGE ISSUE WHEN CLICKING ITEMS IN BIN

\\\\\\\\\\\\\\\\\\\\\          MINIMUM VIABLE PRODUCT TO SEND OUT			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




\\\\\\\\\\\\\\\\\\\\\		   Things to be Implemented		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Add NPC AI path finding
- Add AI Idle moving
- Add AI Chase Prisoner
- Add AI Running away

- Put mouse input code into their respective files
- Implement structs for objects which are stored in chests
- Watch youtube video on structs & interfaces in C++
- Watch SFML Inventory video
- watch SFML crafting tutorial video
- Clean Up Code

\\\\\\\\\\\\\\\\\\\\\		   Things to be Implemented		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Implement NPC movement within NPC class and call it in the classes for guard, prisoner, warden and nurse

- Implement better crafting and removing objects when clicked upon in inventory

- Create a mini game within the game for the skill items to give skills

- Create path finding for AI to follow and attack player

AI: Path Finding Algorithm A* - Use on all characters, use the given states in the class to change their behavior _ PATH FOLLOW and PLAYER FOLLOW (make sure collision works on it)

*/

int main()
{
	//Initializing the game
	Game game;

	//Game Loop
	while (game.running()) {
		game.run();
	}

	//End of application
	return 0;
}


#include "Game.h"
/*

TODO -

\\\\\\\\\\\\\\\\\\\\\          ISSUES NEED RESOLVING			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- FIX SKILLS MENU NOT DISPLAYING SKILLS TO GUI
- FIX INVENTORY ITEMS NOT FOLLOWING THEIR CONTAINER
- FIX RANDOMIZATION OF INVENTORY ITEMS
- FIX PRISONERS AND GUARDS NOT ATTACKING ONCE ATTACKED
- FIX VECTOR OUT OF RANGE ISSUE WHEN CLICKING ITEMS IN BIN

\\\\\\\\\\\\\\\\\\\\\          ISSUES NEED RESOLVING			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


\\\\\\\\\\\\\\\\\\\\\		   Things to be Implemented		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Add NPC AI path finding (Idle moving, Chase Prisoner, Running away)
- Implement Crafting new items by existing items
- Implement keys for doors
- Implement doors not opening unless you have a specific key
- Implement Missions and rewards for missions
- Create a mini game within the game for the skill items to give skills

\\\\\\\\\\\\\\\\\\\\\		   Things to be Implemented		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

*/

int main()
{
	//Initializing the game
	Game game;

	//Game loop
	while (game.running()) {
		game.run();
	}

	//End of application
	return 0;
}


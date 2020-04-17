
#include "Game.h"
/*

TODO -

\\\\\\\\\\\\\\\\\\\\\          MINIMUM VIABLE PRODUCT TO SEND OUT			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


When issues are mitigated to the best possibility on the end of the 18th, clean up code, add things to their parent class, 
such as dialogue, object, menumanager and character

- We get a vector subscript out of range error when using the mouse handler within the GUI or dialogue options. Fix this. 
(Suspect this is from GUI class, began happening with AI Dialogue with mouse input, then furthered when I modified the GUI)

 GAME CLASS
- Fix collision distance of skill items / prisoners etc - add extra distance.
- Fix skills not displaying from skill menu to GUI skills menu


- Fix Inventory item texture randomizing on click and removal of item
- Fix Inventory Items moving when character moves
- Fix GUI showing no Inventory Item one accessed another one
- Fix bookshelf, exercise bike and weights not giving skills

\\\\\\\\\\\\\\\\\\\\\          MINIMUM VIABLE PRODUCT TO SEND OUT			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




\\\\\\\\\\\\\\\\\\\\\		   Implementations		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

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

\\\\\\\\\\\\\\\\\\\\\		   Implementations		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Implement movement for AI within NPC code

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


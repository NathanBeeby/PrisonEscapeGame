
#include "Game.h"
/*

TODO -


\\\\\\\\\\\\\\\\\\\\\          BUG FIXES			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Need to fix the player not rendering until movement, no doubt due to the players sprite.

- Fix skills not displaying from skill menu to GUI skills menu

- Need to fix prisoner dialogue collision

- FIX the player stats not showing in the skills menu when pressing S

- Update NPC in prison Bitch Gamestate breaks the game

- Remove items from the HUD when you click them into your inventory (within InventoryItems, when clicking an inv item, it doesn't remove the texture, just the object and switches texture)

- GUI stats are not stored when opening skill menu

- Fix Furniture Inventory Items not having items / randomizing once you've accessed one of the furniture inventories

- Fix Inventory item texture randomizing on click and removal of item

- Fix guards showing all guard textures (should only show 1 texture per movement frame)

- Fix GUI showing no Inventory Item one accessed another one

- Fix Nurse not displaying on screen

- Fix bookshelf, exercise bike and weights not giving skills
\\\\\\\\\\\\\\\\\\\\\          BUG FIXES			 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


\\\\\\\\\\\\\\\\\\\\\		   Implementations		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

- Add NPC AI path finding
- Add AI Idle moving
- Add AI Chase Prisoner
- Add AI Running away

- Put mouse input code into their respective files
- preferrably make the Game file less than 400 lines of code by seperating the code out
- Add a gamestate manager class to control the gamestates
- Implement functions through the menu manager class and implement menu variables through the menu manager
- Look through common functionality that the character classes have and implement it in the character class
- Look through object files and find common functionality to add to the object files
- Look through dialogue files and find common functionality to add to the dialogue manager class

- Implement structs for objects which are stored in chests
- Watch youtube video on structs & interfaces in C++
- Watch SFML Inventory video
- watch SFML crafting tutorial video


\\\\\\\\\\\\\\\\\\\\\		   Implementations		 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


- IMPLEMENT COLLISION within the Character class

- Only add NPC Collision if the NPC is in view

- Attempt culling items that dont need to be there (delete items when used or not in view etc)

- Make it so that the view cant go past the outer wall

- Implement movement for AI within NPC code

- Implement different States for the AI

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


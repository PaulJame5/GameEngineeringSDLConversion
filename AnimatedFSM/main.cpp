#include <Defines.h>

#include <SDL_main.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "Texture.h"
#include <Player.h>
#include <Events.h>
#include <Debug.h>
#include "InputKeyboard.h"


int main(int argc, char* args[])
{
	// Create the main window
	RenderWindow* window = new RenderWindow("SDL Conversion", 800, 600);

#pragma region TextureLoading

	// Load a sprite to display
	Texture* player_texture;
	if (!player_texture->loadTextureFromFile(PLAYER_SPRITES, window))
	{
		DEBUG_MSG("Failed to load file");
		if (!player_texture->loadTextureFromFile(ERROR_SPRITES, window))
		{
			return EXIT_FAILURE;
		}
	}

#pragma endregion

#pragma region AnimatedSprite

	// Setup Players Default Animated Sprite
	AnimatedSprite player_animated_sprite(player_texture);
	InputKeyboard inputKeyboard;
#pragma endregion

	Player player(player_animated_sprite);

	gpp::Events input;

	bool exit = false;
	// Start the game loop
	while (!exit)
	{
		inputKeyboard.Update();

		// Died Event
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_D))
		{
			DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
			input.setCurrent(gpp::Events::Event::DIED_EVENT);
		}

		// Revieved Event
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_R)) {
			DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
			input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
		}
		// Running attack
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_Z)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			||
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_Z))
		{
			DEBUG_MSG("gpp::Events::Event::ATTACK_START");
			input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
		}
		// Attack
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_Z))
		{
			DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
			input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
		}
		// Throw attack
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_X)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			||
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_X)
			)
		{
			DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
			input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
		}
		// Throw Attack
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_X))
		{
			DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
			input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
		}
		// Run Right
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT))
		{
			DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
			input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
		}
		// Climb Up
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_UP))
		{
			DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
			input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
		}
		// Climb Down
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_DOWN))
		{
			DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
			input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
		}
		// Hit Bottom of Ladder Event
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_C))
		{
			DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
			input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
		}
		// Hit Top of Ladder Event
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_T))
		{
			DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
			input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
		}
		// Jump Run
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_SPACE)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			||
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_SPACE)
			)
		{
			DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
			input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
		}
		// Jump Event
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_SPACE))
		{
			DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
			input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
		}
		// Running Slide
		if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_DOWN)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			||
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_RIGHT)
			&&
			inputKeyboard.IsKeyPressed(SDL_SCANCODE_DOWN)
			)
		{
			DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
			input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
		}
		// Hit Ground Event
		else if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_H))
		{
			DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
			input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
		}

		// Jump Attack Event
		else if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_H))
		{
			DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
			input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
		}

		// Jump Throw Attack Event
		else if (inputKeyboard.IsKeyPressed(SDL_SCANCODE_H))
		{
			DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
			input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
		}

		// Deal with KeyReleased
		// Run and Stop Attack

		if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_Z)
			&&
			inputKeyboard.IsKeyReleased(SDL_SCANCODE_RIGHT))
		{
			DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
			input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
		}
		// Stop Attack
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_Z))
		{
			DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
			input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
		}
		// Run and Stop Throw Attack
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_X)
			&&
			inputKeyboard.IsKeyReleased(SDL_SCANCODE_RIGHT))
		{
			DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
			input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
		}
		// Stop Throw Attack
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_X))
		{
			DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
			input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
		}
		// Stop Running Right
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_RIGHT))
		{
			DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
			input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
		}
		// Stop Slide
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_DOWN)
			&&
			inputKeyboard.IsKeyReleased(SDL_SCANCODE_RIGHT))
		{
			DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
			input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
		}
		// Stop Moving Up
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_UP))
		{
			DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
			input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
		}
		// Stop Moving Down
		else if (inputKeyboard.IsKeyReleased(SDL_SCANCODE_DOWN))
		{
			DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
			input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
		}

		DEBUG_MSG("gpp::Events::Event::NONE");
		input.setCurrent(gpp::Events::Event::NONE);

		// Handle input to Player
		player.handleInput(input);


		// Update the Player
		player.update();

		// Clear screen
		window->clear();

		// Draw the Players Current Animated Sprite
		window->display(player.getAnimatedSpriteFrame());

		// Update the window
		window->display();
	} // end game loop

	return EXIT_SUCCESS;
}


//#include <SDL_main.h>
//#include <SDL.h>
//#include <SDL_image.h>
//#include <iostream>
//#include "Sprite.h"
//#include "Texture.h"
//
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
////The image we will load and show on the screen
//SDL_Surface* gHelloWorld = NULL;
//
//void close();
//
//int main(int argc, char* args[])
//{
//	RenderWindow* window = new RenderWindow("sdl Test", SCREEN_WIDTH, SCREEN_HEIGHT);
//
//	//Sprite spriteObject = Sprite("img.png",  window);
//	//Sprite spriteObject = Sprite("assets/Kunai.png", window);
//	Texture* texture = new Texture();// = new Texture("assets/Kunai.png", window);
//	Sprite spriteObject;
//	if (!texture->loadTextureFromFile("assets/Kunai.png", window))
//	{
//		printf("notloaded");
//	}
//	spriteObject.setTexture(texture);
//
//	bool exit = false;
//
//	while (!exit)
//	{
//		window->clear();
//		window->addToRenderQueue(spriteObject);
//		window->draw();
//	}
//
//	//Free resources and close SDL
//	close();
//
//	return 0;
//}
//
//
//void close()
//{
//	//Deallocate surface
//	SDL_FreeSurface(gHelloWorld);
//	gHelloWorld = NULL;
//
//
//	//Quit SDL subsystems
//	SDL_Quit();
//}

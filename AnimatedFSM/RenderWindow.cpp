#pragma once
#include "RenderWindow.h"

RenderWindow::RenderWindow(std::string windowName, unsigned int screenWidth, unsigned int screenHeight)
{
	window = NULL;
	renderer = NULL;

	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return;
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		printf("could not create rendering window");
		return;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize PNG! SDL_image Error: %s\n", IMG_GetError());
		return;
	}
	// Initialise Jpeg Loading
	imgFlags = IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize JPG! SDL_image Error: %s\n", IMG_GetError());
		return;
	}
}

RenderWindow::~RenderWindow()
{
	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;
}

void RenderWindow::addToRenderQueue(SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_RenderPresent(renderer);
}
//
void RenderWindow::addToRenderQueue(Sprite sprite)
{
	SDL_RenderCopyEx(renderer, sprite.getTexture()->get(), &sprite.getTextureRect(), &sprite.getSpriteBillBoard(), .0f, &sprite.getRotationOrigin(), SDL_RendererFlip::SDL_FLIP_NONE);
}

void RenderWindow::draw()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

SDL_Renderer* RenderWindow::getRenderer()
{
	return renderer;
}




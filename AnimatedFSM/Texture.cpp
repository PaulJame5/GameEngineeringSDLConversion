#pragma once
#include "Texture.h"

Texture::Texture()
{
}

Texture::Texture(std::string textureUrl, RenderWindow* renderWindow)
{
	texture = loadTexture(textureUrl, renderWindow);
}

Texture::~Texture()
{
}

SDL_Texture* Texture::get()
{
	return texture;
}

bool Texture::loadTextureFromFile(std::string textureUrl, RenderWindow* renderWindow)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(textureUrl.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load Image %s! SDL_IMage Error:%s\n", textureUrl.c_str(), IMG_GetError());
		return false;
	}
	newTexture = SDL_CreateTextureFromSurface(renderWindow->getRenderer(), loadedSurface);

	SDL_FreeSurface(loadedSurface);
	texture = newTexture;
	return true;
}

SDL_Texture* Texture::loadTexture(std::string textureUrl, RenderWindow* renderWindow)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(textureUrl.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load Image %s! SDL_IMage Error:%s\n", textureUrl.c_str(), IMG_GetError());
		return NULL;
	}
	newTexture = SDL_CreateTextureFromSurface(renderWindow->getRenderer(), loadedSurface);

	SDL_FreeSurface(loadedSurface);
	return newTexture;
}


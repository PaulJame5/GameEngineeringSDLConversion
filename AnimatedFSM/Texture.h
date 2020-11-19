#pragma once

#ifndef __TEXTURE__
#define __TEXTURE__
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "RenderWindow.h"


class Sprite;
class RenderWindow;

class Texture
{
public:
	Texture();
	Texture(std::string textureUrl, RenderWindow* renderWindow);
	~Texture();

	SDL_Texture* get();
	bool loadTextureFromFile(std::string textureUrl, RenderWindow* renderWindow);
private:
	SDL_Texture* texture;
	SDL_Texture* loadTexture(std::string textureUrl, RenderWindow* renderWindow);

};
#endif __TEXTURE__
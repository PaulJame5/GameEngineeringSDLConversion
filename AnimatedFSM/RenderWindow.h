#pragma once
#ifndef __RENDERWINDOW__
#define __RENDERWINDOW__
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Sprite.h"

class Sprite;
class RenderWindow
{
public :
	RenderWindow(std::string windowName, unsigned int screenWidth, unsigned int screenHeight);
	~RenderWindow();
	void addToRenderQueue(SDL_Texture* texture);
	void addToRenderQueue(Sprite sprite);
	void draw();
	void clear();

	SDL_Renderer* getRenderer();
private:
	//SDL_Surface* loadSurface(std::string path);
	//The window we'll be rendering to
	SDL_Window* window;

	SDL_Renderer* renderer;
};
#endif __RENDERWINDOW__
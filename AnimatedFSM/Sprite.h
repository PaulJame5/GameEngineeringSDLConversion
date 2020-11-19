#pragma once

#ifndef __SPRITE__
#define __SPRITE__
#include <SDL.h>
#include <string>
#include "Texture.h"
#include "RenderWindow.h"

class Texture;

class RenderWindow;
class Sprite
{
public:
	Sprite();
	Sprite(std::string imgUrl, RenderWindow *window);
	Sprite(Texture* texture);
	~Sprite();
	SDL_Rect getTextureRect();
	void setTextureRect(int x, int y, int width, int height);
	void setTextureRect(SDL_Rect spriteTextureBounds);
	SDL_Rect getSpriteBillBoard();
	SDL_Point getRotationOrigin();

	void setPosition(int x, int y);
	void setPositionX(int x);
	void setPositionY(int y);

	void setScaleX(float x);
	void setScaleY(float y);
	float getXScale();
	float getYScale();
	void setScale(float x, float y);

	void setAngleDegrees(float angle);
	float getAngleDegrees();

	Texture* getTexture();
	void setTexture(Texture* texture);

	void initialise(std::string imgUrl, RenderWindow* window);
	void setAsAnimationTexture();
	bool isAnimationTexture();
private:

	SDL_Rect spriteTextureBounds = { 0, 0 , 0 , 0 };
	// position x, poisition y, width, height 
	SDL_Rect spriteBillBoard = { 0 ,0 , 0, 0};
	SDL_Point rotationOrigin = { 0, 0 };
	Texture* texture;

	float xScale = 1;
	float yScale = 1;

	float angleDegrees = 0;
	bool animationTexture = false;

	//SDL_Surface* loadSurface(std::string path, RenderWindow window);
};

#endif __SPRITE__
#pragma once
#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(std::string imgUrl, RenderWindow* renderWindow)
{
	initialise(imgUrl, renderWindow);
}

Sprite::Sprite(Texture* texture)
{
	this->texture = texture;

	// We Query because no data has been supplied so 
	// we shall presume the whole texture is used
	int w, h;
	SDL_QueryTexture(texture->get(), NULL, NULL, &w, &h);

	// Angle Rotation Origin
	rotationOrigin.x = 0;
	rotationOrigin.y = 0;

	// Bound to the whole texture
	spriteTextureBounds = { 0,0, w, h };

	// position
	spriteBillBoard.x = 0;
	spriteBillBoard.y = 0;

	xScale = 1;
	yScale = 1;

	// fit to Pixel Scale
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}


Sprite::~Sprite()
{
	
}

SDL_Rect Sprite::getTextureRect()
{
	return spriteTextureBounds;
}

void Sprite::setTextureRect(int x, int y, int width, int height)
{
	spriteTextureBounds = { x, y, width, height };
	// Update Billboard
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}
void Sprite::setTextureRect(SDL_Rect spriteTextureBounds)
{
	this->spriteTextureBounds = spriteTextureBounds;
	// Update Billboard
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}

SDL_Rect Sprite::getSpriteBillBoard()
{
	return spriteBillBoard;
}

SDL_Point Sprite::getRotationOrigin()
{
	return rotationOrigin;
}

void Sprite::setPosition(int x, int y)
{
	spriteBillBoard.x = x;
	spriteBillBoard.y = y;
}

void Sprite::setPositionX(int x)
{
	spriteBillBoard.x = x;
}

void Sprite::setPositionY(int y)
{
	spriteBillBoard.y = y;
}

void Sprite::setScaleX(float x)
{
	xScale = x;
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
}

void Sprite::setScaleY(float y)
{
	yScale = y;
	// fit to Pixel Scale
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}

float Sprite::getXScale()
{
	return xScale;
}

float Sprite::getYScale()
{
	return yScale;
}

void Sprite::setScale(float x, float y)
{
	xScale = x;
	yScale = y;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
}

void Sprite::setAngleDegrees(float angle)
{
	angleDegrees = angle;
}

float Sprite::getAngleDegrees()
{
	return angleDegrees;
}

//SDL_Surface* Sprite::getSprite()
//{
//	return image;
//}

Texture* Sprite::getTexture()
{
	return texture;
}

void Sprite::setTexture(Texture* texture)
{
	this->texture = texture;

	// We Query because no data has been supplied so 
	// we shall presume the whole texture is used
	int w, h;
	SDL_QueryTexture(texture->get(), NULL, NULL, &w, &h);

	// Angle Rotation Origin
	rotationOrigin.x = 0;
	rotationOrigin.y = 0;

	// Bound to the whole texture
	spriteTextureBounds = { 0,0, w, h };

	// position
	spriteBillBoard.x = 0;
	spriteBillBoard.y = 0;

	xScale = 1;
	yScale = 1;

	// fit to Pixel Scale
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}

void Sprite::initialise(std::string imgUrl, RenderWindow* renderWindow)
{
	texture = new Texture(imgUrl, renderWindow);

	// We Query because no data has been supplied so 
	// we shall presume the whole texture is used
	int w, h;
	SDL_QueryTexture(texture->get(), NULL, NULL, &w, &h);

	// Angle Rotation Origin
	rotationOrigin.x = 0;
	rotationOrigin.y = 0;

	// Bound to the whole texture
	spriteTextureBounds = { 0,0, w, h };

	// position
	spriteBillBoard.x = 0;
	spriteBillBoard.y = 0;

	xScale = 1;
	yScale = 1;

	// fit to Pixel Scale
	spriteBillBoard.w = spriteTextureBounds.w * xScale;
	spriteBillBoard.h = spriteTextureBounds.h * yScale;
}

void Sprite::setAsAnimationTexture()
{
	animationTexture = true;
}

bool Sprite::isAnimationTexture()
{
	return animationTexture;
}


//SDL_Surface* Sprite::loadSurface(std::string path, RenderWindow window)
//{
//	//The final optimized image
//	SDL_Surface* optimizedSurface = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str(});
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError(});
//	}
//	else
//	{
//		//Convert surface to screen format
//		optimizedSurface = SDL_ConvertSurface(loadedSurface, window.getSurface()->format, 0);
//		if (optimizedSurface == NULL)
//		{
//			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError(});
//		}
//
//		//Get rid of old loaded surface
//		SDL_FreeSurface(loadedSurface);
//	}
//
//	return optimizedSurface;
//}

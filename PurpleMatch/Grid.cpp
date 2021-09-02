#include "Grid.h"

//Constructor
Grid::Grid()
{
}

//Destructuor
Grid::~Grid()
{
}

//SetSprite: sets sprite info (location, size scale, texture)
void Grid::setSprite(int x, int y,int multiplier, Texture& spriteSheet)
{
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(IntRect(17 * multiplier,0, 17, 17));
	//sprite.setScale(Vector2f(2, 2));
	sprite.setPosition(Vector2f(20.f*x, 20.f * y));
}

Sprite Grid::getSprite()
{
	return sprite;
}

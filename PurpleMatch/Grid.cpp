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
void Grid::setSprite(int& posX, int& posY,int& multiplier, Texture& spriteSheet)
{
	//sets id for comparison later
	spriteId = multiplier;
	sprite.setTexture(spriteSheet);
	//Set rectangle (x,y axis location of rectangle) then (x,y) size of rectangle cutter
	//Multiplier refers to order of the sprite in sprite sheet
	sprite.setTextureRect(IntRect(17 * multiplier,0, 17, 17));
	sprite.setPosition(Vector2f(20.f*posX, 20.f * posY));
}

Sprite Grid::getSprite()
{
	return sprite;
}

int Grid::getSpriteId()
{
	return spriteId;
}

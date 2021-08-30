#include "Grid.h"

void Grid::initDimen()
{
	dimen.x = 200.f;
	dimen.y = 200.f;
}

void Grid::initSprite()
{
	if (!texture.loadFromFile("Assets/test.png")) {
		//Error message
		std::cout << "Couldnt find texture";
	}

	sprite.setTexture(texture,true);
}

Grid::Grid()
{
	initDimen();
	initSprite();
}

Grid::~Grid()
{
}

Sprite Grid::getSprite()
{
	return sprite;
}

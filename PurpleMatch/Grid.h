#pragma once
#include "Game.h"
using namespace sf;
class Grid
{
private:
	//Attr
	sf::Vector2f dimen;
	Sprite sprite;
	Texture texture;
	//Private functions
	void initDimen();
	void initSprite();
public:
	//Constructors /Destructors
	Grid();
	~Grid();

	//SendSprite: returns the sprite to be drawn
	Sprite getSprite();
};


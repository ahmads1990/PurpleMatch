#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
using namespace sf;
class Grid
{
private:
	//Private attributes
	Texture texture;
	Sprite sprite;
	//spriteId refers to order of sprite in sprite sheet used to compare between grids
	int spriteId;

	//Private functions
public:
	//Constructors /Destructors
	Grid();
	~Grid();

	//SetSprite: sets sprite info (location, size scale, texture)
	void setSprite(int& posX, int& posY,int& multiplier, Texture& spriteSheet);
	//GetSprite: returns the sprite to be drawn
	Sprite getSprite();
	//GetSpriteId: returns id of sprite for comparison
	int getSpriteId();
};


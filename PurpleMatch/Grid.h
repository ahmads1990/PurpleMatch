#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
using namespace sf;
class Grid
{
private:
	//Attr
	Sprite sprite;
	Texture texture;

	//Private functions
public:
	//Constructors /Destructors
	Grid();
	~Grid();

	//SetSprite: sets sprite info (location, size scale, texture)
	void setSprite(int x, int y,int multiplier, Texture& spriteSheet);
	//GetSprite: returns the sprite to be drawn
	Sprite getSprite();
};


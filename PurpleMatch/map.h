#pragma once

#include "Grid.h"
#include <random>
#include "SFML/Graphics.hpp"
/*
* This class acts as placeholder for grids
*/
class gridMap
{
public:
	sf::Texture texture;
	Grid** gArr;

	//Private functions:
	//LoadTexture: load texture used for grides
	void loadTexture();
public:
	gridMap();
	~gridMap();

	//LoadLevel: Creates Grids 2d array and assign sprites randomly on them
	void loadLevel(int nInRow);

};


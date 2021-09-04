#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "map.h"
#include "Grid.h"
using namespace sf;
/*
	This class will act as the game engine

*/
//Struct used to hold information to init. level
struct levels
{
	//used to describe matrix size 
	int nGridInRow;
};
class Game
{

private:
	// Attrs
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	//GMatrix used as container for grids
	gridMap gMatrix;
	//Levels consist of  3 levels (4x4), (6x6), (8x8)
	levels gamelevel[3];
	int currentLevel;
	// Private Functions
	void initVars();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Isrunning: return if window is running or not
	bool isRunning();
	//GoNextLevel: delete current Gmap and create one with diff size
	void goNextLevel();
	//DrawMatrix: used to draw grids by asking for sprites for each one
	void drawMatrix();
	//Check events: check input events
	void updateEvents();
	//Update
	void update();
	void render();
};


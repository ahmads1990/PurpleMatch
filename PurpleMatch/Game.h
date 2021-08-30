#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Grid.h"
using namespace sf;
/*
	This class will act as the game engine

*/
class Game
{

private:
	// Attrs
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	// Private Functions
	void initVars();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Isrunning: return if window is running or not
	bool isRunning();

	//Check events: check input events
	void updateEvents();
	//Update
	void update();
	void render();
};


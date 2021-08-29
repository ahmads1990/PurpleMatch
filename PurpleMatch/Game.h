#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

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

	//Isrunning
	bool isRunning();
	//Check events
	void updateEvents();
	//Update
	void update();
	void render();
};


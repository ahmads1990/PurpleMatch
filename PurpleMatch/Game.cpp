#include "Game.h"

void Game::initVars()
{
	window = nullptr;
	//Init game levels (4x4), (6x6), (8x8)
	gamelevel[0].nGridInRow = 4;
	gamelevel[1].nGridInRow = 6;
	gamelevel[2].nGridInRow = 8;
	//Current level (0 indexed)
	currentLevel = 0;
}

void Game::initWindow()
{
	//Window size options
	videoMode.width = 960;
	videoMode.height = 540;
	//Init window pointer
	window = new RenderWindow(videoMode, "Test sfml");
}

//Constructors 
Game::Game()
{
	initVars();
	initWindow();
	gMatrix.loadLevel(gamelevel[currentLevel].nGridInRow);
}
// Destructors
Game::~Game()
{
}

//Isrunning: return if window is running or not
bool Game::isRunning()
{
	return window->isOpen();
}

void Game::goNextLevel()
{
	//call destructor of Gmap to delete it
	//temp
	//Check if currentLevel = 2 (end level) 0 index
	if (currentLevel == 2)
	{
		//Todo end game status
		std::cout << "Still not end";
	}
	//else Advance current level by one
	currentLevel++;
	//Call struct to get equiv size of matrix for new level and load new level
	gMatrix.loadLevel(gamelevel[currentLevel].nGridInRow);
}

//Check events: check input events
void Game::updateEvents()
{
	while (this->window->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::update()
{
	this->updateEvents();
}

void Game::render()
{
	this->window->clear();
	gMatrix.drawMatrix(gamelevel[currentLevel].nGridInRow, window);
	this->window->display();
}

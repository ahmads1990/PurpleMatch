#include "Game.h"

void Game::initVars()
{
	window = nullptr;
}

void Game::initWindow()
{
	//Window size options
	videoMode.height = 600;
	videoMode.width = 800;
	//Init window pointer
	window = new RenderWindow(videoMode, "Test sfml");
}

//Constructors 
Game::Game()
{
	initVars();
	initWindow();

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
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Grid test;

	this->window->clear();
	this->window->draw(test.getSprite());
	this->window->display();
}

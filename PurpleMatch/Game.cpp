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

bool Game::isRunning()
{
	return window->isOpen();
}

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

	this->window->clear();
	this->window->draw(shape);
	this->window->display();
}

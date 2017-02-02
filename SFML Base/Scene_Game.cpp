#include "Scene_Game.h"

Game::Game()
{
	init();
}

Game::~Game()
{
}

void Game::init()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Main Game");
	text.setPosition(screenSize.x / 2, screenSize.y / 2);
	text.setCharacterSize(18);
}

void Game::update()
{
	int i = 0;
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void Game::input(sf::Event Event)
{
	if (Event.type == sf::Event::KeyPressed)
	{ 
		std::cout << Event.key.code << std::endl; 
	}

	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		goToScene(myGlobalOptions->MAINMENU);
	}

	controller(Event);
}

void Game::goToScene(int scene)
{
	myGlobalOptions->setCurrentScene(scene);
}

void Game::controller(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}



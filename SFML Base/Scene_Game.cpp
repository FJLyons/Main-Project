#include "Scene_Game.h"

Game::Game()
{
	Init();
}

Game::~Game()
{
}

void Game::Init()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Main Game");
	text.setPosition(screenSize.x / 2, screenSize.y / 2);
	text.setCharacterSize(18);
}

void Game::Update()
{
	int i = 0;
}

void Game::Draw(sf::RenderWindow &window)
{
	map->Draw(window);
	castle->Draw(window);
	leftAgent->Draw(window);
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
		GV->setCurrentScene(GV->MAINMENU);
	}

	controller(Event);
}

void Game::controller(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}



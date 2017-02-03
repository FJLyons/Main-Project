#include "Scene_Load.h"



LoadScreen::LoadScreen()
{
	Init();
}


LoadScreen::~LoadScreen()
{
}

void LoadScreen::Init()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Load Game");
	text.setPosition(screenSize.x / 2, screenSize.y / 2);
	text.setCharacterSize(18);
}

void LoadScreen::Update()
{

}

void LoadScreen::Draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void LoadScreen::input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		GV->setCurrentScene(GV->MAINMENU);
	}
}
#include "Scene_Instructions.h"



InstructionsScreen::InstructionsScreen()
{
	Init();
}


InstructionsScreen::~InstructionsScreen()
{
}

void InstructionsScreen::Init()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Instructions");
	text.setPosition(screenSize.x / 2, screenSize.y / 2);
	text.setCharacterSize(18);
}

void InstructionsScreen::Update()
{

}

void InstructionsScreen::Draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void InstructionsScreen::input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		goToScene(GV->MAINMENU);
	}
}

void InstructionsScreen::goToScene(int scene)
{
	GV->setCurrentScene(scene);
}
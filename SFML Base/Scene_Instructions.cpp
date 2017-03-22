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
	text.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	text.setCharacterSize(18);

	_swapScene = GameScenes::INSTRUCTIONS;
}

int InstructionsScreen::Update()
{

	return (int)_swapScene;
}

void InstructionsScreen::Draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void InstructionsScreen::Input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		_swapScene = GameScenes::MAINMENU;
	}
}

bool InstructionsScreen::IsRunning()
{
	return _running;
}

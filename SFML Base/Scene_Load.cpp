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
	text.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	text.setCharacterSize(18);

	_swapScene = GameScenes::LOAD;
}

int LoadScreen::Update()
{

	return (int)_swapScene;
}

void LoadScreen::Draw(sf::RenderWindow &window)
{
	window.draw(text);
}

void LoadScreen::Input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		_swapScene = GameScenes::MAINMENU;
	}
}

bool LoadScreen::IsRunning()
{
	return _running;
}

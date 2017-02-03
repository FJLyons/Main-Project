#include "Manager_Scene.h"

SceneManager::SceneManager()
{
	Init();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	GV = GlobalVariables::getInstance();
	inputManager = new InputManager();

	splashScreen = new SplashScreen();
	mainMenu = new MainMenu();
	game = new Game();
	load = new LoadScreen();
	optionsMenu = new OptionsMenu();
	instructions = new InstructionsScreen();
}

void SceneManager::Update()
{
	if (GV->getCurrentScene() == GV->SPLASH){ splashScreen->Update(); }
	else if (GV->getCurrentScene() == GV->MAINMENU){ mainMenu->Update(); }
	else if (GV->getCurrentScene() == GV->GAME){ game->Update(); }
	else if (GV->getCurrentScene() == GV->LOAD) { load->Update(); }
	else if (GV->getCurrentScene() == GV->OPTIONS){ optionsMenu->Update(); }
	else if (GV->getCurrentScene() == GV->INSTRUCTIONS) { instructions->Update(); }
}

void SceneManager::Draw(sf::RenderWindow &window)
{
	if (GV->getCurrentScene() == GV->SPLASH){ splashScreen->Draw(window); }
	else if (GV->getCurrentScene() == GV->MAINMENU){ mainMenu->Draw(window); }
	else if (GV->getCurrentScene() == GV->GAME){ game->Draw(window); }
	else if (GV->getCurrentScene() == GV->LOAD) { load->Draw(window); }
	else if (GV->getCurrentScene() == GV->OPTIONS){ optionsMenu->Draw(window); }
	else if (GV->getCurrentScene() == GV->INSTRUCTIONS) { instructions->Draw(window); }
}
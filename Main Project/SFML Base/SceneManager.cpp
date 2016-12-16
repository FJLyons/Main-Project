#include "SceneManager.h"

SceneManager::SceneManager()
{
	init();
}

SceneManager::~SceneManager()
{
}

void SceneManager::init()
{
	myGlobalOptions = GlobalVariables::getInstance();
	inputManager = new InputManager();

	splashScreen = new SplashScreen();
	mainMenu = new MainMenu();
	game = new Game();
	load = new LoadScreen();
	optionsMenu = new OptionsMenu();
	instructions = new InstructionsScreen();
}

void SceneManager::update()
{
	if (myGlobalOptions->getCurrentScene() == myGlobalOptions->SPLASH){ splashScreen->update(); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->MAINMENU){ mainMenu->update(); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->GAME){ game->update(); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->LOAD) { load->update(); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->OPTIONS){ optionsMenu->update(); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->INSTRUCTIONS) { instructions->update(); }
}

void SceneManager::draw(sf::RenderWindow &window)
{
	if (myGlobalOptions->getCurrentScene() == myGlobalOptions->SPLASH){ splashScreen->draw(window); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->MAINMENU){ mainMenu->draw(window); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->GAME){ game->draw(window); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->LOAD) { load->draw(window); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->OPTIONS){ optionsMenu->draw(window); }
	else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->INSTRUCTIONS) { instructions->draw(window); }
}

void SceneManager::input(sf::RenderWindow &window, sf::Event &Event)
{
	swapScenes(window, Event);
}

void SceneManager::swapScenes(sf::RenderWindow &window, sf::Event &Event)
{
	//if (myGlobalOptions->getCurrentScene() == myGlobalOptions->SPLASH) // Splash
	//{
	//	if (Event.type == sf::Event::KeyPressed)
	//	{
	//		splashScreen->goToScene(myGlobalOptions->MAINMENU);
	//	}
	//}

	//else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->MAINMENU) // Main Menu
	//{
	//	// Main menu movement
	//	if (inputManager->KeyPressed(sf::Keyboard::Up)) { mainMenu->moveUp(); }
	//	else if (inputManager->KeyPressed(sf::Keyboard::Down)) { mainMenu->moveDown(); }

	//	// Enter New Screen
	//	if (inputManager->KeyPressed(sf::Keyboard::Return))
	//	{
	//		mainMenu->swapScreen(window, myGlobalOptions);
	//	}

	//	// Return to previous screen
	//	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	//	{
	//		mainMenu->backScreen(myGlobalOptions, myGlobalOptions->SPLASH);
	//		splashScreen->init();
	//	}
	//}

	//else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->GAME) // Game
	//{
	//	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	//	{
	//		optionsMenu->backScreen(myGlobalOptions, myGlobalOptions->MAINMENU);
	//	}
	//}

	//else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->LOAD) // Load
	//{
	//	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	//	{
	//		optionsMenu->backScreen(myGlobalOptions, myGlobalOptions->MAINMENU);
	//	}
	//}

	//else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->OPTIONS) // Options menu movement
	//{
	//	// Main menu movement
	//	if (inputManager->KeyPressed(sf::Keyboard::Up)) { optionsMenu->moveUp(); }
	//	else if (inputManager->KeyPressed(sf::Keyboard::Down)) { optionsMenu->moveDown(); }

	//	// Options Function
	//	if (inputManager->KeyPressed(sf::Keyboard::Return))
	//	{
	//		// Option functions
	//	}

	//	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	//	{
	//		optionsMenu->backScreen(myGlobalOptions, myGlobalOptions->MAINMENU);
	//	}
	//}

	//else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->INSTRUCTIONS) // Game
	//{
	//	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	//	{
	//		optionsMenu->backScreen(myGlobalOptions, myGlobalOptions->MAINMENU);
	//	}
	//}
}
#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// C++ Headers
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

// Custom Classes
#include "Variables_Global.h"
#include "Manager_Input.h"

#include "Scene_Splash.h"
#include "Scene_Main_Menu.h"
#include "Scene_Game.h"
#include "Scene_Load.h"
#include "Scene_Options.h"
#include "Scene_Instructions.h"


class SceneManager
{
private:
	GlobalVariables* myGlobalOptions = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();
public:
	SceneManager();
	~SceneManager();

	void init();
	void update();
	void draw(sf::RenderWindow &window);

	SplashScreen* splashScreen;
	MainMenu* mainMenu;
	Game* game;
	LoadScreen* load;
	OptionsMenu* optionsMenu;
	InstructionsScreen* instructions;

private:
	sf::Vector2f screenSize = myGlobalOptions->screenSize;
};


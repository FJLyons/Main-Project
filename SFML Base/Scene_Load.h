#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Global.h"
#include "Manager_Input.h"

class LoadScreen
{
private:
	GlobalVariables* myGlobalOptions = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	LoadScreen();
	~LoadScreen();

	void init();
	void update();
	void draw(sf::RenderWindow &window);
	void input(sf::Event Event);


private:
	sf::Vector2f screenSize = myGlobalOptions->screenSize;

	sf::Font font;
	sf::Text text;
};


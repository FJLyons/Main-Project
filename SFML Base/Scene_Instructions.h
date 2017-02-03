#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Global.h"
#include "Manager_Input.h"


class InstructionsScreen
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	InstructionsScreen();
	~InstructionsScreen(); 
	
	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);
	void input(sf::Event Event);

private:
	sf::Vector2f screenSize = GV->screenSize;

	void goToScene(int screen);

	sf::Font font;
	sf::Text text;
};


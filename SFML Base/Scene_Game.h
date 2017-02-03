#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h> 

#include "Variables_Global.h"
#include "Manager_Input.h"

#include "Map.h"
#include "Structure.h"
#include "Unit.h"

class Game
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	Game();
	~Game();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);
	void input(sf::Event Event);

private:
	Map* map = new Map();

	Structure* castle = new Structure();

	Unit* leftAgent = new Unit();
	Unit* RightAgent = new Unit();

private:
	sf::Vector2f screenSize = GV->screenSize;

	void controller(sf::Event Event);

	sf::Font font;
	sf::Text text;
};


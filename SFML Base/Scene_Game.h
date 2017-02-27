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

#include "GOAP_Action.h"
#include "GOAP_WorldState.h"
#include "GOAP_Planner.h"

class Game
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	Game();
	~Game();

	void InitGOAP();
	void InitMCTS();

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

private:
	GOAPWorldState* goap_goal_win;
	GOAPWorldState* goap_initial_state;

	GOAPPlanner* AStarSearch;

	//MCTSWorldState* mcts_goal_win;
	//MCTSWorldState* mcts_sinitial_state;

	//MCTSPlanner* MCTSSearch;
};


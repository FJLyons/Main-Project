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

#include "Scene.h"

#include "Map.h"
#include "Structure.h"
#include "Unit.h"

#include "GOAP_Action.h"
#include "GOAP_WorldState.h"
#include "GOAP_Planner.h"

#include "MCTS_Action.h"
#include "MCTS_WorldState.h"
#include "MCTS_Planner.h"

class Game : public Scene
{
private:
	GlobalVariables* GV = GlobalVariables::GetInstance();
	InputManager* inputManager = InputManager::GetInstance();

public:
	Game();
	~Game();

	void InitGOAP();
	void InitMCTS();

	void Init() override;
	int Update() override;
	void Draw(sf::RenderWindow &window) override;
	void Input(sf::Event Event) override;
	bool IsRunning() override;

private:
	Map* map = new Map();

	Structure* castle = new Structure();

	Unit* leftAgent = new Unit(0);
	Unit* rightAgent = new Unit(1);


	sf::Clock clock;

private:

	void controller(sf::Event Event);

	sf::Font font;
	sf::Text text;

private:
	GOAPWorldState* goap_goal_win;
	GOAPWorldState* goap_initial_state;

	GOAPPlanner* AStarSearch;

	void GOAP();

	std::vector<GOAPAction> GOAP_Plan;

	MCTSAction next_action;
	MCTSWorldState* mcts_initial_state;

	MCTSPlanner* UCTSearch;

	void MCTS();
};


#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <map>
#include <vector>
#include <queue>

#include "Variables_Global.h"

using namespace std;

#include "GOAP_Action.h"
#include "MCTS_Action.h"


class Unit
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();

public:
	Unit();
	~Unit();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

	std::vector<GOAPAction*>* actions;
	std::vector<MCTSAction*>* m_actions;
	MCTSAction* m_action;

private:
	float m_value_attack;
	float m_speed_attack;
	float m_range_attack;

	float m_value_defense;
	float m_speed_movement;
	float m_range_sight;

	float m_value_resource;
	float m_value_build;
	float m_value_sell;

private:
	sf::CircleShape m_circleShape;
	float m_radius;

private:
	void CreateGOAPActions();
	void CreateMCTSActions();

	// Actions
	GOAPAction* search;
	GOAPAction* sighted;
	GOAPAction* moveTo;
	GOAPAction* attack;
	GOAPAction* win;

	MCTSAction* m_search;
	MCTSAction* m_sighted;
	MCTSAction* m_moveTo;
	MCTSAction* m_attack;
	MCTSAction* m_win;
};


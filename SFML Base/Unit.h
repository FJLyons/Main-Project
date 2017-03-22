#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <map>
#include <vector>
#include <queue>

#include "Variables_Global.h"
#include "Manager_Collision.h"

using namespace std;

#include "GOAP_Action.h"
#include "MCTS_Action.h"


class Unit
{
public:
	Unit(int);
	~Unit();

	void Init();
	int Update(ActionState currentState, float dt);
	void Draw(sf::RenderWindow &window);

	std::vector<GOAPAction*>* actions;
	std::vector<MCTSAction*>* m_actions;
	MCTSAction* m_action;

private:
	float m_value_attack;
	float m_speed_attack = 2.5f;
	float m_range_attack = 2;

	float m_value_defense;
	float m_speed_movement = 2;
	float m_range_sight = 10;

	float m_value_resource;
	float m_value_build;
	float m_value_sell;

	float m_attack_timer = 0;

public:
	sf::Vector2f m_position;
	float m_radius;

	sf::CircleShape m_circleShape;
	sf::CircleShape POV;
	sf::CircleShape RANGE;

private:
	int m_type;
	int m_working;
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

private:
	int SearchForCastle();
	int MoveToCastle();
	int CheckCastle();
	int AttackCastle(float dt);
	int Win();
};


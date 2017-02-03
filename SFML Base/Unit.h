#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <map>
#include <vector>
#include <queue>

using namespace std;

#include "Action.h"

class Unit
{
public:
	Unit();
	~Unit();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

	bool Move(Action* act);

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

public:
	map<string, bool> GetWorldState(); // HashSet<KeyValuePair<string , object>> 
	map<string, bool> CreateGoalState(); 

	map<string, bool> PlanFailed(map<string, bool> failedPlan);
	map<string, bool> PlanFound(map<string, bool> goal, priority_queue<Action*>* actions);
	void PlanAborted(Action* act);

	void ActionFinished();
};


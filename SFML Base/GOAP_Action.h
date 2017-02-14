#pragma once

#include <string>
#include <unordered_map>

#include "Variables_Global.h"

struct WorldState;

class Action
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();

public:
	Action();
	Action(int name, int cost);
	~Action();

private:
	int m_name;
	int m_cost;

	std::unordered_map<int, bool> m_preconditions;
	std::unordered_map<int, bool> m_effects;

public:
	int GetName();
	int GetCost() const;

	void SetPreconditions(int key, bool value);
	void SetEffects(int key, bool value);

	bool OperableOn(const WorldState& worldState) const;
	WorldState ActOn(const WorldState& worldState) const;
};

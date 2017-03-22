#pragma once

#include <string>
#include <unordered_map>

#include "Variables_Global.h"

class GOAPWorldState;

class GOAPAction
{
public:
	GOAPAction();
	GOAPAction(ActionState name, int cost);
	~GOAPAction();

private:
	ActionState m_name;
	int m_cost;

	std::unordered_map<ActionState, bool> m_preconditions;
	std::unordered_map<ActionState, bool> m_effects;

public:
	std::string GetName();
	int GetCost() const;

	void SetPreconditions(ActionState key, bool value);
	void SetEffects(ActionState key, bool value);

	ActionState GetAction();

	bool OperableOn(const GOAPWorldState& worldState) const;
	GOAPWorldState ActOn(const GOAPWorldState& worldState) const;
};

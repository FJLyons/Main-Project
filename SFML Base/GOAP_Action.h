#pragma once

#include <string>
#include <unordered_map>

#include "Variables_Global.h"

class GOAPWorldState;

class GOAPAction
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();

public:
	GOAPAction();
	GOAPAction(GlobalVariables::GOAPState name, int cost);
	~GOAPAction();

private:
	GlobalVariables::GOAPState m_name;
	int m_cost;

	std::unordered_map<GlobalVariables::GOAPState, bool> m_preconditions;
	std::unordered_map<GlobalVariables::GOAPState, bool> m_effects;

public:
	std::string GetName();
	int GetCost() const;

	void SetPreconditions(GlobalVariables::GOAPState key, bool value);
	void SetEffects(GlobalVariables::GOAPState key, bool value);

	bool OperableOn(const GOAPWorldState& worldState) const;
	GOAPWorldState ActOn(const GOAPWorldState& worldState) const;
};

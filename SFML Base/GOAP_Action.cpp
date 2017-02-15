#include "GOAP_Action.h"
#include "GOAP_WorldState.h"

Action::Action() 
	: m_cost(0) 
{
}

Action::Action(GlobalVariables::GOAPState name, int cost)
	: m_name(name)
	, m_cost(cost)
{
}

Action::~Action()
{
}

std::string Action::GetName()
{
	return GV->stateNames[m_name];
}

int Action::GetCost() const
{
	return m_cost;
}

void Action::SetPreconditions(GlobalVariables::GOAPState key, bool value)
{
	m_preconditions[key] = value;
}

void Action::SetEffects(GlobalVariables::GOAPState key, bool value)
{
	m_effects[key] = value;
}

bool Action::OperableOn(const WorldState& worldState) const
{
	for (const auto& precondition : m_preconditions)
	{
		try
		{
			if (worldState.m_variables.at(precondition.first) != precondition.second)
			{
				return false;
			}
		}
		catch (const std::out_of_range&)
		{
			return false;
		}
	}

	return true;
}

WorldState Action::ActOn(const WorldState& worldState) const
{
	WorldState temp = worldState;

	for (const auto& effect : m_effects)
	{
		temp.SetVariable(effect.first, effect.second);
	}

	return temp;
}
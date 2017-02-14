#include "GOAP_Action.h"
#include "GOAP_WorldState.h"

Action::Action() 
	: m_cost(0) 
{
}

Action::Action(int name, int cost)
	: m_name(name)
	, m_cost(cost)
{
}

Action::~Action()
{
}

int Action::GetName()
{
	return m_name;
}

int Action::GetCost() const
{
	return m_cost;
}

void Action::SetPreconditions(int key, bool value)
{
	m_preconditions[key] = value;
}

void Action::SetEffects(int key, bool value)
{
	m_effects[key] = value;
}

bool Action::OperableOn(const WorldState& ws) const
{
	for (const auto& precondition : m_preconditions)
	{
		try
		{
			if (ws.m_variables.at(precondition.first) != precondition.second)
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
#include "GOAP_Action.h"
#include "GOAP_WorldState.h"

GOAPAction::GOAPAction()
	: m_cost(0) 
{
}

GOAPAction::GOAPAction(ActionState name, int cost)
	: m_name(name)
	, m_cost(cost)
{
}

GOAPAction::~GOAPAction()
{
}

std::string GOAPAction::GetName()
{
	return GlobalVariables::GetInstance()->stateNames[m_name];
}

int GOAPAction::GetCost() const
{
	return m_cost;
}

void GOAPAction::SetPreconditions(ActionState key, bool value)
{
	m_preconditions[key] = value;
}

void GOAPAction::SetEffects(ActionState key, bool value)
{
	m_effects[key] = value;
}

ActionState GOAPAction::GetAction()
{
	return m_name;
}

bool GOAPAction::OperableOn(const GOAPWorldState& worldState) const
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

GOAPWorldState GOAPAction::ActOn(const GOAPWorldState& worldState) const
{
	GOAPWorldState temp = worldState;

	for (const auto& effect : m_effects)
	{
		temp.SetVariable(effect.first, effect.second);
	}

	return temp;
}
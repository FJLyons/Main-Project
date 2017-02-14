#include "GOAP_WorldState.h"

WorldState::WorldState(const std::string name)
	: m_priority(0)
	, m_name(name)
{
}

WorldState::~WorldState()
{
}

void WorldState::SetVariable(const int var_id, const bool value)
{
	m_variables[var_id] = value;
}

bool WorldState::GetVariable(const int var_id) const
{
	return m_variables.at(var_id);
}

bool WorldState::MeetsGoal(const WorldState& goal_state) const
{
	for (const auto& variable : goal_state.m_variables)
	{
		try
		{
			if (m_variables.at(variable.first) != variable.second)
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

int WorldState::DistanceTo(const WorldState& goal_state) const
{
	int result = 0;

	for (const auto& variable : goal_state.m_variables)
	{
		auto itr = m_variables.find(variable.first);

		if (itr == end(m_variables) || itr->second != variable.second)
		{
			++result;
		}
	}

	return result;
}

bool WorldState::operator==(const WorldState& otherWorld) const
{
	return (m_variables == otherWorld.m_variables);
}

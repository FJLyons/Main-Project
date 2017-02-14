#pragma once

#include <ostream>
#include <string>
#include <map>

class WorldState
{
public:
	WorldState(const std::string name = "");
	~WorldState();

	float m_priority; 
	std::string m_name; 
	std::map<int, bool> m_variables; // the variables that in aggregate describe a worldstate

	void SetVariable(const int var_id, const bool value);
	bool GetVariable(const int var_id) const;

	bool MeetsGoal(const WorldState& goal_state) const;

	int DistanceTo(const WorldState& goal_state) const;

	bool operator==(const WorldState& otherWorld) const;


	// ?
	friend std::ostream& operator<<(std::ostream& out, const WorldState& node);
};

inline std::ostream& operator<<(std::ostream& outStream, const WorldState& worldState) 
{
	outStream << "WorldState { ";
	for (const auto& variable : worldState.m_variables)
	{
		outStream << variable.second << " ";
	}
	outStream << "}";

	return outStream;
}


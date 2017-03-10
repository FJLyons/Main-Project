#pragma once

#include <ostream>
#include <string>
#include <map>

class GOAPWorldState
{
public:
	GOAPWorldState(const std::string name = "");
	~GOAPWorldState();

	float m_priority; 
	std::string m_name; 
	std::map<int, bool> m_variables; // the variables that in aggregate describe a worldstate

	void SetVariable(const int var_id, const bool value);
	bool GetVariable(const int var_id) const;

	bool MeetsGoal(const GOAPWorldState& goal_state) const;

	int DistanceTo(const GOAPWorldState& goal_state) const;

	bool operator==(const GOAPWorldState& otherWorld) const;


	// ?
	//friend std::ostream& operator<<(std::ostream& out, const GOAPWorldState& node);
};

//inline std::ostream& operator<<(std::ostream& outStream, const GOAPWorldState& worldState)
//{
//	outStream << "WorldState { ";
//	for (const auto& variable : worldState.m_variables)
//	{
//		outStream << variable.second << " ";
//	}
//	outStream << "}";
//
//	return outStream;
//}


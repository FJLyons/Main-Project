#pragma once

#include "GOAP_Action.h"
#include "GOAP_Node.h"
#include "GOAP_WorldState.h"

#include <ostream>
#include <unordered_map>
#include <vector>

class Planner
{
public:
	Planner();
	~Planner();

	std::vector<Node>::iterator MemberOfOpen(const WorldState& worldState);

private:
	std::vector<Node> m_open;   
	std::vector<Node> m_closed; 

	int CalculateHeuristic(const WorldState& now, const WorldState& goal) const;

	void AddToOpenList(Node&&);

	Node& PopAndClose();

	bool MemberOfClosed(const WorldState& ws) const;

public:
	void PrintOpenList() const;
	void PrintClosedList() const;

	std::vector<Action> Plan(const WorldState& start, const WorldState& goal, const std::vector<Action>& actions);
};


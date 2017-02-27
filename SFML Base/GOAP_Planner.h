#pragma once

#include "GOAP_Action.h"
#include "GOAP_Node.h"
#include "GOAP_WorldState.h"

#include <ostream>
#include <unordered_map>
#include <vector>

class GOAPPlanner
{
public:
	GOAPPlanner();
	~GOAPPlanner();

	std::vector<GOAPNode>::iterator MemberOfOpen(const GOAPWorldState& worldState);

private:
	std::vector<GOAPNode> m_open;
	std::vector<GOAPNode> m_closed;

	int CalculateHeuristic(const GOAPWorldState& now, const GOAPWorldState& goal) const;

	void AddToOpenList(GOAPNode&&);

	GOAPNode& PopAndClose();

	bool MemberOfClosed(const GOAPWorldState& ws) const;

public:
	void PrintOpenList() const;
	void PrintClosedList() const;

	std::vector<GOAPAction> Plan(const GOAPWorldState& start, const GOAPWorldState& goal, const std::vector<GOAPAction*>& actions);
};


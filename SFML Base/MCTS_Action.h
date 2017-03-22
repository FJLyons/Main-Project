#pragma once

#include "Variables_Global.h"

class MCTSAction
{
public:
	MCTSAction();
	MCTSAction(ActionState name);
	~MCTSAction();

	ActionState action;

	std::string GetName();

	void AddChild(ActionState child, bool isTerminal);

	std::vector<ActionState> m_children;
	std::vector<bool> m_winner;

	MCTSAction& operator = (const MCTSAction& other);

	void SetUpAction();

	// MCTS Actions should be all unit actions

	// MCTS can search all AVAILABLE actions at once

	// Each action can lead to AVAILABLE actions again

	// Highest value is calculated by MCTS

	// Need to set up all actions before hand
};


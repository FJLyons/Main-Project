#pragma once

#include <vector>
#include <string>

#include "MCTS_Action.h"

class MCTSWorldState
{
public:
	MCTSWorldState();
	MCTSWorldState(MCTSAction action);
	~MCTSWorldState();

	// copy and assignment operators should perform a DEEP clone of the given state
	MCTSWorldState(const MCTSWorldState& other);
	MCTSWorldState& operator = (const MCTSWorldState& other);

	// whether or not this state is terminal (reached end)
	bool IsTerminal() const;

	// apply action to state
	void ApplyAction(const MCTSAction& action);

	// return possible actions from this state
	void GetActions(std::vector<MCTSAction>& actions) const;

	// get a random action, return false if no actions found
	bool GetRandomAction(MCTSAction& action) const;

	// evaluate this state and return a vector of rewards (for each agent)
	const float Evaluate(MCTSAction action);

private:
	bool m_isTerminal;
	int m_winner;
	std::vector<GlobalVariables::ActionState> m_moves;

	MCTSAction m_previousAction;

	void reset();
};

